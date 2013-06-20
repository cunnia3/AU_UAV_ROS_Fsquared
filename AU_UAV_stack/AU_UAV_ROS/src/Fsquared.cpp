/*
Authors: Andrew Cunningham
		 Victoria Wu

Description:
		This is an implementation of the fsquared algorithm for collision avoidance and detection.
		For a description of each of these functions refer to Fsquared.h, comments in this file
		will be limited to comments on implementation


Date: 6/13/13


*/

#include "AU_UAV_ROS/Fsquared.h"
#include "AU_UAV_ROS/planeObject.h"

//-----------------------------------------
//Fields
//-----------------------------------------

/*
 * findFieldAngle
 * Preconditions:	assumes valid planes
 * params:		me: plane that is potentially in enemy's field
 * 			enemy: plane that is producing field
 * returns:		field angle - angle between enemy's bearing and my location.
 * 				0  < x < 180  = to enemy's right
 * 				-180< x < 0= to enemy's left 
 *
 * note: Different from AU_UAV_ROS::PlaneObject::findAngle(). FindAngle finds
 * the angle between the relative position vector from one plane to another and the
 * x axis in a global, absolute x/y coordinate system based on latitude and
 * longitude.
 */
double fsquared::findFieldAngle(AU_UAV_ROS::PlaneObject& me, AU_UAV_ROS::PlaneObject &enemy)	{

	//Make two vectors - one representing bearing of enemy plane
	//		     the other representing relative position from
	//		     enemy to me
	AU_UAV_ROS::mathVector enemyBearing(1, toCartesian(enemy.getCurrentBearing())); 
	AU_UAV_ROS::mathVector positionToMe(1, enemy.findAngle(me));


	//Find angle between two vectors
	return enemyBearing.findAngleBetween(positionToMe); 
}

/* Assumptions:
 * 		Only calculates radially repuslive forces from enemy to "me"
 *
 * Pseudocode:
 * 		find "me" coordinates from enemy's POV
 *		check to see if these coordinates are within enemy's field
 *		if "me" is in the enemys field
 *			find the repulisve force
 *		else
 *			the repulsive force imparted by enemy has magnitude 0
 *
 * Variables:
 * 		fieldAngle: angle between the bearing of the plane generating the force to the location
 *		rMagnitude: magnitude of the repuslive force vector
 *		rAngle:		angle of repulsive force
 *		relativePosition: x and y difference in position between me and enemy from
 *						  enemy's POV
 *
 * TODO:
 * 		Add a feel function
 * 		Incorporate "right hand turn" rules
 */

AU_UAV_ROS::mathVector fsquared::calculateRepulsiveForce(AU_UAV_ROS::PlaneObject &me, AU_UAV_ROS::PlaneObject &enemy){
   	double fieldAngle, planeAngle, rMagnitude, rAngle;
	fsquared::relativeCoordinates relativePosition;
	bool insideEnemyField;


	fieldAngle = fsquared::findFieldAngle(me, enemy);
	//find the angle from enemy's position to "me"s position
	planeAngle = enemy.findAngle(me);
	//find "me" coordinates from enemy's POV
	relativePosition = fsquared::findRelativePosition(me, enemy);
	//determine whether or not "me" is in enemy's field
	insideEnemyField = fsquared::inEnemyField(enemy, relativePosition, fieldAngle, planeAngle);
	//if "me" is in enemy field
	if(insideEnemyField){
		//calculate the force exerted by the field on "me"
		rMagnitude = enemy.getField()->findForceMagnitude(relativePosition);
		//calculate the angle of the force exerted by the field onto me
		rAngle = planeAngle; //changed from toCartesian(planeAngle - 180) to planeAngle
		AU_UAV_ROS::mathVector repulsiveForceVector(rMagnitude, rAngle);
		return repulsiveForceVector;
	}
	//"me" is not in the enemy's field, return a vector with 0 magnitude (no contribution to force)
	else{
		AU_UAV_ROS::mathVector repulsiveForceVector(0,0);
		return repulsiveForceVector;
	}
}

