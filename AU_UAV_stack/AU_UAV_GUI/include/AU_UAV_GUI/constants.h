/***************************************************
 Coder: Jacob Dalton Conaway - jdc0019@auburn.edu
 Reviewer/Tester: Kayla Casteel - klc0025@auburn.edu
 Senior Design - Spring 2013
 Sources are in-line
 ***************************************************/

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QList>
#include <QStringList>
#include <QUrl>
#include <QMessageBox>

//numbers
static const int AUTO_CENTER_DURATION = 5000;
static const int INVALID_PLANE_ID = -1;
static const int TOTAL_NUM_OF_PLANES = 64;
static const int LAT_LONG_NUM_OF_DIGITS = 5;
static const int OTHER_DATA_NUM_OF_DIGITS = 2;
static const int LAT_LONG_FIELD_WIDTH = 0;
static const int OTHER_DATA_FIELD_WIDTH = 0;
static const int ICON_PIXMAP_SIZE = 100;
static const int ICON_CIRCLE_LINE_WIDTH = 2;
static const int TOTAL_NUM_OF_DIRECTIONS = 16;
static const double DEGREES_PER_DIRECTION = 22.5;
static const double DEGREE_SHIFT = 11.25;
static const char FLOAT_FORMATTER = 'f';
static const int NOT_FOUND = -1;
static const int MAX_DIRECTION = 360;
static const int LAT_MIN_VAL = -90;
static const int LAT_MAX_VAL = 90;
static const int LONG_MIN_VAL = -180;
static const int LONG_MAX_VAL = 180;
static const int LAT_LONG_MAX_DEC_DIGITS = 7;
static const int LAT_POS = 0;
static const int LONG_POS = 1;
static const int CIRCLE_X_COORD = 10;
static const int CIRCLE_Y_COORD = 10;
static const int CIRCLE_HEIGHT = 80;
static const int CIRCLE_WIDTH = 80;
static const int DIRECTION_MULTIPLE = 5;
static const int ID_LIST_POS = 0;
static const int LAT_LIST_POS = 1;
static const int LONG_LIST_POS = 2;
static const int ALT_LIST_POS = 3;
static const int LAT_LONG_NUM_OF_DIGITS_FILE = 6;
static const int PLANNER_TAB_INDEX = 1;
static const int FLIGHT_VIZ_INDEX = 0;
static const int NO_PARENT = 0;
static const int MIN_PLANE_ID = 0;
static const int MAX_PLANE_ID = 63;
static const int MIN_ALTITUDE = 0;
static const int ITEMS_PER_LINE = 4;
static const int LOC_TABLE_NUM_OF_COLS = 4;

static const int NAME_COLUMN = 0;
static const int LAT_COLUMN = 1;
static const int LONG_COLUMN = 2;
static const int DELETE_COLUMN = 3;
static const int SEP_LINE_INDEX_1 = 1;
static const int SEP_LINE_INDEX_2 = 3;
static const int DEFAULT_ALTITUDE = 200;
static const int SUB_QUEUE_SIZE = 1000;

//strings
static const QUrl VIZ_MAP_URL = QUrl("qrc:/html/html_files/google_maps.html");
static const QUrl PLANNER_MAP_URL = QUrl(
                                        "qrc:/html/html_files/planner_map.html");
static const QString EDIT_DISCLAIMER =
    "#Note: This file has been manually edited. Parameters and settings listed in comments may no longer be correct.\n\n";
static const QString DISP_PLANE_PREFIX = "Display Plane #";
static const QString PLANE_NUM_PREFIX = "Plane #";
static const QString ALL_PLANES_LABEL = "All Planes";
static const QString POPUP_SELECTOR_TITLE = "Toggle Plane Visibility";
static const QString DEFAULT_NUM_VAL = "0";
static const QString DEFAULT_DIRECTION = "N";
static const QString FLIGHT_VIZ_TAB_NAME = "Flight Visualization";
static const QString PLANNER_TAB_NAME = "Mission Planner";
static const QString NO_ROS_WARNING =
    "It appears that ROS is not running."
    "\n\nPlease restart the application using roslaunch if you wish to use the Flight Visualization tab.";
static const QString NO_ROS_NODE_WARNING =
    "It appears that the AU_UAV_ROS nodes are not all running."
    "\n\nPlease restart the application using roslaunch if you wish to use the Flight Visualization tab.";
static const QString WARNING_TITLE = "Warning!";
static const QString RESET_DATA_WARNING =
    "This will reset all data!\nWould you like to save the current file first?";
static const char FILE_COMMENT_TAG = '#';
static const QString RANDOM_FILE_TAG = "#Randomly";
static const QString PLANE_HEADER_LINE =
    "\n\n#Plane ID: %1\n#Waypoints (Including First): %2\n#Plane ID\tLatitude\tLongitude\tAltitude";
static const QString PLANE_COORD_LINE_COURSE = "\n%1\t\t%2\t%3\t%4";
static const QString PLANE_COORD_LINE_PATH = "\n%1\t\t%2\t%3";
static const QString PLANE_ID_TAG = "#Plane ID\t";
static const QString DEFAULT_FILE_PREVIEW_TEXT =
    "This file will be automatically generated.";
