/*
XbeeIO
The purpose of XbeeIO is to act as a ROS bridge between the XBee communication system and the ROS network.
We will need to port XBee code into here somewhere in order to communicate over the XBee network.
*/

// Standard includes
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <string.h>
#include <inttypes.h>
#include <fstream>
// Serial includes
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#ifdef __linux
#include <sys/ioctl.h>
#endif

#include <glib.h>

// Latency Benchmarking
#include <sys/time.h>
#include <time.h>

//Standard C++ headers
#include <sstream>

//ROS headers
#include "ros/ros.h"
#include "AU_UAV_ROS/TelemetryUpdate.h"
#include "AU_UAV_ROS/Command.h"
#include "AU_UAV_ROS/StartXbeeIO.h"
#include "mavlink/v1.0/ardupilotmega/mavlink.h"

using std::string;
using namespace std;

struct timeval tv;		      ///< System time

int baud = 57600;                     ///< The serial baud rate
// Settings
int sysid = -1;                       ///< The unique system id of this MAV, 0-127. Has to be consistent across the system
int compid = 110;
int serial_compid = 0;
std::string port = "/dev/ttyUSB0";    ///< The serial port name, e.g. /dev/ttyUSB0
bool silent = false;                  ///< Wether console output should be enabled
bool verbose = false;                  ///< Enable verbose output
bool debug = false;                   ///< Enable debug functions and output
bool pc2serial = true;		      ///< Enable PC to serial push mode (send more stuff from pc over serial)
int fd;				      ///< file descriptor of port

int updateIndex = 0;		      ///<To keep number of AU_UAV MAVLink messages
int WPSendSeqNum = 0;		      ///<Int to keep up with number of wp's sent to UAV
int myMessages[256];		      ///< Array to keep up with which messages are sent 

bool readyToStart = false;

/**
 * Grabs all mavlink-messages from the ROS-Topic "" and publishes them on the LCM-Mavlink-Channel
 */

ros::Subscriber c_sub;			//Ros subscriber to get waypoint command info
ros::Publisher t_pub;			//Ros publisher to publish GPS information

/**
 *
 *
 * Returns the file descriptor on success or -1 on error.
 */

int open_port(std::string& port)
{
	int fd; /* File descriptor for the port */
	
	// Open serial port
	// O_RDWR - Read and write
	// O_NOCTTY - Ignore special chars like CTRL-C
	fd = open(port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
	if (fd == -1)
	{
		/* Could not open the port. */
		return(-1);
	}
	else
	{
		fcntl(fd, F_SETFL, 0);
	}
	
	return (fd);
}

bool setup_port(int fd, int baud, int data_bits, int stop_bits, bool parity, bool hardware_control)
{
	//struct termios options;
	
	struct termios  config;
	if(!isatty(fd))
	{
		fprintf(stderr, "\nERROR: file descriptor %s is NOT a serial port\n", port.c_str());
		return false;
	}
	if(tcgetattr(fd, &config) < 0)
	{
		fprintf(stderr, "\nERROR: could not read configuration of port %s\n", port.c_str());
		return false;
	}
	//
	// Input flags - Turn off input processing
	// convert break to null byte, no CR to NL translation,
	// no NL to CR translation, don't mark parity errors or breaks
	// no input parity check, don't strip high bit off,
	// no XON/XOFF software flow control
	//
	config.c_iflag &= ~(IGNBRK | BRKINT | ICRNL |
	                    INLCR | PARMRK | INPCK | ISTRIP | IXON);
	//
	// Output flags - Turn off output processing
	// no CR to NL translation, no NL to CR-NL translation,
	// no NL to CR translation, no column 0 CR suppression,
	// no Ctrl-D suppression, no fill characters, no case mapping,
	// no local output processing
	//
	// config.c_oflag &= ~(OCRNL | ONLCR | ONLRET |
	//                     ONOCR | ONOEOT| OFILL | OLCUC | OPOST);
	config.c_oflag = 0;
	//
	// No line processing:
	// echo off, echo newline off, canonical mode off,
	// extended input processing off, signal chars off
	//
	config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);
	//
	// Turn off character processing
	// clear current char size mask, no parity checking,
	// no output processing, force 8 bit input
	//
	config.c_cflag &= ~(CSIZE | PARENB);
	config.c_cflag |= CS8;
	//
	// One input byte is enough to return from read()
	// Inter-character timer off
	//
	config.c_cc[VMIN]  = 1;
	config.c_cc[VTIME] = 10; // was 0
	
	// Get the current options for the port
	//tcgetattr(fd, &options);
	
	switch (baud)
	{
		case 1200:
			if (cfsetispeed(&config, B1200) < 0 || cfsetospeed(&config, B1200) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baud);
				return false;
			}
			break;
		case 1800:
			cfsetispeed(&config, B1800);
			cfsetospeed(&config, B1800);
			break;
		case 9600:
			cfsetispeed(&config, B9600);
			cfsetospeed(&config, B9600);
			break;
		case 19200:
			cfsetispeed(&config, B19200);
			cfsetospeed(&config, B19200);
			break;
		case 38400:
			if (cfsetispeed(&config, B38400) < 0 || cfsetospeed(&config, B38400) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baud);
				return false;
			}
			break;
		case 57600:
			if (cfsetispeed(&config, B57600) < 0 || cfsetospeed(&config, B57600) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baud);
				return false;
			}
			break;
		case 115200:
			if (cfsetispeed(&config, B115200) < 0 || cfsetospeed(&config, B115200) < 0)
			{
				fprintf(stderr, "\nERROR: Could not set desired baud rate of %d Baud\n", baud);
				return false;
			}
			break;
		default:
			fprintf(stderr, "ERROR: Desired baud rate %d could not be set, falling back to 115200 8N1 default rate.\n", baud);
			cfsetispeed(&config, B115200);
			cfsetospeed(&config, B115200);
			
			break;
	}
	
	//
	// Finally, apply the configuration
	//
	if(tcsetattr(fd, TCSAFLUSH, &config) < 0)
	{
		fprintf(stderr, "\nERROR: could not set configuration of port %s\n", port.c_str());
		return false;
	}
	return true;
}