/* Assumptions:
 * 		The magnitude of the attractive force to the waypoint is defined correctly
 *
 * Pseudocode:
 * 		Find angle to waypoint
 * 		Set magnitude of attractive force
 * 		Return force vector
 *
 * Credit:
 * 		Derived from 2012 APF Group
 *
 */

AU_UAV_ROS::mathVector fsquared::calculateAttractiveForce(AU_UAV_ROS::PlaneObject &me, AU_UAV_ROS::waypoint goal_wp){
	double aAngle, aMagnitude, destLat, destLon, currentLat, currentLon;
	//obtain current location by accessing PlaneObject's current coordinate
	currentLat = me.getCurrentLoc().latitude;
	currentLon = me.getCurrentLoc().longitude;
	destLat = goal_wp.latitude;
	destLon = goal_wp.longitude;
	aAngle = toCartesian(findAngle(currentLat, currentLon, destLat, destLon));
	aMagnitude = ATTRACTIVE_FORCE;
	//construct the attractrive force vector and return it
	AU_UAV_ROS::mathVector attractiveForceVector(aMagnitude, aAngle);
	return attractiveForceVector;
}


/*
 *Precondition: Assume valid planes
 *Use: Find "me's" position from enemy's POV
 *Params:
 *		me: Plane that is potentially in enemy's field
 *		enemy: Plane that is producing the field
 *Returns:	relativeCoordinates in meters of "me" from the enemy's POV, where enemy's bearing is towards the positive y axis.
 *Implementation:
 *			
 *who:		vw
*/
fsquared::relativeCoordinates fsquared::findRelativePosition(AU_UAV_ROS::PlaneObject &me, AU_UAV_ROS::PlaneObject &enemy ){
	fsquared::relativeCoordinates loc;

	double distance = enemy.findDistance(me);
	double fieldAngle = fsquared::findFieldAngle(me, enemy);

	//Find Y axis coordinate (in front or behind enemey)
	loc.y = cos(fieldAngle*PI/180.0)*distance;

	//Find X Axis coordinate (to the left or right)
	loc.x = sin(fieldAngle*PI/180.0)*distance;

	return loc;
}

/* Assumptions:
 * 		Enemy plane has a properly initialized field
 * 	Description:
 * 		All calculations are handeled by the ForceField class, so this function
 * 		retrieves the ForceField associated with a plane and then calls the
 * 		appropriate method to determine whether or not a point is in a specific
 * 		field
 */
bool fsquared::inEnemyField(AU_UAV_ROS::PlaneObject &enemy, fsquared::relativeCoordinates locationOfMe, double fieldAngle, double planeAngle){
	ForceField * enemyField = enemy.getField();
	return enemyField->areCoordinatesInMyField(locationOfMe, fieldAngle, planeAngle);
}
//-----------------------------------------
//Waypoint Generation
//-----------------------------------------

/*
 *Precondition: Valid waypoint for me_loc 
 *Use: Converts from desired angle heading to a waypoint. Distance to generated waypoint dependent on previously defined scalar WP_GEN_SCALAR. 
 *Params:
 *		motionAngle: angle between [0,360), CCW from positive x axis (longitude axis)
 *		me_coor: "me's" current location 
 *tood:		vw
 */
AU_UAV_ROS::waypoint motionVectorToWaypoint(double angle, AU_UAV_ROS::waypoint me_loc) {
	AU_UAV_ROS::waypoint dest_wp;

	//Find relative offset for new waypoint.
	double x_delta_meters = WP_GEN_SCALAR*cos(angle*PI/180.0); 
	double y_delta_meters = WP_GEN_SCALAR*sin(angle*PI/180.0); 

	//Calculate new waypoint 
	double dest_wp_long= me_loc.longitude+ (x_delta_meters*METERS_TO_DELTA_LON);
	double dest_wp_lat= me_loc.latitude+ (y_delta_meters*METERS_TO_DELTA_LAT);
	dest_wp.longitude = dest_wp_long;
	dest_wp.latitude = dest_wp_lat;	
	dest_wp.altitude = me_loc.altitude;
	return dest_wp;	
}

