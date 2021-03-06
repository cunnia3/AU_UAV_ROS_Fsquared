/*
Distributed Simulator
In the decentralized environment, the Collision Avoidance node will not be run.
This node subscribes to telemetry updates and has every simulated plane run some collision
avoidance in the callback.
*/

//Standard C++ headers
#include <sstream>
#include <map>

//ROS headers
#include "ros/ros.h"
#include "AU_UAV_ROS/standardDefs.h"
#include "AU_UAV_ROS/TelemetryUpdate.h"
#include "AU_UAV_ROS/Command.h"
#include "AU_UAV_ROS/RequestPlaneID.h"
#include "AU_UAV_ROS/CreateSimulatedPlane.h"
#include "AU_UAV_ROS/DeleteSimulatedPlane.h"
#include "AU_UAV_ROS/SimulatedPlane.h"
#include "AU_UAV_ROS/StartSimulator.h"
#include "AU_UAV_ROS/planeObject.h"

//Coordinator Services
ros::ServiceClient requestPlaneIDClient;

//a map of plane IDs to the Simulated Plane with that ID
std::map<int, AU_UAV_ROS::SimulatedPlane> simPlaneMap;

//a map of plane IDs to the associated PlaneObject
std::map<int, AU_UAV_ROS::PlaneObject> planeObjectMap;


//global boolean to start this node.
bool readyToStart = false;

/*
commandCallback:
This is the callback in place to handle any commands sent.  Note that not all commands will be destined for
the simulator so it must be verified before proceeding with any commands.
*/
//TODO: make sure cmd is for simulated (odd planeID) UAVs
void commandCallback(const AU_UAV_ROS::Command::ConstPtr& msg)
{
	//check to make sure that the plane ID is in the simulator
	if(simPlaneMap.find(msg->planeID) != simPlaneMap.end())
	{
		//let the simulator handle the new command now
		ROS_INFO("Received new message: Plane #%d to (%f, %f, %f)", msg->planeID, msg->latitude, msg->longitude, msg->altitude);
		simPlaneMap[msg->planeID].handleNewCommand(*msg);
	}
	else
	{
		//we may want to remove this message eventually
		ROS_INFO("Received message to non-simulated plane $%d", msg->planeID);
	}
}

/*
telemetryCallback:
This is the callback used to handle how other planes would get an update. Every plane in the map, except
for the one that the update came from, handles its own collision avoidance.
*/
void telemetryCallback(const AU_UAV_ROS::TelemetryUpdate::ConstPtr& msg)
{
	// Make sure the plane ID from the update is in the map
	if(simPlaneMap.find(msg->planeID) == simPlaneMap.end())
	{
		ROS_INFO("Received message to non-simulated plane $%d", msg->planeID);
		return;
	}
	
	// Update PlaneObject map
	planeObjectMap.find(msg->planeID)->second.update(*msg);
	
	// Check for collisions from the perspective of each plane being simulated
	std::map<int, AU_UAV_ROS::SimulatedPlane>::iterator it;
	for (it = simPlaneMap.begin(); it != simPlaneMap.end(); it++)
	{
	
		// The plane that sent the update doesn't need to check for collisions
		if (it->first == msg->planeID)
			continue;
		
		// For now, assume that every plane can get updates from every other plane
		simPlaneMap[it->first].handleCollisionAvoidance(planeObjectMap[it->first], planeObjectMap);
		//simPlaneMap[it->first].handleCollisionAvoidance(simPlaneMap);
	}
}

/*
createSimulatePlaneCallback
This is the callback used to handle any users wishing to create a new plane.  This could be used for setting
up a course as well.
*/
bool createSimulatedPlaneCallback(AU_UAV_ROS::CreateSimulatedPlane::Request &req, AU_UAV_ROS::CreateSimulatedPlane::Response &res)
{
	//create a service to get a plane ID to use
	AU_UAV_ROS::RequestPlaneID srv;
	srv.request.requestedID = req.requestedID;
	
	//check to make sure the client call worked (regardless of return values from service)
	if(requestPlaneIDClient.call(srv))
	{
		res.planeID = srv.response.planeID;
		
		if(srv.response.planeID == -1)
		{
			ROS_ERROR("Couldn't create plane with ID %d", req.requestedID);
			return false;
		}
		
		//create and add our plane to the list of simulated planes
		//AU_UAV_ROS::SimulatedPlane newPlane(srv.response.planeID, req);
		simPlaneMap[srv.response.planeID] = AU_UAV_ROS::SimulatedPlane(srv.response.planeID, req);
		planeObjectMap[srv.response.planeID] = AU_UAV_ROS::PlaneObject();
		planeObjectMap[srv.response.planeID].setID(srv.response.planeID);
		
		//plane created successfully
		return true;
	}
	else
	{
		//if this happens, chances are the coordinator isn't running
		ROS_ERROR("Did not receive an ID from coordinator");
		return false;
	}
}

