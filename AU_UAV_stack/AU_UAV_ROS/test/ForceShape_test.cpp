/*
* ForceShape_test
*
* Test the FieldShape class 

* TESTS:
* 	Ensures that for each type of FieldShape, a point is correctly
*       classified as being either in or out of the shape
*
* team 1 2013
*/

#include <gtest/gtest.h>

//what we are testing
#include "AU_UAV_ROS/ForceField.h"

namespace	{
	class Force_Shape_tester : public ::testing::Test{
	protected:
		Force_Shape_tester(){
		//no setup, only need setup when more fieldShapes are added
		}


		/* This test function will test the fieldShape to ensure that it correctly
		 * classifies points as being "inside" or "outside" the shape */

		void In_Field_tester(ForceField aField){
			fsquared::relativeCoordinates testCoordinates;

			//test to ensure that overlapping planes register as in a field shape
			testCoordinates.x = 0;
			testCoordinates.y = 0;
			EXPECT_TRUE(aField.areCoordinatesInMyField(testCoordinates, 0, 0)) << "Overlap is broken";

			//ensure that four far away points are not found to be in the shape
			testCoordinates.x = 99999;
			testCoordinates.y = 99999;
			EXPECT_FALSE(aField.areCoordinatesInMyField(testCoordinates, 0, 0)) << "First quadrant far away point is broken";
			testCoordinates.x = -99999;
			testCoordinates.y = 99999;
			EXPECT_FALSE(aField.areCoordinatesInMyField(testCoordinates, 0, 0)) << "Second quadrant far away point is broken";
			testCoordinates.x = -99999;
			testCoordinates.y = -99999;
			EXPECT_FALSE(aField.areCoordinatesInMyField(testCoordinates, 0, 0)) << "Third quadrant far away point is broken";
			testCoordinates.x = 99999;
			testCoordinates.y = -99999;
			EXPECT_FALSE(aField.areCoordinatesInMyField(testCoordinates, 0, 0)) << "Fourth quadrant far away point is broken";
		}


		//this field will test the default field (2012 group's field setup)
		ForceField defaultField;
	};

	//test the each field shape using the In_Field_tester method to ensure that
	//points are properly classified

	TEST_F(Force_Shape_tester, In_Field_tests){
		//test the default field shape (the oval shape)
		In_Field_tester(defaultField);

		//add more fields as more are created
	}
}

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
