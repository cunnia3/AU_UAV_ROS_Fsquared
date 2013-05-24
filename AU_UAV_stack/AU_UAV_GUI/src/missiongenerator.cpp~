#include "Google_Maps_CMAKE/missiongenerator.hpp"

// Calculation functions are Matt Holt's. I made minor Qt-specific changes and converted it into an object oriented class.
//TODO:determin minimum field size that will not lock up the application. UI file restricts to 100, to prevent errors.

MissionGenerator::MissionGenerator(double westMostLong, double northMostLat,
                                   int minAltitude, int maxAltitude, int waypointsPerPlane)
{
    this->westMostLong = westMostLong;
    this->northMostLat = northMostLat;
    this->minAltitude = minAltitude;
    this->maxAltitude = maxAltitude;
    this->waypointsPerPlane = waypointsPerPlane;
}

/*
 * distanceBetween(...)
 * Returns the distance in meters between the two waypoints provided. Note that it does take into account
 * the earth's curvature.
 * NOTE: copied from Matt Holt's source code
 */
double MissionGenerator::distanceBetween(struct waypoint first,
        struct waypoint second)
{
    // difference in latitudes in radians
    double lat1 = first.latitude * DEGREES_TO_RADIANS;
    double lat2 = second.latitude * DEGREES_TO_RADIANS;
    double long1 = first.longitude * DEGREES_TO_RADIANS;
    double long2 = second.longitude * DEGREES_TO_RADIANS;
    double deltaLat = lat2 - lat1;
    double deltaLong = long2 - long1;

    // haversine crazy math, should probably be verified further beyond basic testing
    // calculate distance from current position to destination
    double a = pow(sin(deltaLat / 2.0), 2);

    a = a + cos(lat1) * cos(lat2) * pow(sin(deltaLong / 2.0), 2);
    a = 2.0 * asin(sqrt(a));

    return EARTH_RADIUS * a;
}

QList<QList<QVariant> > MissionGenerator::generateCourse(int numberOfPlanes,
        int fieldLength)
{
    struct waypoint planeStarts[numberOfPlanes];

    struct waypoint newPoint;

    int altitudeDifference = maxAltitude - minAltitude;
    QList < QList<QVariant> > allCoords;

    for (int planeid = 0; planeid < numberOfPlanes; planeid++) {
        // latitude is easy to calculate
        newPoint.latitude = northMostLat
                            - METERS_TO_LATITUDE * (rand() % (fieldLength + 1));

        // longitude requires a little more stuff
        int longitudeMeters = rand() % (fieldLength + 1);
        double temp = pow(sin((longitudeMeters / EARTH_RADIUS) / 2.0), 2);

        temp = temp
               / (sin(M_PI / 2.0 - newPoint.latitude * DEGREES_TO_RADIANS)
                  * sin(
                      (M_PI / 2.0)
                      - newPoint.latitude
                      * DEGREES_TO_RADIANS));
        newPoint.longitude = westMostLong
                             + 2.0 * RADIANS_TO_DEGREES * asin(sqrt(temp));

        // altitude is easy too
        newPoint.altitude = minAltitude + rand() % (altitudeDifference + 1);

        // make sure our distance between each other point is enough
        bool isTooClose = false;

        for (int i = 0; (i < planeid) && !isTooClose; i++) {
            if (distanceBetween(newPoint, planeStarts[i]) < BUFFER_SPACE) {
                // subtract a value to put us back where we were and re-roll the dice
                isTooClose = true;

                planeid--;
            }
        }

        if (isTooClose) {
            continue;
        }

        // save our point for later
        planeStarts[planeid] = newPoint;

        // save to list
        QList < QVariant > planeCoords;

        planeCoords.append(QVariant(planeid));
        planeCoords.append(QVariant(newPoint.latitude));
        planeCoords.append(QVariant(newPoint.longitude));
        planeCoords.append(QVariant(newPoint.altitude));
        allCoords.append(planeCoords);
    }

    // for each plane, create a list of values
    for (int planeid = 0; planeid < numberOfPlanes; planeid++) {
        for (int x = 0; x < waypointsPerPlane; x++) {
            // latitude is easy to calculate
            newPoint.latitude = northMostLat
                                - METERS_TO_LATITUDE * (rand() % (fieldLength + 1));

            // longitude requires a little more stuff
            int longitudeMeters = rand() % (fieldLength + 1);
            double temp = pow(sin((longitudeMeters / EARTH_RADIUS) / 2.0), 2);

            temp = temp
                   / (sin(M_PI / 2.0 - newPoint.latitude * DEGREES_TO_RADIANS)
                      * sin(
                          (M_PI / 2.0)
                          - newPoint.latitude
                          * DEGREES_TO_RADIANS));
            newPoint.longitude = westMostLong
                                 + 2.0 * RADIANS_TO_DEGREES * asin(sqrt(temp));

            // altitude is easy too
            newPoint.altitude = minAltitude + rand() % (altitudeDifference + 1);

            QList < QVariant > planeCoords;

            planeCoords.append(QVariant(planeid));
            planeCoords.append(QVariant(newPoint.latitude));
            planeCoords.append(QVariant(newPoint.longitude));
            planeCoords.append(QVariant(newPoint.altitude));
            allCoords.append(planeCoords);
        }
    }

    // return list;
    return allCoords;
}