bool close_port(int fd)
{
	if (verbose) {
		printf("\n");
		printf("\n");
		printf("Printing myMessages array: \n");
		int i;
		for(i = 0; i < 256; i++)
			if (myMessages[i] > 0) 
				printf("#%d: %d\n", i, myMessages[i]);
	}
	close(fd);
	return true;
}


/**
*	Helper method to transfer data from a Mavlink telemetry message to a ROS message
*/

bool convertMavlinkTelemetryToROS(mavlink_au_uav_t *mavMessage, AU_UAV_ROS::TelemetryUpdate *tUpdate) {
	//tUpdate->planeID = mavlink_ros->planeID;
	
	tUpdate->currentLatitude = (mavMessage->au_lat) / 10000000.0;	  /// Lattitude * 10**7 so have to divide by 10^7
	tUpdate->currentLongitude = (mavMessage->au_lng) / 10000000.0;	  /// Longitude * 10**7 so have to divide by 10^7
	tUpdate->currentAltitude = (mavMessage->au_alt) / 100.0; 	  /// Altitude in cm so divide by 100 to get meters	
	
	tUpdate->destLatitude = (mavMessage->au_target_lat) / 10000000.0;  /// Lattitude * 10**7 so have to divide by 10^7
	tUpdate->destLongitude = (mavMessage->au_target_lng) / 10000000.0; /// Longitude * 10**7 so have to divide by 10^7
	tUpdate->destAltitude = (mavMessage->au_target_alt) / 100.0; 	  /// Altitude in cm so divide by 100 to get meters

	tUpdate->groundSpeed = (mavMessage->au_ground_speed) / 100.0; /// Originally in cm / sec so have to convert to mph

	tUpdate->distanceToDestination = mavMessage->au_distance; 	  /// Distance between plane and next waypoint in meters.

	tUpdate->targetBearing = mavMessage->au_target_bearing / 100;	  /// This is the direction to the next waypoint or loiter center in degrees

	tUpdate->currentWaypointIndex = mavMessage->au_target_wp_index;   /// The current waypoint index

	tUpdate->telemetryHeader.seq = ++updateIndex;
	tUpdate->telemetryHeader.stamp = ros::Time::now();
return true;
}

