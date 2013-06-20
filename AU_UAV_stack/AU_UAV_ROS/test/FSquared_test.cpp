/*
 *Fsquared_test
 *
 * let's test some stuff
 * 
 * team 1 2013  
 * Andrew Cunningham and Victoria Wu
 */

#include <gtest/gtest.h>

//what are we testing
#include "AU_UAV_ROS/vmath.h"
#include "AU_UAV_ROS/planeObject.h"
#include "AU_UAV_ROS/Fsquared.h"

#define ENEMY_LAT 32.6
#define ENEMY_LONG -85.5
#define ERROR 1		//acceptable error in meters
#define DELTA 0.005	//results in about 550 m difference north/south
			//		   470 m difference east/west

namespace	{
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

