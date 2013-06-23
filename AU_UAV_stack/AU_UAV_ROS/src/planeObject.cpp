/* Implementation of planeObject.h

*/

#include "ros/ros.h"
#include "AU_UAV_ROS/planeObject.h"
#include "AU_UAV_ROS/SimulatedPlane.h"
#include <math.h>
#include "AU_UAV_ROS/standardFuncs.h" /* for PI, EARTH_RADIUS in meters */
//#include "AU_UAV_ROS/ForceField.h"
#include <math.h>

/* Implementation of the default constructor: Member variables are set to zero */
AU_UAV_ROS::PlaneObject::PlaneObject(void) {
	this->id = 0;
	this->currentLoc.altitude = 0.0;
	this->currentLoc.latitude = 0.0;
	this->currentLoc.longitude = 0.0;
	this->previousLoc.altitude = 0.0;
	this->previousLoc.latitude = 0.0;
	this->previousLoc.longitude = 0.0;
	this->targetBearing = 0.0;
	this->currentBearing = 0.0;

	this->speed = 0.0;
	this->destination.latitude = 0.0;
	this->destination.longitude = 0.0;
	this->destination.altitude = 0.0;
	this->tempForceWaypoint = destination;
	//this->lastUpdateTime = ros::Time::now().toSec(); //commented out to allow for testing
	this->collisionRadius = 0.0;
	this->setField(0,0); //initialize field to default configuration
	//this->planesToAvoid = new std::map<int, AU_UAV_ROS::PlaneObject>();
	planesToAvoid.clear();
}
/* Explicit value constructor using TelemetryUpdate */
AU_UAV_ROS::PlaneObject::PlaneObject(double cRadius, const AU_UAV_ROS::TelemetryUpdate &msg) {
	this->id = msg.planeID;
	this->currentLoc.altitude = msg.currentAltitude;
	this->currentLoc.latitude = msg.currentLatitude;
	this->currentLoc.longitude = msg.currentLongitude;
	this->previousLoc.altitude = 0.0;
	this->previousLoc.latitude = 0.0;
	this->previousLoc.longitude = 0.0;
	this->targetBearing = msg.targetBearing;
	this->currentBearing = 0.0;

	this->speed = msg.groundSpeed;
	this->destination.latitude = msg.destLatitude;
	this->destination.longitude = msg.destLongitude;
	this->destination.altitude = msg.destAltitude;
	this->tempForceWaypoint = destination;
	//this->lastUpdateTime = ros::Time::now().toSec();//  commented out to run tests
	this->collisionRadius = cRadius;
	this->setField(0,0); //initialize field to default configuration
	//this->planesToAvoid = new std::map<int, AU_UAV_ROS::PlaneObject>();
	planesToAvoid.clear();
}

AU_UAV_ROS::PlaneObject::~PlaneObject()	{
	//delete(planeField);
}
/* mutator functions to update member variables */
void AU_UAV_ROS::PlaneObject::setID(int id){
	this->id = id;
}

void AU_UAV_ROS::PlaneObject::setPreviousLoc(double lat, double lon, double alt) {
	this->previousLoc.latitude = lat;
	this->previousLoc.longitude = lon;
	this->previousLoc.altitude = alt;
}

void AU_UAV_ROS::PlaneObject::setCurrentLoc(double lat, double lon, double alt) {
	this->currentLoc.latitude = lat;
	this->currentLoc.longitude = lon;
	this->currentLoc.altitude = alt;
}


void AU_UAV_ROS::PlaneObject::setTargetBearing(double tBearing) {
	this->targetBearing = tBearing;
}

void AU_UAV_ROS::PlaneObject::setCurrentBearing(double cBearing) {
	this->currentBearing = cBearing;
}

void AU_UAV_ROS::PlaneObject::setSpeed(double speed) {
	this->speed = speed;
}

void AU_UAV_ROS::PlaneObject::setDestination(const AU_UAV_ROS::waypoint &destination) {
	this->destination = destination;
}

void AU_UAV_ROS::PlaneObject::setTempForceWaypoint(const AU_UAV_ROS::waypoint &tempForceWaypoint){
	this->tempForceWaypoint = tempForceWaypoint;
}

void AU_UAV_ROS::PlaneObject::updateTime(void) {
	this->lastUpdateTime = ros::Time::now().toSec();
}