static const QString COURSE_TAG = "course";
static const QString PATH_TAG = "path";
static const QString SAVE_FILE_TITLE = "Save File";
static const QString OPEN_FILE_TITLE = "Open File";
static const QString PATH_DIR_POSTFIX = "/paths";
static const QString COURSE_DIR_POSTFIX = "/courses";
static const QString COURSE_FILE_TYPE = "Course Files (*.course)";
static const QString PATH_FILE_TYPE = "Path Files (*.path)";
static const QString PATH_FILE_EXT = ".path";
static const QString COURSE_FILE_EXT = ".course";
static const char FILE_LINE_DELIM = '\t';
static const QString MAIN_WINDOW_TITLE = "AU UAV GUI";
static const QString ABOUT_TITLE = "About " + MAIN_WINDOW_TITLE;
static const QString SAVE_FILE_WARNING =
    "Unable to open file for saving!\nPlease choose a new file name or try again later.";
static const QString OPEN_FILE_WARNING =
    "Unable to open file!\nPlease choose a new file or try again later.";
static const QString ABOUT_TEXT =
    "AU_UAV_GUI - A GUI for AU_UAV_ROS\n\nCreated by:\nGUI Team: Jacob Conaway, Kayla Casteel"
    "\nROS Team: David Jones, Michael Widick\nSenior Design Spring 2013"
    "\n\nSpecial Thanks To: James Matthew Holt and all of the ATTRACT team"
    "\n\nPlanner Map Markers Provoded By: Maps Icons Collection http://mapicons.nicolasmollet.com";
static const QString LOC_SAVE_ERROR =
    "Unable to save locations file!\nThis saved location will not persist, Please try again later.";
static const QString SAVED_LOC_PATH_POSTFIX =
    "/../AU_UAV_GUI/saved_locations/favs.loc";
static const QString FILE_PARSE_ERROR =
    "Unable to parse file info!\nPlease review the file for errors and try again";
static const QString ENTER_NAME_TITLE = "Enter name";
static const QString ENTER_NAME_TEXT = "Enter name of location";
static const QString LOC_COMBO_BOX_TITLE = "Saved Locations";
static const QString EDIT_LOC_TITLE = "Edit/Delete Locations";
static const QString EMPTY_NAME_ERROR =
    "Blank names are not allowed!\nThe location was not saved!";
static const QString MISSING_LOC_ERROR =
    "Location not found! Please select another location.";
static const QString EDIT_FILE_TITLE = "Edit File";
static const QString DONE_EDITING_TITLE = "Done Editing";
static const QString MISSION_LOADED_TEXT = "Mission Loaded";
static const QString ROS_PKGE_NAME = "AU_UAV_ROS";
static const QString GUI_PACKAGE_NAME = "AU_UAV_GUI";
static const QString SEND_FILE_SRV_NAME = "send_file_path";
static const QString TELEM_TOPIC = "telemetry";
static const QString MARKER_SOURCE_ICON_PATH =
    ":/images/images/miclogo-88x31.png";
static const QStringList DIRECTIONS = QStringList() << "(N)" << "(NNE)"
                                      << "(NE)" << "(ENE)" << "(E)" << "(ESE)" << "(SE)" << "(SSE)" << "(S)"
                                      << "(SSW)" << "(SW)" << "(WSW)" << "(W)" << "(WNW)" << "(NW)"
                                      << "(NNW)";
static const QStringList LOC_TABLE_HEADER = QStringList() << "Name"
        << "Latitude" << "Longitude" << "Delete?";
static const QString MAN_FILE_HEADER =
    "#Auburn University ATTRACT Project - AU_UAV_ROS Sub-project\n"
    "#Manually generated course file - GUI Built\n\n" "#Starting waypoints\n"
    "#Plane ID\tLatitude\tLongitude\tAltitude";
static const QString RAND_FILE_HEADER =
    "#Auburn University ATTRACT Project - AU_UAV_ROS Sub-project\n"
    "#Randomly generated course file - GUI Built\n#Settings:\n" "#Number of planes: %1\n"
    "#Field size: %2 meters by %2 meters\n" "#Waypoints per plane: %3\n" "#North-west corner: (%4, %5)\n"
    "#Altitude range: %6 - %7\n\n" "#Starting waypoints\n" "#Plane ID\tLatitude\tLongitude\tAltitude\n";
static const QList<QString> COLORS = QList<QString>() << "#FF0000" << "#FF9900"
                                     << "#FFCC00" << "#FF0066" << "#993366" << "#CC6699" << "#FFFFFF"
                                     << "#00FF00" << "#99CCFF" << "#00FFFF" << "#9900FF" << "#0033CC"
                                     << "#0099CC" << "#CCFF33" << "#FF66CC" << "#FF6600" << "#009999"
                                     << "#990000" << "#CC9900" << "#339966" << "#009933" << "#FFCC66"
                                     << "#99FF99" << "#CC3300" << "#006666" << "#CC66FF" << "#333399"
                                     << "#FF9933" << "#669900" << "#FF5050" << "#000000" << "#993333"
                                     << "#CC99FF" << "#CC3399" << "#660033" << "#CC00CC" << "#0066FF"
                                     << "#99FF66" << "#6600CC" << "#FF3399" << "#B2B2B2" << "#FFFF66"
                                     << "#669999" << "#9966FF" << "#33CC33" << "#333300" << "#CCCC00"
                                     << "#990033" << "#9999FF" << "#00CC99" << "#CC0033" << "#990099"
                                     << "#CC6666" << "#660099" << "#003333" << "#990066" << "#33FFFF"
                                     << "#99FF33" << "#00FF66" << "#996699" << "#663300" << "#66FF00"
                                     << "#0033FF" << "#0000FF";
#endif // CONSTANTS_H
