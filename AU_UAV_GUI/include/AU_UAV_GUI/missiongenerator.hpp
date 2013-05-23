//Matt Holt's Code

#ifndef MISSIONGENERATOR_H
#define MISSIONGENERATOR_H

#include <QString>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <QVariant>
#include <QList>

//*********************************************************************
//USER DEFINED SETTINGS - you can put as many options as you want in {}
//amount of space in meters between each plane at start
#define BUFFER_SPACE 36.0 //meters
//END USER DEFINED SETTINGS
//*********************************************************************

//1 degree latitude ~= 111.2 km
#define METERS_TO_LATITUDE (1.0/111200.0)
#define EARTH_RADIUS 6371000.0 //meters
#define DEGREES_TO_RADIANS (M_PI/180.0)
#define RADIANS_TO_DEGREES (180.0/M_PI)

class MissionGenerator
{
    struct waypoint {
        double latitude;
        double longitude;
        double altitude;
    };

public:
    MissionGenerator(double westMostLong, double northMostLat, int minAltitude,
                     int maxAltitude, int waypointsPerPlane);
    QList<QList<QVariant> > generateCourse(int numberOfPlanes, int fieldLength);

private:
    double distanceBetween(struct waypoint first, struct waypoint second);
    double westMostLong;
    double northMostLat;
    int minAltitude;
    int maxAltitude;
    int waypointsPerPlane;
};

#endif // MISSIONGENERATOR_H
