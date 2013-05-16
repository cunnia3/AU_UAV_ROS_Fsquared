#include <gtest/gtest.h>

/** Source code for standardDefs  */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//12 meters - set to this because simulator makes 11 meter jumps
#define COLLISION_THRESHOLD 12 //meters
#define CONFLICT_THRESHOLD 24 //meters

/*UAV SPECIFIC DEFINES*/
//25 mph = 11.17600 meters / second
#define MPS_SPEED 11.176 
#define MPH_SPEED 25

/*
Many defines for simulator calculations
*/
#define EARTH_RADIUS 6371000 //meters

//pi radians = 180 degrees
#define DEGREES_TO_RADIANS (M_PI/180.0)
#define RADIANS_TO_DEGREES (180.0/M_PI)

//1 degree latitude ~= 111.2 km
#define LATITUDE_TO_METERS (111200.0)
#define METERS_TO_LATITUDE (1.0/111200.0)


namespace AU_UAV_ROS
{
	//Here's our standard waypoint definition
	struct waypoint
	{
		double latitude;
		double longitude;
		double altitude;
	};
}

bool isBlankLine(char str[])
{
	for(int i = 0; i < strlen(str); i++)
	{
		switch(str[i])
		{
			case ' ':
			case '\n':
			case '\t':
			{
				//keep checking
				break;
			}
			default:
			{
				//not a blank line character
				return false;
				break;
			}
		}
	}
	
	//we made it here, must be blank
	return true;
}

bool isValidYesNo(char c)
{
	c = tolower(c);
	if(c == 'y' || c == 'n') return true;
	else return false;
}

double distanceBetween(struct AU_UAV_ROS::waypoint first, struct AU_UAV_ROS::waypoint second)
{
	//difference in latitudes in radians
	double lat1 = first.latitude*DEGREES_TO_RADIANS;
	double lat2 = second.latitude*DEGREES_TO_RADIANS;
	double long1 = first.longitude*DEGREES_TO_RADIANS;
	double long2 = second.longitude*DEGREES_TO_RADIANS;
	
	double deltaLat = lat2 - lat1;
	double deltaLong = long2 - long1;
	
	//haversine crazy math, should probably be verified further beyond basic testing
	//calculate distance from current position to destination
	double a = pow(sin(deltaLat / 2.0), 2);
	a = a + cos(lat1)*cos(lat2)*pow(sin(deltaLong/2.0), 2);
	a = 2.0 * asin(sqrt(a));
	
	return EARTH_RADIUS * a;
}

/** END OF SOURCE CODE */

TEST(StdDefsTests, blankLineTest1){
  char s[] = "     ";
  EXPECT_TRUE(isBlankLine(s)); 
}

TEST(StdDefsTests, blankLineTest2){
  char s[] = "blah";
  EXPECT_FALSE(isBlankLine(s)); 
}

TEST(StdDefsTests, blankLineTest3){
  char s[] = "\t";
  EXPECT_TRUE(isBlankLine(s)); 
}

TEST(StdDefsTests, blankLineTest4){
  char s[] = "\n";
  EXPECT_TRUE(isBlankLine(s)); 
}

TEST(StdDefsTests, isValidYesNoTest1) {
  char c = 'Y';
  EXPECT_TRUE(isValidYesNo(c));
}

TEST(StdDefsTests, isValidYesNoTest2) {
  char c = 'N';
  EXPECT_TRUE(isValidYesNo(c));
}

TEST(StdDefsTests, isValidYesNoTest3) {
  char c = 'y';
  EXPECT_TRUE(isValidYesNo(c));
}

TEST(StdDefsTests, isValidYesNoTest4) {
  char c = 'n';
  EXPECT_TRUE(isValidYesNo(c));
}

TEST(StdDefsTests, isValidYesNoTest5) {
  char c = 'Q';
  EXPECT_FALSE(isValidYesNo(c));
}

TEST(StdDefsTests, distanceBetweenSamePoint) {
  struct AU_UAV_ROS::waypoint first;
  struct AU_UAV_ROS::waypoint second;
  first.latitude = second.latitude = 35.232323;
  first.longitude = second.longitude = -85.232323;
  first.altitude = second.altitude = 100.0000;
  EXPECT_EQ(0, distanceBetween(first,second));
}

TEST(StdDefsTests, distanceBetween236m) {
  struct AU_UAV_ROS::waypoint first;
  struct AU_UAV_ROS::waypoint second;
  first.latitude = 32.603464;
  second.latitude = 32.601340;
  first.longitude = -85.490434;
  second.longitude = -85.490477;
  first.altitude = second.altitude = 100.0000;
  EXPECT_NEAR(236.2, distanceBetween(first,second), .1);
}

 
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


