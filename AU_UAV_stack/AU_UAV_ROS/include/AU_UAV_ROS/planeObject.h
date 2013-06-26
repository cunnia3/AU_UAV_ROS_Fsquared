/* PlaneObject */

#ifndef PLANE_OBJECT_H
#define PLANE_OBJECT_H

#include <map>
#include "AU_UAV_ROS/TelemetryUpdate.h"
#include "AU_UAV_ROS/standardDefs.h"
#include "AU_UAV_ROS/standardFuncs.h"
#include "AU_UAV_ROS/Fsquared.h"
#include "AU_UAV_ROS/ForceField.h"

namespace AU_UAV_ROS {

	class PlaneObject {

        public:
            /* Default constructor. Sets everything to zero. */
            PlaneObject(void);
            
            /* Explicit value constructor: Takes a collision radius and a
            telemetry update and creates a new PlaneObject. */
            PlaneObject(double cRadius, const AU_UAV_ROS::TelemetryUpdate &msg);

	    //Destructor
	    ~PlaneObject();
            
	    /* Mutator functions */
            void setID(int id);
            void setPreviousLoc(double lat, double lon, double alt);
            void setCurrentLoc(double lat, double lon, double alt);
            void setTargetBearing(double tBearing);		/* set bearing to destination */
            void setCurrentBearing(double cBearing); 	/* set current bearing in the air */
            void setSpeed(double speed);
            void setDestination(const AU_UAV_ROS::waypoint &destination);
            void setTempForceWaypoint(const AU_UAV_ROS::waypoint &tempForceWaypoint);

            void updateTime(void);

            /* Update the plane's data members with the information contained within the telemetry update. */
            void update(const AU_UAV_ROS::TelemetryUpdate &msg);

            /* Accessor functions */
            int getID(void) const;
            AU_UAV_ROS::coordinate getPreviousLoc(void) const;
            AU_UAV_ROS::coordinate getCurrentLoc(void) const;
            double getTargetBearing(void) const;
            double getCurrentBearing(void) const;
            double getSpeed(void) const;
            double getLastUpdateTime(void) const;
            AU_UAV_ROS::waypoint getDestination(void) const;
            

            /* Find distance between this plane and another plane */
            double findDistance(const PlaneObject& plane) const;
            /* Find distance between this plane and another plane's latitude/longitude */
            double findDistance(double lat2, double lon2) const;

            /* Find Cartesian angle between this plane and another plane,
	     * with this plane as origin 
		Returns value from [-180 , 180] degrees*/
            double findAngle(const PlaneObject& plane) const;
            /* Find Cartesian angle between this plane and another plane's latitude/longitude 
		Returns value from [-180 , 180] degrees*/
            double findAngle(double lat2, double lon2) const;

            /* Overloaded equality operator */
            PlaneObject& operator=(const PlaneObject& pobj);

            /* Returns true if a plane object is within the cRadius meters of this plane object, false otherwise */
            bool isColliding(const PlaneObject& planeObj) const;






            /*************************************************************************************************
            Fsquared methods
            *************************************************************************************************/

            /*Field Accessor, will return the plane's field*/
            ForceField getField();

            /*This method will adjust the field of the plane to specificiations provided by the arguements*/
            void setField(int encodedFieldShape, int encodedFieldFunction);

            /*This method will adjust the field of the plane to a specific field*/
            void setField(ForceField  newField);


	    //Note = map setters and getters are NOT guaranteed to be thread safe.  

	    /*Accessor method for planesToAvoid map */
            std::map<int, AU_UAV_ROS::PlaneObject> & getMap();

            /* If the plane is not in the map, add it
             * If the plane is in the map, update it
             */
            void planeIn_updateMap(AU_UAV_ROS::PlaneObject plane);

	    /* Clears plane's planesToAvoid map. */
	    void clearMap();

            /* Ensure plane is not in the map */
            void planeOut_updateMap(AU_UAV_ROS::PlaneObject &plane);

        private:
            /* Private data members */
            int id;
            double collisionRadius;
            double targetBearing;		/* get bearing to destination */
            double currentBearing;		/* get current bearing in the air, north is zero and goes to 359 in cw direction */
            double speed;
            double lastUpdateTime;
            AU_UAV_ROS::coordinate previousLoc;	/*used to calculate currentBearing*/
            AU_UAV_ROS::coordinate currentLoc;
            AU_UAV_ROS::waypoint destination;
            AU_UAV_ROS::waypoint tempForceWaypoint; //temporary destination waypoint that is generated from
            										//the fsquared algorithm
            std::map<int, AU_UAV_ROS::PlaneObject>  planesToAvoid; //Planes whose fields "me" is in
        							 	//and are exerting a force on "me"

            ForceField  planeField;		/*Object that handles APF calls*/


    };
};

#endif
