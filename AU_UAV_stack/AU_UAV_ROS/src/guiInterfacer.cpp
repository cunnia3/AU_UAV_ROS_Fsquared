//standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctype.h>

//ROS headers
#include "ros/ros.h"
#include "ros/package.h"
#include "AU_UAV_ROS/standardDefs.h"
#include "AU_UAV_ROS/CreateSimulatedPlane.h"
#include "AU_UAV_ROS/DeleteSimulatedPlane.h"
#include "AU_UAV_ROS/RequestPlaneID.h"
#include "AU_UAV_ROS/GoToWaypoint.h"
#include "AU_UAV_ROS/LoadPath.h"
#include "AU_UAV_ROS/LoadCourse.h"
#include "AU_UAV_ROS/SaveFlightData.h"
//New JC
#include "AU_UAV_ROS/SendFilePath.h"
//includes for ROS init services
#include "AU_UAV_ROS/StartCoordinator.h"
#include "AU_UAV_ROS/StartCollisionAvoidance.h"
#include "AU_UAV_ROS/StartSimulator.h"
#include "AU_UAV_ROS/StartXbeeIO.h"

//services to the simulator
ros::ServiceClient createSimulatedPlaneClient;
ros::ServiceClient deleteSimulatedPlaneClient;

//services to the coordinator
ros::ServiceClient goToWaypointClient;
ros::ServiceClient loadPathClient;
ros::ServiceClient loadCourseClient;
ros::ServiceClient requestPlaneIDClient;
ros::ServiceClient initiateCoordinator;
ros::ServiceClient initiateCollisionAvoidance;
ros::ServiceClient initiateSimulator;
ros::ServiceClient initiateXbeeIO;


//Horrible programming - jc
//TODO: avoid somehow
bool fileNameLoaded = false;
std::string selectedFileName;

/*
createCourseUAVs(...)
takes a filename and will parse it to determine how many UAVs there are and create them as needed
*/
bool createCourseUAVs(std::string filename)
{
    //open our file
    FILE *fp;
    fp = fopen(filename.c_str(), "r");

    //check for a good file open
    if(fp != NULL)
    {
        char buffer[256];

        std::map<int, bool> isFirstPoint;

        while(fgets(buffer, sizeof(buffer), fp))
        {
            if(buffer[0] == '#' || isBlankLine(buffer))
            {
                //this line is a comment
                continue;
            }
            else
            {
                //set some invalid defaults
                int planeID = -1;
                struct AU_UAV_ROS::waypoint temp;
                temp.latitude = temp.longitude = temp.altitude = -1000;

                //parse the string
                sscanf(buffer, "%d %lf %lf %lf\n", &planeID, &temp.latitude, &temp.longitude, &temp.altitude);

                //check for the invalid defaults
                if(planeID == -1 || temp.latitude == -1000 || temp.longitude == -1000 || temp.altitude == -1000)
                {
                    //this means we have a bad file somehow
                    ROS_ERROR("Bad file parse");
                    return false;
                }

                //check our map for an entry, if we dont have one then this is the first time
                //that this plane ID has been referenced so it's true
                if(isFirstPoint.find(planeID) == isFirstPoint.end())
                {
                    if (planeID >= 0 && planeID <= 31) {
                        isFirstPoint[planeID] = true;

                        //this is the first time we've seen this ID in the file, attempt to create it
                        AU_UAV_ROS::CreateSimulatedPlane srv;
                        srv.request.startingLatitude = temp.latitude;
                        srv.request.startingLongitude = temp.longitude;
                        srv.request.startingAltitude = temp.altitude;
                        srv.request.startingBearing = 0;
                        srv.request.requestedID = planeID;

                        //send the service request
                        printf("\nRequesting to create new simulated plane with ID #%d...\n", planeID);
                        if(createSimulatedPlaneClient.call(srv))
                        {
                            printf("New simulated plane with ID #%d has been created!\n", srv.response.planeID);
                        }
                        else
                        {
                            ROS_ERROR("Did not receive a response from simulator");
                        }
                    }
                    else if (planeID >= 32 && planeID <= 63){
                        isFirstPoint[planeID] = true;
                        //this planeID is for a real UAV
                        // use the requestPlaneID service to initialize the planesArray in coordinator with real UAV object
                        AU_UAV_ROS::RequestPlaneID srv;
                        srv.request.requestedID = planeID;
                        printf("\nRequesting to create new real plane with ID #%d...\n", planeID);
                        //check to make sure the client call worked (regardless of return values from service)
                        if(requestPlaneIDClient.call(srv))
                        {

                            if(srv.response.planeID == -1)
                            {
                                ROS_ERROR("Couldn't create plane with ID %d", planeID);
                                return false;
                            }
                            //plane added successfully
                            printf("New real plane with ID #%d has been created!\n", srv.response.planeID);
                        }
                        else
                        {
                            //if this happens, chances are the coordinator isn't running
                            ROS_ERROR("Did not receive an ID from coordinator");
                            return false;
                        }
                    }
                    else {
                        //this means we have a bad file somehow
                        ROS_ERROR("Bad file parse");
                        return false;
                    }
                }

                //only clear the queue with the first point
                if(isFirstPoint[planeID]) isFirstPoint[planeID] = false;
            }
        }

        //if we make it here everything happened according to plan
        return true;
    }
    else
    {
        ROS_ERROR("Invalid filename or location: %s", filename.c_str());
        return false;
    }
}