/**
 * @brief Serial function
 *
 * This function blocks waiting for serial data in it's own thread
 * and forwards the data once received.
 * Basically it takes the mavlink messages from the serial port and handles (forwards) them.
 */ 
void* serial_wait(void* serial_ptr)
{
	int fd = *((int*) serial_ptr);	

	mavlink_status_t lastStatus;
	lastStatus.packet_rx_drop_count = 0;
	
	// Blocking wait for new data
	while (1)
	{
		//if (debug) printf("Checking for new data on serial port\n");
		// Block until data is available, read only one byte to be able to continue immediately
		//char buf[MAVLINK_MAX_PACKET_LEN];
		uint8_t cp;
		mavlink_message_t message;
		mavlink_status_t status;
		uint8_t msgReceived = false;
		//tcflush(fd, TCIFLUSH);
		if (read(fd, &cp, 1) > 0)
		{
			// Check if a message could be decoded, return the message in case yes
			msgReceived = mavlink_parse_char(MAVLINK_COMM_1, cp, &message, &status);
			if (lastStatus.packet_rx_drop_count != status.packet_rx_drop_count)
			{
				if (verbose || debug) printf("ERROR: DROPPED %d PACKETS\n", status.packet_rx_drop_count);
				if (debug)
				{
					unsigned char v=cp;
					fprintf(stderr,"%02x ", v);
				}
			}
			lastStatus = status;
		}
		else
		{
			if (!silent) fprintf(stderr, "ERROR: Could not read from port %s\n", port.c_str());
		}
		
		// If a message could be decoded, handle it
		if(msgReceived)
		{
			if (verbose || debug) std::cout << std::dec << "Received and forwarded serial port message with id " << static_cast<unsigned int>(message.msgid) << " from system " << static_cast<int>(message.sysid) << std::endl;
			if (debug) ROS_ERROR("Message sequence #: %d", message.seq);
			// DEBUG output
			if (debug)
			{
				fprintf(stderr,"Forwarding SERIAL -> ROS: ");
				unsigned int i;
				uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
				unsigned int messageLength = mavlink_msg_to_send_buffer(buffer, &message);
				if (messageLength > MAVLINK_MAX_PACKET_LEN)
				{
					fprintf(stderr, "\nFATAL ERROR: MESSAGE LENGTH IS LARGER THAN BUFFER SIZE\n");
				}
				else
				{
					for (i=0; i<messageLength; i++)
					{
						unsigned char v=buffer[i];
						fprintf(stderr,"%02x ", v);
					}
					fprintf(stderr,"\n");
				}
			}
			
			if (verbose || debug)
				ROS_INFO("Received message from serial with ID #%d (sys:%d|comp:%d):\n", message.msgid, message.sysid, message.compid);
			

			//TODO: Need better way to keep track of multiple UAVs, this should work fine for one UAV.
			//	Maybe keep an array of current 'real' UAVs			
			sysid = message.sysid;
			serial_compid = message.compid;

			/**
			 * Serialize the Mavlink-ROS-message
			 */
/**
			mavlink_ros::Mavlink rosmavlink_msg;

			rosmavlink_msg.len = message.len;
			rosmavlink_msg.seq = message.seq;
			rosmavlink_msg.sysid = message.sysid;
			rosmavlink_msg.compid = message.compid;
			rosmavlink_msg.msgid = message.msgid;
			rosmavlink_msg.fromlcm = false;
*/
			if (verbose) 
				myMessages[message.msgid]++;
/**

			for (int i = 0; i < message.len/8; i++)
			{
				(rosmavlink_msg.payload64).push_back(message.payload64[i]);
			}
*/			
			/**
			 * Mark the ROS-Message as coming not from LCM
			 */
			//rosmavlink_msg.fromlcm = true;
			
			/**
			 * Send the received MAVLink message to ROS (topic: mavlink, see main())
			 */
			//mavlink_pub.publish(rosmavlink_msg);



			if(message.msgid == MAVLINK_MSG_ID_HEARTBEAT)
			{
				//ROS_INFO("Delay: %d", delay);
				//mavlink_heartbeat_t receivedHeartbeat;
				//mavlink_msg_heartbeat_decode(&message, &receivedHeartbeat);
				//ROS_INFO("Received heartbeat with ID #%d (type:%d | AP:%d | base:%d | custom:%d | status:%d)\n", message.msgid, receivedHeartbeat.type, receivedHeartbeat.autopilot, receivedHeartbeat.base_mode, receivedHeartbeat.custom_mode, receivedHeartbeat.system_status);
			}
			if(message.msgid == MAVLINK_MSG_ID_AU_UAV)
			{
				//ROS_INFO("Received AU_UAV message from serial with ID #%d (sys:%d|comp:%d):\n", message.msgid, message.sysid, message.compid);
				
				AU_UAV_ROS::TelemetryUpdate tUpdate;
				mavlink_au_uav_t myMSG;
				mavlink_msg_au_uav_decode(&message, &myMSG);		// decode generic mavlink message into AU_UAV message
				convertMavlinkTelemetryToROS(&myMSG, &tUpdate);			// decode AU_UAV mavlink struct into ROS message
				tUpdate.planeID = message.sysid;				// update planeID
				ROS_INFO("Received telemetry message from UAV[#%d] (lat:%f|lng:%f|alt:%f)", tUpdate.planeID, tUpdate.currentLatitude, tUpdate.currentLongitude, tUpdate.currentAltitude);
				t_pub.publish(tUpdate);						// publish ROS telemetry message to ROS topic /telemetry
			}
			//TODO: add code here to test if received ack corresponsed to desired target_wp, if not retransmit target_wp
			/*
			if (message.msgid == MAVLINK_MSG_ID_MISSION_ACK) 
			{
				mavlink_mission_ack_t mission_ack;
				mavlink_msg_mission_ack_decode(&message, &mission_ack);
				ROS_INFO("RECEIVED message from serial with ID #%d (sys:%d|comp:%d|type:%d):\n", message.msgid, message.sysid, message.compid, mission_ack.type);
			}
			*/
		}
	}
	return NULL;
} // end serial_wait


