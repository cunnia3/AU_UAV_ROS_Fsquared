/*
 *Fsquared_test
 *
 * let's test some stuff
 * Tests Fsquared helper methods (find relative location, find field angle, find angle between)
 * also will test plane object mappy and sum repulsive forces
 * team 1 2013  - wu 
 */

#include <gtest/gtest.h>

//what are we testing
#include "AU_UAV_ROS/vmath.h"
#include "AU_UAV_ROS/planeObject.h"
#include "AU_UAV_ROS/Fsquared.h"
#include <map>

#define ENEMY_LAT 32.6
#define ENEMY_LONG -85.5
#define ERROR 1		//acceptable error in meters
#define DELTA 0.005	//results in about 550 m difference north/south
			//		   470 m difference east/west

#define CLOSE_DELTA 0.000000001 	//a small enough delta in long/lat to ensure plane is in fields (sumRepulsive)
namespace	{


//-----------------------
//plane stuff
//-----------------------


class F_Squared_tester: public ::testing::Test	{

	protected:
		F_Squared_tester()	{
			enemy.setCurrentLoc(ENEMY_LAT,ENEMY_LONG,0);	
			enemy.setCurrentBearing(0);	//going north	

			northPlane.setCurrentLoc(ENEMY_LAT + DELTA, ENEMY_LONG, 0);
			northPlane.setCurrentBearing(180);
			northPlane.setID(1);
			eastPlane.setCurrentLoc(ENEMY_LAT, ENEMY_LONG + DELTA , 0);
			eastPlane.setCurrentBearing(-90);
			eastPlane.setID(2);
			southPlane.setCurrentLoc(ENEMY_LAT -DELTA, ENEMY_LONG, 0);
			southPlane.setCurrentBearing(0);
			southPlane.setID(3);
			westPlane.setCurrentLoc(ENEMY_LAT ,ENEMY_LONG -DELTA, 0);
			westPlane.setCurrentBearing(90);
			westPlane.setID(4);
			
			northEastPlane.setCurrentLoc(ENEMY_LAT + DELTA, ENEMY_LONG + DELTA, 0);
			northEastPlane.setCurrentBearing(-135);
			northEastPlane.setID(5);
			northWestPlane.setCurrentLoc(ENEMY_LAT + DELTA , ENEMY_LONG - DELTA , 0);
			northWestPlane.setCurrentBearing(135);
			northWestPlane.setID(6);
			southWestPlane.setCurrentLoc(ENEMY_LAT -DELTA, ENEMY_LONG- DELTA, 0);
			southWestPlane.setCurrentBearing(45);
			southWestPlane.setID(7);
			southEastPlane.setCurrentLoc(ENEMY_LAT - DELTA ,ENEMY_LONG + DELTA, 0);
			southEastPlane.setCurrentBearing(-45);
			southEastPlane.setID(8);
	
			closerNorth.setCurrentLoc(ENEMY_LAT + CLOSE_DELTA, ENEMY_LONG, 0);
			closerNorth.setCurrentBearing(180);
			closerNorth.setID(9);
			closerEast.setCurrentLoc(ENEMY_LAT, ENEMY_LONG + CLOSE_DELTA , 0);
			closerEast.setCurrentBearing(-90);
			closerEast.setID(10);
			closerSouth.setCurrentLoc(ENEMY_LAT -CLOSE_DELTA, ENEMY_LONG, 0);
			closerSouth.setCurrentBearing(0);
			closerSouth.setID(11);
			closerWest.setCurrentLoc(ENEMY_LAT ,ENEMY_LONG - CLOSE_DELTA, 0);
			closerWest.setCurrentBearing(90);
			closerWest.setID(12);
			

		}