/*
isDistributed()
This checks to see if the distributed simulator node is running.
*/
bool isDistributed()
{  
    ros::V_string nodes;
    ros::master::getNodes(nodes);
    int size = nodes.size();
    std::string distSimulator("/distSimulator");
    for (int i = 0; i < size; i++)
    {
    	if (distSimulator.compare(nodes[i]) == 0)
    		return true;
    }
    
    return false;
}

/*
initiateTest()
This functions initiates the test flight for the real and sim planes.
*/
void initiateTest()
{
    //create all our UAVs
    if(createCourseUAVs(selectedFileName))
    {
        //nothing bad happened
    }
    else
    {
        ROS_ERROR("Error creating UAVs");
        exit(0);
    }

    AU_UAV_ROS::LoadCourse srv;
    srv.request.filename = selectedFileName;

    //countdown to success
    //system("clear");
    printf("\n");
    printf("Loading course into coordinator in...\n3...\n");
    ros::Duration(1.0).sleep();
    printf("2...\n");
    ros::Duration(1.0).sleep();
    printf("1...\n");
    ros::Duration(1.0).sleep();

    //call the load course function on the coordinator
    if(loadCourseClient.call(srv))
    {
        printf("Course loaded successfully!\n");
    }
    else
    {
        ROS_ERROR("Error loading course");
        exit(0);
    }

}

//New - JC
bool setFileName(AU_UAV_ROS::SendFilePath::Request  &req, AU_UAV_ROS::SendFilePath::Response &res)
{
    res.error = "None";
    std::cout << req.filename;
    selectedFileName = req.filename;
    fileNameLoaded = true;
    return true;
}

void startNodes(void)
{
	//start coordinator
	AU_UAV_ROS::StartCoordinator coordsrv;
	coordsrv.request.indicator = "start coordinator";
	while (initiateCoordinator.call(coordsrv) == false)
	{
		ROS_INFO("starting coordinator...");
	}

	//start simulator
	AU_UAV_ROS::StartSimulator simsrv;
	simsrv.request.indicator = "start simulator";
	while (initiateSimulator.call(simsrv) == false)
	{
		ROS_INFO("starting simulator....");
	}

	//start collision avoidance if the distributed simulator is not running
	if (!isDistributed())
	{
		AU_UAV_ROS::StartCollisionAvoidance casrv;
		casrv.request.indicator = "start collision avoidance";
		while (initiateCollisionAvoidance.call(casrv) == false)
		{
			ROS_INFO("starting collision avoidance...");
		}
	}

	//start XbeeIO
	AU_UAV_ROS::StartXbeeIO xbeesrv;
	xbeesrv.request.indicator = "start xbee io";
	while (initiateXbeeIO.call(xbeesrv) == false)
	{
		ROS_INFO("starting XbeeIO");
	}
}

/*
main(...)
This just sets up all the ROS stuff and serves as the primary top level menu
*/
int main(int argc, char **argv)
{
    //Standard ROS startup
    ros::init(argc, argv, "GUIInterfacer");
    ros::NodeHandle n;

    //advertise service - New - JC
    ros::ServiceServer fileNameService = n.advertiseService("send_file_path", setFileName);

    //setup client services
    createSimulatedPlaneClient = n.serviceClient<AU_UAV_ROS::CreateSimulatedPlane>("create_simulated_plane");
    deleteSimulatedPlaneClient = n.serviceClient<AU_UAV_ROS::DeleteSimulatedPlane>("delete_simulated_plane");
    requestPlaneIDClient = n.serviceClient<AU_UAV_ROS::RequestPlaneID>("request_plane_ID");
    goToWaypointClient = n.serviceClient<AU_UAV_ROS::GoToWaypoint>("go_to_waypoint");
    loadPathClient = n.serviceClient<AU_UAV_ROS::LoadPath>("load_path");
    loadCourseClient = n.serviceClient<AU_UAV_ROS::LoadCourse>("load_course");
    initiateCoordinator = n.serviceClient<AU_UAV_ROS::StartCoordinator>("start_coordinator");
    initiateCollisionAvoidance = n.serviceClient<AU_UAV_ROS::StartCollisionAvoidance>("start_collision_avoidance");
    initiateSimulator = n.serviceClient<AU_UAV_ROS::StartSimulator>("start_simulator");
    initiateXbeeIO = n.serviceClient<AU_UAV_ROS::StartXbeeIO>("start_xbeeio");

    //make sure all other nodes have time to activate
    sleep(1);

    //new - JC - We cannot spin() because it will never stop, but we need to get our service callbacks so let's spin until we get the service call.
        ros::Rate r(10); // 10 hz
        while (!fileNameLoaded)
        {
        ros::spinOnce();
        r.sleep();
        }

    startNodes();
    //make sure all other nodes have time to activate
    sleep(1);

//send service call to next node in line - in that node have a blocking call in main that just does the above and make the boolean true when the service is called 
    initiateTest();

    return 0;
}