void AU_UAV_ROS::PlaneObject::update(const AU_UAV_ROS::TelemetryUpdate &msg) {

	//Update previous and current position
	this->setPreviousLoc(this->currentLoc.latitude, this->currentLoc.longitude, this->currentLoc.altitude);
	this->setCurrentLoc(msg.currentLatitude, msg.currentLongitude, msg.currentAltitude);
	
	//Calculate actual Cardinal Bearing
	double numerator = (this->currentLoc.latitude - this->previousLoc.latitude);
	double denominator = (this->currentLoc.longitude - this->previousLoc.longitude);
	double angle = atan2(numerator*DELTA_LAT_TO_METERS,denominator*DELTA_LON_TO_METERS)*180/PI;

	if (this->currentLoc.latitude != this->previousLoc.latitude && this->currentLoc.longitude != this->previousLoc.longitude)
	{ 
			this->setCurrentBearing(toCardinal(angle));
	}
	else this->setCurrentBearing(0.0);

	// Update everything else
	this->setTargetBearing(msg.targetBearing);
	this->setSpeed(msg.groundSpeed);
	this->updateTime();
}

/* accessor functions */
int AU_UAV_ROS::PlaneObject::getID(void) const {
	return this->id;
}

AU_UAV_ROS::coordinate AU_UAV_ROS::PlaneObject::getPreviousLoc(void) const {
	return this->previousLoc;
}

AU_UAV_ROS::coordinate AU_UAV_ROS::PlaneObject::getCurrentLoc(void) const {
	return this->currentLoc;
}

double AU_UAV_ROS::PlaneObject::getTargetBearing(void) const {
	return this->targetBearing;
}

double AU_UAV_ROS::PlaneObject::getCurrentBearing(void) const {
	return this->currentBearing;
}
	
double AU_UAV_ROS::PlaneObject::getSpeed(void) const {
	return this->speed;
}

double AU_UAV_ROS::PlaneObject::getLastUpdateTime(void) const {
	return this->lastUpdateTime;
}

AU_UAV_ROS::waypoint AU_UAV_ROS::PlaneObject::getDestination(void) const {
	return this->destination;
}

/* Find distance between this plane and another plane, returns in meters */
double AU_UAV_ROS::PlaneObject::findDistance(const AU_UAV_ROS::PlaneObject& plane) const {
	return this->findDistance(plane.currentLoc.latitude, plane.currentLoc.longitude);
}



/* Find distance between this plane and another pair of coordinates, 
returns value in meters */
double AU_UAV_ROS::PlaneObject::findDistance(double lat2, double lon2) const {
	double xdiff = (lon2 - this->currentLoc.longitude)*DELTA_LON_TO_METERS;
	double ydiff = (lat2 - this->currentLoc.latitude)*DELTA_LAT_TO_METERS;

	return sqrt(pow(xdiff, 2) + pow(ydiff, 2));
}

/* Find Cartesian angle between this plane and another plane, using this plane
as the origin */
//Returns angle in degrees, in range [-180 to 180] in cartesian coordinate plane
double AU_UAV_ROS::PlaneObject::findAngle(const AU_UAV_ROS::PlaneObject& plane) const {
	return this->findAngle(plane.currentLoc.latitude, plane.currentLoc.longitude);
}

/* Find Cartesian angle between this plane and another plane's latitude/longitude 
using this plane as the origin */
//Returns angle in degrees, in range [-180 to 180] in cartesian coordinate plane
double AU_UAV_ROS::PlaneObject::findAngle(double lat2, double lon2) const {
	double xdiff = (lon2 - this->currentLoc.longitude)*DELTA_LON_TO_METERS;
	double ydiff = (lat2 - this->currentLoc.latitude)*DELTA_LAT_TO_METERS;

	//Get angle in degrees, in range [-180 to 180] in cartesian coordinate frame
	double degrees =  atan2(ydiff, xdiff)*180.0/PI;

	//added in an attempt to get test to work
	return degrees;

}

//FIELD METHODS


/*This method will adjust the field of the plane to specifications provided by the arguments
 * TODO:
 * 		DELETE PREVIOUS FIELD
 * 		Enable choosing multiple field setups, this method will currently only call one field type
 */
void AU_UAV_ROS::PlaneObject::setField(int encodedFieldShape, int encodedFieldFunction){

}

/*This method will adjust the field of the plane to a specific field setup
 * TODO:
 * 		DELETE PREVIOUS FIELD
 */