		//Make sure all planes' bearing is toward enemy
		void setBearingFacingEnemy()	{
			
			northPlane.setCurrentBearing(180);
			eastPlane.setCurrentBearing(-90);
			westPlane.setCurrentBearing(90);
			southPlane.setCurrentBearing(0);

			northEastPlane.setCurrentBearing(-135);
			southEastPlane.setCurrentBearing(-45);
			southWestPlane.setCurrentBearing(45);
			northWestPlane.setCurrentBearing(135);

			closerNorth.setCurrentBearing(180);
			closerEast.setCurrentBearing(-90);
			closerWest.setCurrentBearing(90);
			closerSouth.setCurrentBearing(0);


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

	AU_UAV_ROS::PlaneObject closerNorth;
	AU_UAV_ROS::PlaneObject closerEast;
	AU_UAV_ROS::PlaneObject closerSouth;
	AU_UAV_ROS::PlaneObject closerWest;
};


TEST_F(F_Squared_tester, findingFieldAngle_planes)	{
	double tempAngle;
	enemy.setCurrentBearing(0);
	EXPECT_EQ(90, fsquared::findFieldAngle(eastPlane,enemy) );	
	EXPECT_EQ(-90, fsquared::findFieldAngle(westPlane,enemy) );	
	EXPECT_EQ(0, fsquared::findFieldAngle(northPlane,enemy) );	
	EXPECT_TRUE((tempAngle = fsquared::findFieldAngle(southPlane,enemy))==180||tempAngle==-180 );	

	enemy.setCurrentBearing(135);	//facing southeast
	EXPECT_EQ(-45, fsquared::findFieldAngle(eastPlane,enemy) );	
	EXPECT_EQ(135, fsquared::findFieldAngle(westPlane,enemy) );	
	EXPECT_EQ(-135, fsquared::findFieldAngle(northPlane,enemy) );	
	EXPECT_EQ(45, fsquared::findFieldAngle(southPlane,enemy) );	


}


/*
 * Tests motionVectorToWayPoint
 * given angle, scalar, and waypoint, find resultant waypoint
 */
TEST_F(F_Squared_tester, generateWaypoint)	{
	//base waypoint
	AU_UAV_ROS::waypoint wp; wp.latitude = ENEMY_LAT; wp.longitude = ENEMY_LONG; wp.altitude = 0; 
	int scalar; double givenAngle;
	
	//testing params
	AU_UAV_ROS::waypoint dest;
	double distance; double testedAngle;

	//start
	scalar = 1; givenAngle = 0;
	dest = fsquared::motionVectorToWaypoint(givenAngle, wp, scalar);
	distance = findDistance(wp.latitude, wp.longitude, dest.latitude, dest.longitude);	
	testedAngle = forceAngle360(findAngle(wp.latitude, wp.longitude, dest.latitude, dest.longitude));
	EXPECT_NEAR(distance, scalar, .001);
	EXPECT_NEAR(testedAngle, givenAngle, .01); 

	scalar = 2; givenAngle = 45;
	dest = fsquared::motionVectorToWaypoint(givenAngle, wp, scalar);
	distance = findDistance(wp.latitude, wp.longitude, dest.latitude, dest.longitude);	
	testedAngle = forceAngle360(findAngle(wp.latitude, wp.longitude, dest.latitude, dest.longitude));
	EXPECT_NEAR(distance, scalar, .001);
	EXPECT_NEAR(testedAngle, givenAngle, .01); 

	scalar = 3; givenAngle = 135;
	dest = fsquared::motionVectorToWaypoint(givenAngle, wp, scalar);
	distance = findDistance(wp.latitude, wp.longitude, dest.latitude, dest.longitude);	
	testedAngle = forceAngle360(findAngle(wp.latitude, wp.longitude, dest.latitude, dest.longitude));
	EXPECT_NEAR(distance, scalar, .001);
	EXPECT_NEAR(testedAngle, givenAngle, .01); 

	scalar = 9; givenAngle = 225;
	dest = fsquared::motionVectorToWaypoint(givenAngle, wp, scalar);
	distance = findDistance(wp.latitude, wp.longitude, dest.latitude, dest.longitude);	
	testedAngle = forceAngle360(findAngle(wp.latitude, wp.longitude, dest.latitude, dest.longitude));
	EXPECT_NEAR(distance, scalar, .001);
	EXPECT_NEAR(testedAngle, givenAngle, .01); 

}


/*
 * testing findRelativeLoc
 * only testing n/e/s/w so far... future - test inbetween directions?
 */
TEST_F(F_Squared_tester, findRelativeLoc)	{
	enemy.setCurrentBearing(0);
	fsquared::relativeCoordinates rel;

	rel = fsquared::findRelativePosition(northPlane,enemy); 
	EXPECT_NEAR(rel.y, 556, ERROR); EXPECT_NEAR(rel.x, 0, ERROR);	
	rel = fsquared::findRelativePosition(eastPlane,enemy); 
	EXPECT_NEAR(rel.y, 0, ERROR); EXPECT_NEAR(rel.x, 468.349, ERROR);	
	rel = fsquared::findRelativePosition(southPlane,enemy); 
	EXPECT_NEAR(rel.y, -556, ERROR); EXPECT_NEAR(rel.x, 0, ERROR);	
	rel = fsquared::findRelativePosition(westPlane,enemy); 
	EXPECT_NEAR(rel.y, 0, ERROR); EXPECT_NEAR(rel.x, -468.349, ERROR);	

	rel = fsquared::findRelativePosition(northEastPlane,enemy); 
	EXPECT_NEAR(rel.y, 556, ERROR); EXPECT_NEAR(rel.x, 468.349, ERROR);	


	enemy.setCurrentBearing(180);
	rel = fsquared::findRelativePosition(southPlane,enemy); 
	EXPECT_NEAR(rel.y, 556, ERROR); EXPECT_NEAR(rel.x, 0, ERROR);	
	rel = fsquared::findRelativePosition(westPlane,enemy); 
	EXPECT_NEAR(rel.y, 0, ERROR); EXPECT_NEAR(rel.x, 468.349, ERROR);	
	rel = fsquared::findRelativePosition(northPlane,enemy); 
	EXPECT_NEAR(rel.y, -556, ERROR); EXPECT_NEAR(rel.x, 0, ERROR);	
	rel = fsquared::findRelativePosition(eastPlane,enemy); 
	EXPECT_NEAR(rel.y, 0, ERROR); EXPECT_NEAR(rel.x, -468.349, ERROR);	
	
}


/*
 * planeIn_updateMap
 * planeOut_updateMap
 * let's hope this works 
 */
TEST_F(F_Squared_tester, addRemovePlanesToMap)	{

	enemy.clearMap();
	enemy.planeIn_updateMap(northPlane);


	//Put plane in!	
	EXPECT_EQ(northPlane.getCurrentLoc().latitude, enemy.getMap().find(northPlane.getID())->second.getCurrentLoc().latitude);
	EXPECT_EQ(northPlane.getCurrentLoc().longitude, enemy.getMap().find(northPlane.getID())->second.getCurrentLoc().longitude);
	EXPECT_EQ(northPlane.getCurrentLoc().altitude, enemy.getMap().find(northPlane.getID())->second.getCurrentLoc().altitude);

	EXPECT_EQ(northPlane.getDestination().latitude, enemy.getMap().find(northPlane.getID())->second.getDestination().latitude);
	EXPECT_EQ(northPlane.getDestination().longitude, enemy.getMap().find(northPlane.getID())->second.getDestination().longitude);
	EXPECT_EQ(northPlane.getDestination().altitude, enemy.getMap().find(northPlane.getID())->second.getDestination().altitude);

	EXPECT_EQ(enemy.getMap().find(northPlane.getID())->second.getCurrentBearing(), northPlane.getCurrentBearing());	

	//Take plane out!
	//
	enemy.planeOut_updateMap(northPlane);
	EXPECT_TRUE(enemy.getMap().find(northPlane.getID())== enemy.getMap().end());

	enemy.clearMap();
}

/*
 * sum repulsive forces
 */
TEST_F(F_Squared_tester, sumRepulsiveForces)	{

	/*
	 * Problem is NOT with how the map is set up.
	 * I think it may be in the calculate repulsive force
	 */
	std::map<int, AU_UAV_ROS::PlaneObject> avoid;
	int fakeID = 0;
	
	setBearingFacingEnemy();

	avoid[closerNorth.getID()] = closerNorth; 
	//it sees northplane in the map as all zero, default constructor???
	//derp - using [key] on a non existant element will create it. hehhhe heheh
	EXPECT_EQ(enemy.getCurrentBearing(), 0);
	EXPECT_EQ(avoid[closerNorth.getID()].getCurrentBearing(), 180); 
	//Plane in map should == plane I put in
	EXPECT_EQ(avoid[closerNorth.getID()].getCurrentLoc().latitude, closerNorth.getCurrentLoc().latitude);
	EXPECT_EQ(avoid[closerNorth.getID()].getCurrentLoc().longitude, closerNorth.getCurrentLoc().longitude);
	//verifying closer in map's location in relation to enemy
	EXPECT_GT(avoid[closerNorth.getID()].getCurrentLoc().latitude, enemy.getCurrentLoc().latitude);
	EXPECT_EQ(avoid[closerNorth.getID()].getCurrentLoc().longitude, enemy.getCurrentLoc().longitude);
	
	AU_UAV_ROS::mathVector vec = fsquared::sumRepulsiveForces(enemy, avoid);
	EXPECT_EQ(forceAngle360(vec.getDirection()), 270);

	avoid[closerEast.getID()] = closerEast;
	vec = fsquared::sumRepulsiveForces(enemy, avoid);
	EXPECT_EQ(forceAngle360(vec.getDirection()), 225);

	avoid[closerSouth.getID()] = closerSouth;
	vec = fsquared::sumRepulsiveForces(enemy, avoid);
	EXPECT_EQ(forceAngle360(vec.getDirection()), 180);

}

//-----------------------
//VECTORS!!
//-----------------------

class VectorStuff : public ::testing::Test	{

	protected:
		VectorStuff()	{
			north.setDirection(90); north.setMagnitude(1);
			east.setDirection(0); east.setMagnitude(1);
			south.setDirection(270); south.setMagnitude(1);
			west.setDirection(180); west.setMagnitude(1);
		}
	AU_UAV_ROS::mathVector north;
	AU_UAV_ROS::mathVector east;
	AU_UAV_ROS::mathVector south;
	AU_UAV_ROS::mathVector west;

};


//find angle between two vectors
TEST_F(VectorStuff, findingAngle)	{
	int angleDiff;
	//this greater angle than other when both are [0,360]
	EXPECT_TRUE((angleDiff=south.findAngleBetween(north))==180||angleDiff==-180);
	EXPECT_EQ(90, south.findAngleBetween(west));
	EXPECT_EQ(-90, south.findAngleBetween(east));

	//this smaller angle than other when both are [0,360]
	EXPECT_TRUE((angleDiff=north.findAngleBetween(south))==180||angleDiff==-180);
	EXPECT_EQ(-90, north.findAngleBetween(west));
	EXPECT_EQ(90, north.findAngleBetween(east));

	//sanity check
	EXPECT_EQ(0, south.findAngleBetween(south));	
}



}




int main(int argc, char **argv)	{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

