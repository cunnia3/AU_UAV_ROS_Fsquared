/* Author: Andrew Cunningham
 *
 * Description:
 * 		This file contains tests for the functions that I was assigned in
 * 		Fsquared.h
 *
 */


#include <gtest/gtest.h>
#include <cstdlib>
#include "AU_UAV_ROS/vmath.h"
#include "AU_UAV_ROS/planeObject.h"
#include "AU_UAV_ROS/Fsquared.h"

#define ENEMY_LAT 32.6
#define ENEMY_LONG -85.5
#define ERROR 1 //acceptable error in meters
#define DELTA 0.005 //results in about 550 m difference north/south
// 470 m difference east/west


namespace	{


/*************************************
 * 			Test Classes			 *
 *************************************/

	class F_Squared_tester: public ::testing::Test	{

	protected:
	F_Squared_tester()	{
		enemy.setCurrentLoc(ENEMY_LAT,ENEMY_LONG,0);
		enemy.setCurrentBearing(0);	//going north

		northPlane.setCurrentLoc(ENEMY_LAT + DELTA, ENEMY_LONG, 0);
		northPlane.setCurrentBearing(0);
		eastPlane.setCurrentLoc(ENEMY_LAT, ENEMY_LONG + DELTA , 0);
		eastPlane.setCurrentBearing(0);
		southPlane.setCurrentLoc(ENEMY_LAT -DELTA, ENEMY_LONG, 0);
		southPlane.setCurrentBearing(0);
		westPlane.setCurrentLoc(ENEMY_LAT ,ENEMY_LONG -DELTA, 0);
		westPlane.setCurrentBearing(0);

		northEastPlane.setCurrentLoc(ENEMY_LAT + DELTA, ENEMY_LONG + DELTA, 0);
		northEastPlane.setCurrentBearing(0);
		northWestPlane.setCurrentLoc(ENEMY_LAT + DELTA , ENEMY_LONG - DELTA , 0);
		northWestPlane.setCurrentBearing(0);
		southWestPlane.setCurrentLoc(ENEMY_LAT -DELTA, ENEMY_LONG- DELTA, 0);
		southWestPlane.setCurrentBearing(0);
		southEastPlane.setCurrentLoc(ENEMY_LAT - DELTA ,ENEMY_LONG + DELTA, 0);
		southEastPlane.setCurrentBearing(0);
		}

		AU_UAV_ROS::PlaneObject enemy;
		AU_UAV_ROS::PlaneObject northPlane;
		AU_UAV_ROS::PlaneObject eastPlane;
		AU_UAV_ROS::PlaneObject westPlane;
		AU_UAV_ROS::PlaneObject southPlane;

		AU_UAV_ROS::PlaneObject northEastPlane;
		AU_UAV_ROS::PlaneObject southEastPlane;
		AU_UAV_ROS::PlaneObject southWestPlane;
		AU_UAV_ROS::PlaneObject northWestPlane;
	};



	/* class that contains multiple types of field configurations and contains
	 * methods for testing
	 */

	class calculateRepulsiveForce_tester : public ::testing::Test{
	protected:
		calculateRepulsiveForce_tester(){

			/* plane setup
			 * set me and enemy to face north and set me to be 1.1 meters to
			 * the north of enemy
			 */
			enemy.setCurrentLoc(ENEMY_LAT,ENEMY_LONG,0);
			enemy.setCurrentBearing(0);	//going north
			enemy.setField(defaultField);
			meNorth.setCurrentLoc(ENEMY_LAT + (DELTA/500), ENEMY_LONG, 0);
			meNorth.setCurrentBearing(0);
			meEast.setCurrentLoc(ENEMY_LAT, ENEMY_LONG + (DELTA/500) , 0);
			meEast.setCurrentBearing(0);
			meSouth.setCurrentLoc(ENEMY_LAT -(DELTA/500), ENEMY_LONG, 0);
			meSouth.setCurrentBearing(0);
			meWest.setCurrentLoc(ENEMY_LAT ,ENEMY_LONG -(DELTA/500), 0);
			meWest.setCurrentBearing(0);



			//Field setup
			defaultField = new ForceField();
		}


		/* Description: checks to ensure that several characteristics of a repulsive force are valid when
		 * 				enemy is directly behind "me". This test is modular so any ForceField, if defined correctly,
		 * 				will pass this test. The test checks:
		 * 				(1) Is there a non-zero force exerted?
		 * 				(2) Is the force pointing away from the enemy?
		 * Params:
		 * 		Enemy, me: two planes in a certain orientation such that "me" is in enemy's field
		 * 		enemyField: preset ForceField with initialized ForceShape and ForceFunction
		 */
		void verifyRepulsiveForce(AU_UAV_ROS::PlaneObject& me,AU_UAV_ROS::PlaneObject& enemy, ForceField * enemyField, double expectedForceAngle){
			AU_UAV_ROS::mathVector repulsiveForce;
			enemy.setField(enemyField);
			repulsiveForce = fsquared::calculateRepulsiveForce(me, enemy);

			//ensure condition (1)
			ASSERT_NE(0, repulsiveForce.getMagnitude()) << "Error: A non zero force is being exerted, is the Field shape correct?";

			//ensure condition (2)
			EXPECT_DOUBLE_EQ(expectedForceAngle, repulsiveForce.getDirection()) << "Error: Repulsive force does not point away from enemy";
		}


