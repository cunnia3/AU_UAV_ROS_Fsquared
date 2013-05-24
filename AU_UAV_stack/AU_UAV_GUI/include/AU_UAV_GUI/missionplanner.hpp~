/***************************************************
 Coder: Jacob Dalton Conaway - jdc0019@auburn.edu
 Reviewer/Tester: Kayla Casteel - klc0025@auburn.edu
 Senior Design - Spring 2013
 Sources are in-line
 ***************************************************/

#ifndef MISSIONPLANNER_H
#define MISSIONPLANNER_H

#include <QWidget>
#include <QAbstractButton>
#include <QListWidgetItem>
#include "Google_Maps_CMAKE/jsinterface.hpp"
#include <QPushButton>
#include <QTableWidget>

namespace Ui
{
class MissionPlanner;
}

class MissionPlanner: public QWidget
{
    Q_OBJECT

public:
    explicit MissionPlanner(QWidget *parent = 0);
    ~MissionPlanner();
    void setPackagePath(QString newPath);
public slots:
    void updateFilePreview();
    void saveAltitude();
private slots:
    bool resetMap(bool noCancel = false, bool silent = false, bool resetPreviewBox = true);
    void missionButtonClicked(QAbstractButton * button);
    void fileButtonClicked(QAbstractButton * button);
    void saveFile();
    void resetFileData();
    void editFile();
    void setCenterFromGUI();
    void updatePlaneIDInMap(int newID);
    void toggleFlightPath(QListWidgetItem * item);
    void editPath();
    void generateRandomMission();
    void setMaxStartVal(int value);
    void loadFile();
    void attachObjectToJS();
    void doneWithPlane();
    void showWindConditions();
    void saveMapLocation();
    void goToSavedLocation(QString index);
    void processEditedLocations();
private:
    Ui::MissionPlanner *ui;
    QList<QString> firstPlaneCoords;
    QMap<int, double> altitudes;
    QMap<QString, QList<double> > savedLocations;
    QMap<int, QString> tableIndexToOrigName;
    QString bodyText;
    QString randSettingsHeader;
    QString loadedFileHeader;
    void toggleManualWidgets(bool enabled);
    void toggleRandomWidgets(bool enabled);
    void updateTextField();
    void prepGUI();
    void updatePlanesList();
    void addToPlanesList(int idToAdd);
    void autoEnablePathVisibility(int planeID);
    void populateMapFromQList(QList<QList<QVariant> > planeData);
    QString packagePath;
    QString parseAndLoadCourseFile(QTextStream& inStream);
    void loadFavorites();
    void saveFavorites();
    void showEditLocations();
    JSInterface * jsInterface;
    void populateLocTable(QTableWidget *locTableWidget);
    QTableWidget *locTableWidget;
    void reloadComboBox();
    QSize myGetQTableWidgetSize(QTableWidget *t);
};

#endif // MISSIONPLANNER_H