/*
deleteSimulatedPlaneCallback
This callback will remove a plane from the simulator and stop it from sending updates. NOTE: this does not
free up that plane ID in the coordinator.  New planes will still have higher IDs.
*/
bool deleteSimulatedPlaneCallback(AU_UAV_ROS::DeleteSimulatedPlane::Request &req, AU_UAV_ROS::DeleteSimulatedPlane::Response &res)
{
	//check to make sure the plane is simulated
	if(simPlaneMap.find(req.planeID) != simPlaneMap.end())
	{
		//we found it, erase that bad boy
		simPlaneMap.erase(req.planeID);
		planeObjectMap.erase(req.planeID);
		return true;
	}
	else
	{
		//this plane must not be simulated, silly user!
		ROS_ERROR("No simulated plane with ID #%d", req.planeID);
		return false;
	}
}

bool startSimulator(AU_UAV_ROS::StartSimulator::Request &req, AU_UAV_ROS::StartSimulator::Response &res)
{
    //ROS_INFO(req.indicator);
    readyToStart = true;
    
    // we shouldn't ever have an error, so populate it with "passed"
    res.error = "passed";
    return true;
}

int main(int argc, char **argv)
{
	//Standard ROS startup
	ros::init(argc, argv, "distSimulator");
	ros::NodeHandle n;

        //init service to start this node        
	ros::ServiceServer startSimulatorServer = n.advertiseService("start_simulator", startSimulator);

	ros::Rate r(10); // 10 hz
        while (!readyToStart)
        {
        ros::spinOnce();
        r.sleep();
        }

	
	//setup subscribing to command messages
	ros::Subscriber sub = n.subscribe("commands", 1000, commandCallback);
	
	//setup subscribing to telemerty messages (for collision avoidance
	ros::Subscriber telemetrySub = n.subscribe("telemetry", 1000, telemetryCallback);
	
	//setup publishing to telemetry message
	ros::Publisher telemetryPub = n.advertise<AU_UAV_ROS::TelemetryUpdate>("telemetry", 1000);
	
	
	//setup server services
	ros::ServiceServer createSimulatedPlaneService = n.advertiseService("create_simulated_plane", createSimulatedPlaneCallback);
	ros::ServiceServer deleteSimulatedPlaneService = n.advertiseService("delete_simulated_plane", deleteSimulatedPlaneCallback);
	
	//setup client services
	requestPlaneIDClient = n.serviceClient<AU_UAV_ROS::RequestPlaneID>("request_plane_ID");
	
	//TODO:check for validity of 1 Hz
	//currently updates at 1 Hz, based of Justin Paladino'sestimate of approximately 1 update/sec
	int loopRate = 1;
	int loopMultiple = 10;
	int loopPosition = 0;
	//we multiply so we can spin more
	ros::Rate loop_rate(loopMultiple*loopRate);
	 
	//while the user doesn't kill the process or we get some crazy error
	while(ros::ok())
	{
		//first check for callbacks
		ros::spinOnce();
		
		//only run the update once every ten cycles
		if(loopPosition == 0)
		{
			//prep to send some updates
			AU_UAV_ROS::TelemetryUpdate tUpdate;
			std::map<int, AU_UAV_ROS::SimulatedPlane>::iterator ii;
		
			//iterate through all simulated planes and generate an update for each
			for(ii = simPlaneMap.begin(); ii != simPlaneMap.end(); ii++)
			{
				ii->second.fillTelemetryUpdate(&tUpdate);
				telemetryPub.publish(tUpdate);
			}
		}
		
		//sleep until next update cycle
		loopPosition = (loopPosition+1)%loopMultiple;
		loop_rate.sleep();
	}
	
	return 0;
}
