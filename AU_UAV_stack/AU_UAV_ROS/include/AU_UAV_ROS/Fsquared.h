/*
Authors: Andrew Cunningham
		 Victoria Wu

Description:
		This is an implementation of the distributed fsquared algorithm for collision avoidance and detection
		
Date: 6/12/13

TODO:
Move force header and implementation into the correct folders
Determine waypoint format (for hardware implementation)
Modify Plane object to include field as an enumeration (only use last years for now)




Future:
Situate our algorithm so that it can be simulated
Diversify field types (work on once this implementation is completed and tested


Future Future:
Organize in nodes for hardware


*/

#ifndef FSQUARED_H
#define FSQUARED_H

//ROS Includes
#include <map>
#include "AU_UAV_ROS/TelemetryUpdate.h"
#include "AU_UAV_ROS/vmath.h" 		 //MOVE ME IN
#include "AU_UAV_ROS/standardDefs.h" //contains waypoint struct

#define ATTRACTIVE_FORCE 100 //defines the magnitude of the attractive force to a
							 //waypoint
//fsquared constants
#define WP_GEN_SCALAR 3		//how far generated waypoint will be 
#define RADAR_ZONE 100		//the maximum distance "me" will track enemy



//forward declaration to prevent circular dependencies
namespace AU_UAV_ROS{
	class PlaneObject;
}


namespace fsquared{


	/*
	 * Coordinates in meters
	 * Used to calculate relative position of a plane to another plane.
	 * If coordinate frame is defined so the positive y axis is always in the direction of the bearing of a plane,
	 * then x is if another plane is to the left/right
	 * 	y is if another plane is in front of/behind
	 */

	typedef struct	{
		double x;
		double y;
	} relativeCoordinates;

	//------------------------------
	//Primary Method
	//------------------------------

	/*
	 * Precondition: Telemetry update is not from "me"
	 * Params:
	 * 		me: The plane that is receiving the telemetry update
	 * 		msg: The the telemetry update that is received
	 * 	Use:
	 * 		This is the primary method that calls all the other methods.
	 * 		To use the fsquared algorithm, call this function
	 * 	Pseudocode:
	 * 		Create plane object ("enemy") from telemetry update
	 *		check to see if enemy is within a certain distance (RADAR_ZONE)
	 *		if enemy is out of RADAR_ZONE
	 *			remove enemy from the map of planes exerting forces
	 *		else enemy is within RADAR_ZONE
	 *			if "me" is in enemy's field
	 *				add enemy to the map of planes exerting a force on "me"
	 *			else "me" is not in enemy's field
	 *				remove enemy from the map of planes exerting forces
	 *
	 *		go through map of planes exerting forces to calculate total repuslive force vector
	 *		find attractive force vector
	 *		sum attractive and repulsive forces to find the resultant vector
	 *		set the plane to move in the direction specified by the resultant vector
	 */


	AU_UAV_ROS::waypoint findTempForceWaypoint(AU_UAV_ROS::PlaneObject &me, const AU_UAV_ROS::TelemetryUpdate::ConstPtr& msg);


	//-------------------------------
	//Forces
	//-------------------------------

	/*
  	 *Precondition: "Me's" position in relation to enemy's doesn't matter.
	 *Use: Calculates the force that the enemy's field exerts on me
	 *Params:
	 *		me: Plane that is feeling the force
	 *		enemy: Plane that is exerting the force
	 *IMPLEMENTATION:
	 *		
	 *		calculate field angle from plane methods
	 *		find coordinates relative enemy
	 *				
	 *
	 *todo:		ac
	 *todo:		add field angle as param
	 *todo:
	*/
	AU_UAV_ROS::mathVector calculateRepulsiveForce(AU_UAV_ROS::PlaneObject &me, AU_UAV_ROS::PlaneObject &enemy);

	