		//VARIABLES
		//Add more fields & planes once more are created
		AU_UAV_ROS::PlaneObject enemy;
		AU_UAV_ROS::PlaneObject meNorth;
		AU_UAV_ROS::PlaneObject meEast;
		AU_UAV_ROS::PlaneObject meSouth;
		AU_UAV_ROS::PlaneObject meWest;
		ForceField * defaultField;
	};


	/*************************************
	 * 			Test Functions			 *
	 *************************************/



	/* Description:
	 * 		This group tests the calculateRepulsiveForces function by ensuring that
	 * 		far away points make no contribution
	 *
	 */

	TEST_F(F_Squared_tester, calculateRepulsiveForces_planeTooFar){
		// Don't know why, but this test doesn't work
		//northPlane and enemy are too far away for enemy to exert a force on
		AU_UAV_ROS::mathVector repulsiveForce;
		repulsiveForce = fsquared::calculateRepulsiveForce(northPlane, enemy);
		ASSERT_DOUBLE_EQ(0, repulsiveForce.getMagnitude()) << "Error: Far away plane should not contribute to repulsive force";

	}


	/* Description:
	 * 		This test verifies repuslive force vectors by ensuring that they have
	 * 		a magnitude and are pointing in the correct direction
	 */
	TEST_F(calculateRepulsiveForce_tester, calculateRepulsiveForces_planeClose_verifyDirectionVector){
		//add in more test cases as more fields and plane arrangements are created
		verifyRepulsiveForce(meNorth, enemy, defaultField, 90);
		verifyRepulsiveForce(meEast, enemy, defaultField, 0);
		verifyRepulsiveForce(meSouth, enemy, defaultField, -90);
		verifyRepulsiveForce(meWest, enemy, defaultField, 180);
	}

	/* Description:
	 * 		This test checks to make sure that the maximum magnitude of the force
	 * 		function is located at the location of enemy.  It accopmlishes this by
	 * 		starting near the location of enemy and then comparing points that are
	 * 		further and further away and ensuring that further away points result
	 * 		in a lower force magnitude
	 */
	 /*TEST_F(calculateRepulsiveForce_tester, calculateRepulsiveForces_slidingDistance_verifyMagnitude){
		while()



	}*/



	/* Description:
	 * 		This group tests the calculateAttractiveForces function by setting the goal waypoint
	 * 		to the enemy's position and verifying that the force magnitude and angle that the
	 * 		North, East, South and West planes feel are correct
	 */
	TEST_F(F_Squared_tester, calculateAttractiveForces){

		//set goal waypoint to enemy's current position
		AU_UAV_ROS::waypoint goal_wp;
		goal_wp.latitude = ENEMY_LAT;
		goal_wp.longitude = ENEMY_LONG;
		AU_UAV_ROS::mathVector attractiveForce;

		//ensure that attractive force calculations provide the correct magnitude and direction
		//for different arrangments of planes

		//NORTH TEST
		attractiveForce = fsquared::calculateAttractiveForce(northPlane, goal_wp);
		//ATTRACTIVE_FORCE is defined in Fsquared.h
		ASSERT_DOUBLE_EQ(attractiveForce.getMagnitude(), ATTRACTIVE_FORCE) << "Error: magnitude of attractive force is miscalculated\n";
		ASSERT_DOUBLE_EQ(180, abs(attractiveForce.getDirection())) << "Error: direction of attractive force is miscalculated\n";

		//EAST TEST
		attractiveForce = fsquared::calculateAttractiveForce(eastPlane, goal_wp);
		//ATTRACTIVE_FORCE is defined in Fsquared.cpp
		ASSERT_DOUBLE_EQ(attractiveForce.getMagnitude(), ATTRACTIVE_FORCE) << "Error: magnitude of attractive force is miscalculated\n";
		ASSERT_DOUBLE_EQ(-90, attractiveForce.getDirection())<< "Error: direction of attractive force is miscalculated\n";

		//WEST TEST
		attractiveForce = fsquared::calculateAttractiveForce(westPlane, goal_wp);
		//ATTRACTIVE_FORCE is defined in Fsquared.cpp
		ASSERT_DOUBLE_EQ(attractiveForce.getMagnitude(), ATTRACTIVE_FORCE) << "Error: magnitude of attractive force is miscalculated\n";
		ASSERT_DOUBLE_EQ(90, attractiveForce.getDirection())<< "Error: direction of attractive force is miscalculated\n";

		//SOUTH TEST
		attractiveForce = fsquared::calculateAttractiveForce(southPlane, goal_wp);
		//ATTRACTIVE_FORCE is defined in Fsquared.cpp
		ASSERT_DOUBLE_EQ(attractiveForce.getMagnitude(), ATTRACTIVE_FORCE) << "Error: magnitude of attractive force is miscalculated\n";
		ASSERT_DOUBLE_EQ(0, attractiveForce.getDirection())<< "Error: direction of attractive force is miscalculated\n";
	}





}


int main(int argc, char **argv)	{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

