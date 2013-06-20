/*
Authors: Andrew Cunningham
		 Victoria Wu

Description:
		This file contains definitions of the ForceField object that is required for the F^2 approach
		Currently, it is setup to contain variability of field shape, but not variability of force functions

Date: 6/12/13

.
FUTURE/WORK IN PROGRESS:
		Add in different field configurations and functions as needed
*/

#ifndef FORCEFIELD_H
#define FORCEFIELD_H

#include "AU_UAV_ROS/Fsquared.h"	 //only for coordinates
#include "AU_UAV_ROS/vmath.h"
#include "AU_UAV_ROS/standardDefs.h" //contains waypoint struct

//Forward Declarations of classes
class FieldShape;
class FieldFunction;



/**************************************************************************
 * 								FORCE FIELD								  *
 **************************************************************************/


/* Description:
 * 		This class describes an instance of an APF and is comprised of
 *			two subclasses: a FieldShape and a FieldFunction
 */
class ForceField{
public:
	//Constructor, defaults to creating an oval field with a bivariate normal function
	ForceField();


	bool areCoordinatesInMyField(fsquared::relativeCoordinates positionInField, double fieldAngle, double planeAngle);
	double findForceMagnitude(fsquared::relativeCoordinates positionInField);

private:
	FieldShape * myShape;
	FieldFunction * myFunction;
};



/**************************************************************************
 * 								SHAPES									  *
 **************************************************************************/

/* Description:
 * 		This class is an abstract base class from which all field shapes are derived
 */

class FieldShape{
public:
	virtual ~FieldShape(){};


	//Precondition: None
	//Use:
	//		This method will determine whether or not coordinates are inside
	//		this field
	//Params:
	//		positionInField: coordinate of the plane that will feel the force
	//						 relative to the position of the plane generating the field
	//		fieldAngle: bearing of the plane generating the field - angle between the plane
	//					genereating the field and the plane that will feel the force
	//		planeAngle:	angle between the two planes, calculated starting from the generating
	//					plane and going to the plane that will feel the force

	virtual bool internal_areCoordinatesInMyField(fsquared::relativeCoordinates positionInField, double fieldAngle, double planeAngle) =0;



	/*	Precondition: positionInField is inside the field
	 * 	Use:
	 * 		This method will calculate how far from the outer limit of the field
	 * 			a set of points is
	 * 		This method can be used to build field functions that are dependent
	 * 			on their field shape
	 *	TODO:
	 *		Implement if we choose a FieldFunction that is dependent on FieldShape
	 */
	 //virtual double distanceToLimit(fsquared::relativeCoordinates positionInField, double fieldAngle, double planeAngle);
};



/* Description:
 * 			This class contains the ovoid field shape that was used by the 2012 APF group,
 */
class OvalField : public FieldShape{
public:
	OvalField();
	bool internal_areCoordinatesInMyField(fsquared::relativeCoordinates positionInField, double fieldAngle, double planeAngle);

private:
	/* Credit:
	 * 		Hosea Siu and Miriam Figueroa- the 2012 REU group that worked on APFs & flocking (move this later)
	 * 		the shapeVariables struct contains the constants needed to define an ovoid
	 */
	struct shapeVariables
	{
		// these variables define the limits of the independent force function
		double gamma;
		double alphaTop;
		double betaTop;
		double alphaBot;
		double betaBot;
	};

	shapeVariables shapeParams;
};





/**************************************************************************
 * 								Functions								  *
 **************************************************************************
 *		Force is only calculated if the point is in a field shape 		  *
 **************************************************************************/



/* Description:
 * 		This class is an abstract base class from which all field functions are derived
 */
class FieldFunction{
public:
	virtual ~FieldFunction(){};
	virtual double findFieldFunctionMagnitude(fsquared::relativeCoordinates positionInField) =0;
};

/*	Function: Bivariate Normal
 * 	Equation: F = Fmax * exp(-alpha*x^2 -beta*y^2)
 */
class BivariateNormal : public FieldFunction{
public:
	BivariateNormal();
	double findFieldFunctionMagnitude(fsquared::relativeCoordinates positionInField);


private:
	//constants needed to define the bivariate normal force function
	struct forceVariables{
		double maxForce;				// maximum force imposed by one plane on another, except when they are in conflict radius
		// alpha and beta are parameters that define the bivariate normal potential field
		double alpha;
		double beta;
	};

	forceVariables functionParams;
};




#endif