	/*
	 * Precondition: Me and Map are not null
	 * Use: Sums repulsive forces exerted by all planes in map  acting on me
	 * Params:
	 * 		me: Plane that is feeling the forces
	 * 		map: Map of all planes where "me" is in their fields and thus exerting a 
	 * 			repulsive force on "me"
	 * Todo: TEST TEST TEST
	 */	
	AU_UAV_ROS::mathVector sumRepulsiveForces(AU_UAV_ROS::PlaneObject &me, std::map<int, AU_UAV_ROS::PlaneObject> * planesToAvoid);




	/*
	 *Precondition: Assume valid waypoint
	 *Use: Calculates the force that the waypoint exerts on me
	 *Params:
	 *		me: Plane that is feeling the force
	 *		goal_wp: The waypoint that the plane would like to reach
	 *todo:		ac
	 */
	AU_UAV_ROS::mathVector calculateAttractiveForce(AU_UAV_ROS::PlaneObject &me, AU_UAV_ROS::waypoint goal_wp);

	//-------------------------------
	//Fields
	//-------------------------------


	/* 
	 *Precondition: Assume valid planes
	 *Use: Calculates the relative angle needed to find the relative position of "me" to enemy
	 *Params:
	 *		me: Plane that is potentially in enemy's field
	 *		enemy: Plane that is producing the field
	 *Returns:	Field Angle - angle between my bearing and location of enemy plane
	 *who:		vw - DONE, TESTED
	 */
	double findFieldAngle(AU_UAV_ROS::PlaneObject &me, AU_UAV_ROS::PlaneObject &enemy);


	/*
	 *Precondition: Assume valid planes
	 *Use: Find "me's" position from enemy's POV
	 *Params:
	 *		me: Plane that is potentially in enemy's field
	 *		enemy: Plane that is producing the field
	 *Returns:	relativeCoordinates of "me" from the enemy's POV.
	 *who:		vw (DONE, tested)
	*/
	 relativeCoordinates findRelativePosition(AU_UAV_ROS::PlaneObject &me, AU_UAV_ROS::PlaneObject &enemy);
	 


	/*
	 *Precondition: Assume enemy has a valid field initialized
	 *Use: 	Given a pair of relativeCoordinates of "me", will see if "me" is located inside
	 *		enemy field.
	 *Params:
	 *		enemy: Plane that is producing the field
	 *		locationOfMe: Coordinate location of "me" from the POV of the enemy. 
	 *				Calculated by findRelativePosition()
	 *		fieldAngle: is the angle between the bearing of enemy to the location of "me"
	 *		planeAngle: angle that the repulsive force exerted on "me" will be at. The angle from enemy
	 *					to me

	 *who:		ac
	*/
	bool inEnemyField(AU_UAV_ROS::PlaneObject &enemy, relativeCoordinates locationOfMe, double fieldAngle, double planeAngle);

	bool inEnemyField(AU_UAV_ROS::PlaneObject &me, AU_UAV_ROS::PlaneObject &enemy);



	/* 
	 *Precondition: Assume valid planes
	 *Use: Calculates the relative angle needed to find the relative position of "me" to enemy
	 *Params:
	 *		me: Plane that is potentially in enemy's field
	 *		enemy: Plane that is producing the field
	 *Returns:	Field Angle - angle between my bearing and location of enemy plane
	 *who:		vw - DONE, TESTED
	 */
	double findFieldAngle(AU_UAV_ROS::PlaneObject &me, AU_UAV_ROS::PlaneObject &enemy);


	//-------------------------------
	//Waypoint generation
	//-------------------------------

	/*
	 *Precondition: Valid waypoint for me_loc 
	 *Use: Converts from desired angle heading to a waypoint. Distance to generated waypoint dependent on previously defined scalar WP_GEN_SCALAR. 
	 *Params:
	 *		motionAngle: angle between [0,360), CCW from positive x axis (longitude axis)
	 *		me_coor: "me's" current location 
	 *tood:		vw
	 *		TEST TEST TEST
	 */
	AU_UAV_ROS::waypoint motionVectorToWaypoint(double angle, AU_UAV_ROS::waypoint me_loc, double scalar); 

}



#endif

