/* Author: Andrew Cunningham
 *
 * Description: This file containts test cases to test the methods related to
 * tempForceWaypoint
 *
 */


#include <gtest/gtest.h>
#include <cstdlib>
#include "AU_UAV_ROS/vmath.h"
#include "AU_UAV_ROS/planeObject.h"
#include "AU_UAV_ROS/Fsquared.h"
#include "AU_UAV_ROS/SimulatedPlane.h"

#define ENEMY_LAT 32.6
#define ENEMY_LONG -85.5
#define ERROR 1 //acceptable error in meters
#define DELTA 0.005 //results in about 550 m difference north/south

namespace {

	class tempForceWaypoint_tester: public :: testing:Test{
	protected:
		tempForceWaypoint_tester(){
			enemy.setCurrentLoc(ENEMY_LAT,ENEMY_LONG,0);
			enemy.setCurrentBearing(90);
			AU_UAV_ROS::waypoint goal_wp;
			goal_wp.latitude = ENEMY_LAT;
			goal_wp.longitude = ENEMY_LONG + DELTA;
			enemy.setDestination(goal_wp);



			fromFarNorthPlane->planeID = 30;

			fromFarNorthPlane->currentLatitude = ENEMY_LAT;
			fromFarNorthPlane->currentLongitude = ENEMY_LONG + DELTA;
			fromFarNorthPlane->currentAltitude = 0;

			fromFarNorthPlane->destLatitude = ENEMY_LAT;
			fromFarNorthPlane->destLongitude = ENEMY_LONG;
			fromFarNorthPlane->destAltitude = 0;

			//fromFarNorthPlane->groundSpeed = this->groundSpeed;
			//fromFarNorthPlane->targetBearing = this->actualBearing;

			fromFarNorthPlane->currentWaypointIndex = 0;
			//fromFarNorthPlane->distanceToDestination = 0;
			//fromFarNorthPlane->telemetryHeader.seq = this->updateIndex++;
			//fromFarNorthPlane->telemetryHeader.stamp = ros::Time::now();
		}



	//VARIABLES
	AU_UAV_ROS::PlaneObject enemy;
	AU_UAV_ROS::TelemetryUpdate fromFarNorthPlane;
	};




	TEST_F(tempForceWaypoint_tester, findTempForceWaypoint_verifyDirection){
		AU_UAV_ROS::waypoint tempForceWaypoint;
		tempForceWaypoint = fsquared::findTempForceWaypoint(enemy, fromFarNorthPlane);
		ASSERT_EQ(ENEMY_LAT, tempForceWaypoint.latitude);
		ASSERT_LT(ENEMY_LONG, tempForceWaypoint.longitude);

	}





}