/**
*	mavlinkCallback is run constantly with ros::spin().
*	This method is used to encode a mavlink ros msg into an actual mavlink msg.
*	This information is send serially via XBEE
*
*/

//TODO: add check for lost packet (with acks) and retransmit if lost
//Design Decision:  Real UAVs have planeIDs > 31
void mavlinkCallback(const AU_UAV_ROS::Command cmd)
{
	sysid = cmd.planeID;
	if (sysid >= 32 && sysid <= 64) {
		WPSendSeqNum++;
	 
		mavlink_message_t mavlinkMsg;
		// Refer to message_definitions for parameter explination

		mavlink_msg_mission_item_pack(sysid, compid, &mavlinkMsg,
	       		sysid, serial_compid, WPSendSeqNum, MAV_FRAME_GLOBAL, MAV_CMD_NAV_WAYPOINT, 2, 0, 20.0, 100.0, 1.0, 0.0, cmd.latitude, cmd.longitude, cmd.altitude);
		
		// Send message over serial port
		static uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
		int messageLength = mavlink_msg_to_send_buffer(buffer, &mavlinkMsg);
		if (debug) printf("Writing %d bytes\n", messageLength);
		int written = write(fd, (char*)buffer, messageLength);
		tcflush(fd, TCOFLUSH);
		if (messageLength != written) fprintf(stderr, "ERROR: Wrote %d bytes but should have written %d\n", written, messageLength);

	}
	else {
	// command is for simulated UAV
	}
}


//TODO: move connect to serial to here to add robustness
bool startXbeeIO(AU_UAV_ROS::StartXbeeIO::Request &req, AU_UAV_ROS::StartXbeeIO::Response &res)
{
    //ROS_INFO(req.indicator);
    readyToStart = true;
    
    // we shouldn't ever have an error, so populate it with "passed"
    res.error = "passed";
    return true;
}