void AU_UAV_ROS::PlaneObject::setField(ForceField  newField){
	planeField = newField;
}

ForceField AU_UAV_ROS::PlaneObject::getField(){
	return this->planeField;
}
/*
double AU_UAV_ROS::PlaneObject::findMyFieldForceMagnitude(fsquared::relativeCoordinates relativePosition){
	return planeField->findFieldForceMagnitude(relativePosition);
}


bool AU_UAV_ROS::PlaneObject::isInMyField(fsquared::relativeCoordinates relativePosition, double fieldAngle){
	return planeField->isrelativeCoordinatesInMyField(relativePosition, fieldAngle);
}
*/


/*Accessor method for planesToAvoid map */
std::map<int, AU_UAV_ROS::PlaneObject> * AU_UAV_ROS::PlaneObject::getMap()	{
	return &planesToAvoid; 		
}

/* 
* 
*Insert plane. Copy by value. If it exists, will update the existing plane.
*After adding plane, will clear its map to prevent infinite loop of planes with maps with planes...
*
* Pass by reference, because the only time it will need to be copied is when plane is created.
* most of the time, plane will be updated
*
*/
void AU_UAV_ROS::PlaneObject::planeIn_updateMap(AU_UAV_ROS::PlaneObject &plane)	{

	
/*	
	std::map<int, AU_UAV_ROS::PlaneObject> ::iterator it;
	//Am I already tracking plane?
	int plane_id = plane.getID();
	it = planesToAvoid.find(plane_id);
	if(it  == planesToAvoid.end() )	{
		//make new entry for plane
		std::pair<int, AU_UAV_ROS::PlaneObject> entry;
		entry.first = plane_id;
		entry.second = plane;	// pass by value
		entry.second.clearMap(); 
		planesToAvoid.insert(entry);	
	}
	else	{
		it->second = plane;	//I think this copies by value... need to test	
	}
	*/
/*	std::pair<std::map<int, AU_UAV_ROS::PlaneObject> ::iterator, bool> present;
	present = planesToAvoid.insert(  
	if(msg.planeID 	
*/

	(*planesToAvoid)[plane.getID()]  = plane;
	plane.clearMap();
}

/*
 * Empties plane's map of other planes which is exerting a force.
 */
void AU_UAV_ROS::PlaneObject::clearMap()	{
	planesToAvoid.clear();
}


/* Ensure plane is not in the map */
void AU_UAV_ROS::PlaneObject::planeOut_updateMap(AU_UAV_ROS::PlaneObject &plane)	{

	//If plane is in map, TAKE IT OUT arggghh
	std::map<int, AU_UAV_ROS::PlaneObject> ::iterator it;
	int plane_id = plane.getID();
	it = planesToAvoid.find(plane_id);
	if(it != planesToAvoid.end())
		planesToAvoid.erase(it);
}

// TODO: Add equality check for force field
AU_UAV_ROS::PlaneObject& AU_UAV_ROS::PlaneObject::operator=(const AU_UAV_ROS::PlaneObject& plane) {
	if(this == &plane)
	        return *this;
	this->id = plane.id;
	this->currentLoc.altitude = plane.currentLoc.altitude;
	this->currentLoc.latitude = plane.currentLoc.latitude;
	this->currentLoc.longitude = plane.currentLoc.longitude;

	this->previousLoc.altitude = plane.previousLoc.altitude;
	this->previousLoc.latitude = plane.previousLoc.latitude;
	this->previousLoc.longitude = plane.previousLoc.longitude;

	this->destination.latitude = plane.destination.latitude;
	this->destination.longitude = plane.destination.longitude;
	this->destination.altitude = plane.destination.latitude;

	this->tempForceWaypoint.altitude = plane.tempForceWaypoint.altitude;
	this->tempForceWaypoint.longitude = plane.tempForceWaypoint.longitude;
	this->tempForceWaypoint.latitude = plane.tempForceWaypoint.latitude;

	this->targetBearing = plane.targetBearing;
	this->currentBearing = plane.currentBearing;

	this->speed = plane.speed;
	this->lastUpdateTime = plane.lastUpdateTime;
	this->collisionRadius = plane.collisionRadius;

	//NEED TO ACCOUNT FOR FIELD TYPE AND MAPPPPP

	//Make shallow copy of the map. 
	this->planesToAvoid = plane.planesToAvoid;
	this->planeField = plane.planeField;
		
	return *this;
}