int main(int argc, char **argv) {
	ros::init(argc, argv, "XbeeIO");
	ros::NodeHandle n;

        //init service to start this node        
	ros::ServiceServer startXbeeIOServer = n.advertiseService("start_xbeeio", startXbeeIO);

	ros::Rate r(10); // 10 hz
        while (!readyToStart)
        {
        ros::spinOnce();
        r.sleep();
        }


	if (verbose) {
		int j; 
		for (j = 0; j < 256; j++) 
			myMessages[j] = 0;
	}
	// Handling Program options
	static GOptionEntry entries[] =
	{
			{ "portname", 'p', 0, G_OPTION_ARG_STRING, &port, "Serial port name", port.c_str() },
			{ "baudrate", 'b', 0, G_OPTION_ARG_INT, &baud, "Baudrate", "115200" },
			{ "verbose", 'v', 0, G_OPTION_ARG_NONE, &verbose, "Be verbose", NULL },
			{ "debug", 'd', 0, G_OPTION_ARG_NONE, &debug, "Debug output", NULL },
			{ "sysid", 'a', 0, G_OPTION_ARG_INT, &sysid, "ID of this system, 1-255", "42" },
			{ "compid", 'c', 0, G_OPTION_ARG_INT, &compid, "ID of this component, 1-255", "199" },
			{ NULL, 0, 0, G_OPTION_ARG_NONE, NULL, NULL, 0 }
	};

	GError *error = NULL;
	GOptionContext *context;

	context = g_option_context_new ("- translate MAVLink messages between ROS to serial port");
	g_option_context_add_main_entries (context, entries, NULL);
	//g_option_context_add_group (context, NULL);
	if (!g_option_context_parse (context, &argc, &argv, &error))
	{
		g_print ("Option parsing failed: %s\n", error->message);
		exit (1);
	}

	// SETUP SERIAL PORT

	// Exit if opening port failed
	// Open the serial port.
	if (!silent) printf("Trying to connect to %s.. ", port.c_str());
	fd = open_port(port);
	if (fd == -1)
	{
		if (!silent) fprintf(stderr, "failure, could not open port.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (!silent) printf("success.\n");
	}
	if (!silent) printf("Trying to configure %s.. ", port.c_str());
	bool setup = setup_port(fd, baud, 8, 1, false, false);
	if (!setup)
	{
		if (!silent) fprintf(stderr, "failure, could not configure port.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (!silent) printf("success.\n");
	}
	int* fd_ptr = &fd;


	// SETUP ROS
	
	c_sub = n.subscribe("commands", 1000, mavlinkCallback);
	t_pub =  n.advertise<AU_UAV_ROS::TelemetryUpdate>("telemetry", 1000);

	GThread* serial_thread;
	GError* err;
	if( !g_thread_supported() )
	{
		g_thread_init(NULL);
		// Only initialize g thread if not already done
	}

	// Run indefinitely while the ROS and serial threads handle the data
	if (!silent) printf("\nREADY, waiting for serial/ROS data.\n");

	if( (serial_thread = g_thread_create((GThreadFunc)serial_wait, (void *)fd_ptr, TRUE, &err)) == NULL)
	{
		printf("Failed to create serial handling thread: %s!!\n", err->message );
		g_error_free ( err ) ;
	}

	int noErrors = 0;
	if (fd == -1 || fd == 0)
	{
		if (!silent) fprintf(stderr, "Connection attempt to port %s with %d baud, 8N1 failed, exiting.\n", port.c_str(), baud);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (!silent) fprintf(stderr, "\nConnected to %s with %d baud, 8 data bits, no parity, 1 stop bit (8N1)\n", port.c_str(), baud);
	}
	
	// FIXME ADD MORE CONNECTION ATTEMPTS
	
	if(fd == -1 || fd == 0)
	{
		exit(noErrors);
	}
	
	// Ready to roll
	printf("\nMAVLINK SERIAL TO ROS BRIDGE STARTED ON MAV %d (COMPONENT ID:%d) - RUNNING..\n\n", sysid, compid);
	

	// DEBUG - for testing XBEE serial comm in X-CTU
	/**	
	if(debug) {
	static uint8_t buf[10];
	int messageLength = 10;
	if (debug) printf("Writing %d bytes\n", messageLength);
	for (int i=0;i<10;i++)
		buf[i] = 'A';
	int test = write(fd, (char*)buf, messageLength);
	tcflush(fd, TCOFLUSH);
	if (messageLength != test) fprintf(stderr, "ERROR: Wrote %d bytes but should have written %d\n", test, messageLength);
	}
	*/

	/**
	 * Now pump callbacks (execute mavlinkCallback) until CTRL-c is pressed
	 */
	ros::spin();

	close_port(fd);

	return 0;
}
