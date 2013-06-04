/********************************************************************************
** Form generated from reading UI file 'missionplanner.ui'
**
** Created: Tue May 28 22:42:30 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISSIONPLANNER_H
#define UI_MISSIONPLANNER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MissionPlanner
{
public:
    QGridLayout *gridLayout;
    QLabel *filePreviewLabel;
    QSpinBox *numOfPlanesSpinBox;
    QFrame *line_3;
    QListWidget *visiblePathsList;
    QLabel *numOfPlanesLabel;
    QRadioButton *randomMissionButton;
    QSpinBox *fieldSizeSpinBox;
    QSpinBox *minValSpinBox;
    QPushButton *doneWIthPlaneButton;
    QLabel *latitudeLabel;
    QPushButton *saveFileButton;
    QFrame *line_2;
    QSpinBox *altitudeSpinBox;
    QPushButton *resetMapButton;
    QFrame *line_4;
    QLabel *randomMissionLabel;
    QLineEdit *LatitudeLineEdit;
    QLabel *manualMissionLabel;
    QPushButton *generateMissionButton;
    QLabel *fieldSizeLabel;
    QSpinBox *numOfWPSpinBox;
    QSpinBox *planeIDSpinBox;
    QFrame *line_6;
    QLabel *altitudeLabel;
    QFrame *line;
    QLabel *numOfWPLabel;
    QLabel *planeIDLabel;
    QPlainTextEdit *previewBox;
    QPushButton *goToButton;
    QRadioButton *pathFileButton;
    QLabel *label;
    QLabel *pathVisibleLabel;
    QRadioButton *courseFileButton;
    QSpinBox *maxValSpinBox;
    QRadioButton *manualMissionButton;
    QLabel *minValLabel;
    QLabel *maxValLabel;
    QPushButton *showWindButton;
    QPushButton *loadFileButton;
    QPushButton *editFileButton;
    QPushButton *saveLocationButton;
    QLabel *longitudeLabel;
    QLineEdit *LongitudeLineEdit;
    QPushButton *setCenterButton;
    QComboBox *locationsComboBox;
    QWebView *webView2;
    QFrame *line_5;
    QFrame *line_7;
    QButtonGroup *missionButtonGroup;
    QButtonGroup *fileButtonGroup;

    void setupUi(QWidget *MissionPlanner)
    {
        if (MissionPlanner->objectName().isEmpty())
            MissionPlanner->setObjectName(QString::fromUtf8("MissionPlanner"));
        MissionPlanner->resize(1008, 823);
        MissionPlanner->setAutoFillBackground(false);
        gridLayout = new QGridLayout(MissionPlanner);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        filePreviewLabel = new QLabel(MissionPlanner);
        filePreviewLabel->setObjectName(QString::fromUtf8("filePreviewLabel"));

        gridLayout->addWidget(filePreviewLabel, 0, 0, 1, 3);

        numOfPlanesSpinBox = new QSpinBox(MissionPlanner);
        numOfPlanesSpinBox->setObjectName(QString::fromUtf8("numOfPlanesSpinBox"));
        numOfPlanesSpinBox->setEnabled(false);
        numOfPlanesSpinBox->setMinimum(1);
        numOfPlanesSpinBox->setMaximum(64);
        numOfPlanesSpinBox->setValue(5);

        gridLayout->addWidget(numOfPlanesSpinBox, 33, 16, 1, 1);

        line_3 = new QFrame(MissionPlanner);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 0, 14, 39, 1);

        visiblePathsList = new QListWidget(MissionPlanner);
        visiblePathsList->setObjectName(QString::fromUtf8("visiblePathsList"));

        gridLayout->addWidget(visiblePathsList, 8, 15, 16, 2);

        numOfPlanesLabel = new QLabel(MissionPlanner);
        numOfPlanesLabel->setObjectName(QString::fromUtf8("numOfPlanesLabel"));
        numOfPlanesLabel->setEnabled(false);

        gridLayout->addWidget(numOfPlanesLabel, 33, 15, 1, 1);

        randomMissionButton = new QRadioButton(MissionPlanner);
        missionButtonGroup = new QButtonGroup(MissionPlanner);
        missionButtonGroup->setObjectName(QString::fromUtf8("missionButtonGroup"));
        missionButtonGroup->addButton(randomMissionButton);
        randomMissionButton->setObjectName(QString::fromUtf8("randomMissionButton"));
        randomMissionButton->setChecked(false);

        gridLayout->addWidget(randomMissionButton, 1, 15, 1, 2);

        fieldSizeSpinBox = new QSpinBox(MissionPlanner);
        fieldSizeSpinBox->setObjectName(QString::fromUtf8("fieldSizeSpinBox"));
        fieldSizeSpinBox->setEnabled(false);
        fieldSizeSpinBox->setMinimum(100);
        fieldSizeSpinBox->setMaximum(999999);
        fieldSizeSpinBox->setValue(500);

        gridLayout->addWidget(fieldSizeSpinBox, 34, 16, 1, 1);

        minValSpinBox = new QSpinBox(MissionPlanner);
        minValSpinBox->setObjectName(QString::fromUtf8("minValSpinBox"));
        minValSpinBox->setEnabled(false);
        minValSpinBox->setMaximum(999);
        minValSpinBox->setValue(400);

        gridLayout->addWidget(minValSpinBox, 35, 16, 1, 1);

        doneWIthPlaneButton = new QPushButton(MissionPlanner);
        doneWIthPlaneButton->setObjectName(QString::fromUtf8("doneWIthPlaneButton"));
        doneWIthPlaneButton->setEnabled(true);

        gridLayout->addWidget(doneWIthPlaneButton, 29, 15, 1, 2);

        latitudeLabel = new QLabel(MissionPlanner);
        latitudeLabel->setObjectName(QString::fromUtf8("latitudeLabel"));

        gridLayout->addWidget(latitudeLabel, 38, 0, 1, 1);

        saveFileButton = new QPushButton(MissionPlanner);
        saveFileButton->setObjectName(QString::fromUtf8("saveFileButton"));

        gridLayout->addWidget(saveFileButton, 0, 3, 1, 1);

        line_2 = new QFrame(MissionPlanner);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 30, 15, 1, 2);

        altitudeSpinBox = new QSpinBox(MissionPlanner);
        altitudeSpinBox->setObjectName(QString::fromUtf8("altitudeSpinBox"));
        altitudeSpinBox->setMaximum(999);
        altitudeSpinBox->setValue(200);

        gridLayout->addWidget(altitudeSpinBox, 28, 16, 1, 1);

        resetMapButton = new QPushButton(MissionPlanner);
        resetMapButton->setObjectName(QString::fromUtf8("resetMapButton"));

        gridLayout->addWidget(resetMapButton, 0, 7, 1, 1);

        line_4 = new QFrame(MissionPlanner);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 3, 15, 1, 2);

        randomMissionLabel = new QLabel(MissionPlanner);
        randomMissionLabel->setObjectName(QString::fromUtf8("randomMissionLabel"));
        randomMissionLabel->setEnabled(false);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        randomMissionLabel->setFont(font);

        gridLayout->addWidget(randomMissionLabel, 31, 15, 1, 2);

        LatitudeLineEdit = new QLineEdit(MissionPlanner);
        LatitudeLineEdit->setObjectName(QString::fromUtf8("LatitudeLineEdit"));

        gridLayout->addWidget(LatitudeLineEdit, 38, 1, 1, 1);

        manualMissionLabel = new QLabel(MissionPlanner);
        manualMissionLabel->setObjectName(QString::fromUtf8("manualMissionLabel"));
        manualMissionLabel->setEnabled(true);
        manualMissionLabel->setFont(font);

        gridLayout->addWidget(manualMissionLabel, 26, 15, 1, 2);

        generateMissionButton = new QPushButton(MissionPlanner);
        generateMissionButton->setObjectName(QString::fromUtf8("generateMissionButton"));
        generateMissionButton->setEnabled(false);

        gridLayout->addWidget(generateMissionButton, 38, 15, 1, 2);

        fieldSizeLabel = new QLabel(MissionPlanner);
        fieldSizeLabel->setObjectName(QString::fromUtf8("fieldSizeLabel"));
        fieldSizeLabel->setEnabled(false);

        gridLayout->addWidget(fieldSizeLabel, 34, 15, 1, 1);

        numOfWPSpinBox = new QSpinBox(MissionPlanner);
        numOfWPSpinBox->setObjectName(QString::fromUtf8("numOfWPSpinBox"));
        numOfWPSpinBox->setEnabled(false);
        numOfWPSpinBox->setMinimum(1);
        numOfWPSpinBox->setValue(50);

        gridLayout->addWidget(numOfWPSpinBox, 32, 16, 1, 1);

        planeIDSpinBox = new QSpinBox(MissionPlanner);
        planeIDSpinBox->setObjectName(QString::fromUtf8("planeIDSpinBox"));
        planeIDSpinBox->setEnabled(true);
        planeIDSpinBox->setMaximum(63);

        gridLayout->addWidget(planeIDSpinBox, 27, 16, 1, 1);

        line_6 = new QFrame(MissionPlanner);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 25, 15, 1, 2);

        altitudeLabel = new QLabel(MissionPlanner);
        altitudeLabel->setObjectName(QString::fromUtf8("altitudeLabel"));

        gridLayout->addWidget(altitudeLabel, 28, 15, 1, 1);

        line = new QFrame(MissionPlanner);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 6, 15, 1, 2);

        numOfWPLabel = new QLabel(MissionPlanner);
        numOfWPLabel->setObjectName(QString::fromUtf8("numOfWPLabel"));
        numOfWPLabel->setEnabled(false);

        gridLayout->addWidget(numOfWPLabel, 32, 15, 1, 1);

        planeIDLabel = new QLabel(MissionPlanner);
        planeIDLabel->setObjectName(QString::fromUtf8("planeIDLabel"));
        planeIDLabel->setEnabled(true);

        gridLayout->addWidget(planeIDLabel, 27, 15, 1, 1);

        previewBox = new QPlainTextEdit(MissionPlanner);
        previewBox->setObjectName(QString::fromUtf8("previewBox"));
        previewBox->setReadOnly(true);

        gridLayout->addWidget(previewBox, 1, 0, 6, 13);

        goToButton = new QPushButton(MissionPlanner);
        goToButton->setObjectName(QString::fromUtf8("goToButton"));

        gridLayout->addWidget(goToButton, 24, 15, 1, 2);

        pathFileButton = new QRadioButton(MissionPlanner);
        fileButtonGroup = new QButtonGroup(MissionPlanner);
        fileButtonGroup->setObjectName(QString::fromUtf8("fileButtonGroup"));
        fileButtonGroup->addButton(pathFileButton);
        pathFileButton->setObjectName(QString::fromUtf8("pathFileButton"));

        gridLayout->addWidget(pathFileButton, 4, 15, 1, 2);

        label = new QLabel(MissionPlanner);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 15, 1, 2);

        pathVisibleLabel = new QLabel(MissionPlanner);
        pathVisibleLabel->setObjectName(QString::fromUtf8("pathVisibleLabel"));
        pathVisibleLabel->setFont(font);

        gridLayout->addWidget(pathVisibleLabel, 7, 15, 1, 2);

        courseFileButton = new QRadioButton(MissionPlanner);
        fileButtonGroup->addButton(courseFileButton);
        courseFileButton->setObjectName(QString::fromUtf8("courseFileButton"));
        courseFileButton->setChecked(true);

        gridLayout->addWidget(courseFileButton, 5, 15, 1, 2);

        maxValSpinBox = new QSpinBox(MissionPlanner);
        maxValSpinBox->setObjectName(QString::fromUtf8("maxValSpinBox"));
        maxValSpinBox->setEnabled(false);
        maxValSpinBox->setMinimum(400);
        maxValSpinBox->setMaximum(999);
        maxValSpinBox->setValue(400);

        gridLayout->addWidget(maxValSpinBox, 36, 16, 1, 1);

        manualMissionButton = new QRadioButton(MissionPlanner);
        missionButtonGroup->addButton(manualMissionButton);
        manualMissionButton->setObjectName(QString::fromUtf8("manualMissionButton"));
        manualMissionButton->setChecked(true);

        gridLayout->addWidget(manualMissionButton, 2, 15, 1, 2);

        minValLabel = new QLabel(MissionPlanner);
        minValLabel->setObjectName(QString::fromUtf8("minValLabel"));
        minValLabel->setEnabled(false);

        gridLayout->addWidget(minValLabel, 35, 15, 1, 1);

        maxValLabel = new QLabel(MissionPlanner);
        maxValLabel->setObjectName(QString::fromUtf8("maxValLabel"));
        maxValLabel->setEnabled(false);

        gridLayout->addWidget(maxValLabel, 36, 15, 1, 1);

        showWindButton = new QPushButton(MissionPlanner);
        showWindButton->setObjectName(QString::fromUtf8("showWindButton"));

        gridLayout->addWidget(showWindButton, 0, 8, 1, 1);

        loadFileButton = new QPushButton(MissionPlanner);
        loadFileButton->setObjectName(QString::fromUtf8("loadFileButton"));

        gridLayout->addWidget(loadFileButton, 0, 4, 1, 1);

        editFileButton = new QPushButton(MissionPlanner);
        editFileButton->setObjectName(QString::fromUtf8("editFileButton"));

        gridLayout->addWidget(editFileButton, 0, 5, 1, 1);

        saveLocationButton = new QPushButton(MissionPlanner);
        saveLocationButton->setObjectName(QString::fromUtf8("saveLocationButton"));

        gridLayout->addWidget(saveLocationButton, 38, 7, 1, 1);

        longitudeLabel = new QLabel(MissionPlanner);
        longitudeLabel->setObjectName(QString::fromUtf8("longitudeLabel"));

        gridLayout->addWidget(longitudeLabel, 38, 3, 1, 1);

        LongitudeLineEdit = new QLineEdit(MissionPlanner);
        LongitudeLineEdit->setObjectName(QString::fromUtf8("LongitudeLineEdit"));

        gridLayout->addWidget(LongitudeLineEdit, 38, 4, 1, 1);

        setCenterButton = new QPushButton(MissionPlanner);
        setCenterButton->setObjectName(QString::fromUtf8("setCenterButton"));

        gridLayout->addWidget(setCenterButton, 38, 5, 1, 1);

        locationsComboBox = new QComboBox(MissionPlanner);
        locationsComboBox->setObjectName(QString::fromUtf8("locationsComboBox"));
        locationsComboBox->setEditable(false);
        locationsComboBox->setMaxVisibleItems(10);

        gridLayout->addWidget(locationsComboBox, 38, 8, 1, 1);

        webView2 = new QWebView(MissionPlanner);
        webView2->setObjectName(QString::fromUtf8("webView2"));
        webView2->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webView2, 7, 0, 30, 13);

        line_5 = new QFrame(MissionPlanner);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 38, 6, 1, 1);

        line_7 = new QFrame(MissionPlanner);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_7, 0, 6, 1, 1);


        retranslateUi(MissionPlanner);

        QMetaObject::connectSlotsByName(MissionPlanner);
    } // setupUi

    void retranslateUi(QWidget *MissionPlanner)
    {
        MissionPlanner->setWindowTitle(QApplication::translate("MissionPlanner", "MissionPlanner", 0, QApplication::UnicodeUTF8));
        filePreviewLabel->setText(QApplication::translate("MissionPlanner", "Preview of output file:", 0, QApplication::UnicodeUTF8));
        numOfPlanesLabel->setText(QApplication::translate("MissionPlanner", "Planes", 0, QApplication::UnicodeUTF8));
        randomMissionButton->setText(QApplication::translate("MissionPlanner", "Random Mission", 0, QApplication::UnicodeUTF8));
        fieldSizeSpinBox->setSuffix(QApplication::translate("MissionPlanner", " m2", 0, QApplication::UnicodeUTF8));
        minValSpinBox->setSuffix(QApplication::translate("MissionPlanner", " m", 0, QApplication::UnicodeUTF8));
        doneWIthPlaneButton->setText(QApplication::translate("MissionPlanner", "Done WIth Plane", 0, QApplication::UnicodeUTF8));
        latitudeLabel->setText(QApplication::translate("MissionPlanner", "Latitude:", 0, QApplication::UnicodeUTF8));
        saveFileButton->setText(QApplication::translate("MissionPlanner", "Save File", 0, QApplication::UnicodeUTF8));
        altitudeSpinBox->setSuffix(QApplication::translate("MissionPlanner", " m", 0, QApplication::UnicodeUTF8));
        resetMapButton->setText(QApplication::translate("MissionPlanner", "Reset Map", 0, QApplication::UnicodeUTF8));
        randomMissionLabel->setText(QApplication::translate("MissionPlanner", "Random Mission", 0, QApplication::UnicodeUTF8));
        manualMissionLabel->setText(QApplication::translate("MissionPlanner", "Manual Mission", 0, QApplication::UnicodeUTF8));
        generateMissionButton->setText(QApplication::translate("MissionPlanner", "Generate Mission", 0, QApplication::UnicodeUTF8));
        fieldSizeLabel->setText(QApplication::translate("MissionPlanner", "Field Size:", 0, QApplication::UnicodeUTF8));
        altitudeLabel->setText(QApplication::translate("MissionPlanner", "Altitude", 0, QApplication::UnicodeUTF8));
        numOfWPLabel->setText(QApplication::translate("MissionPlanner", "Waypoints", 0, QApplication::UnicodeUTF8));
        planeIDLabel->setText(QApplication::translate("MissionPlanner", "Plane ID", 0, QApplication::UnicodeUTF8));
        previewBox->setPlainText(QString());
        goToButton->setText(QApplication::translate("MissionPlanner", "Show Markers For Plane", 0, QApplication::UnicodeUTF8));
        pathFileButton->setText(QApplication::translate("MissionPlanner", "Path File", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MissionPlanner", "Options", 0, QApplication::UnicodeUTF8));
        pathVisibleLabel->setText(QApplication::translate("MissionPlanner", "Path Visible:", 0, QApplication::UnicodeUTF8));
        courseFileButton->setText(QApplication::translate("MissionPlanner", "Course File", 0, QApplication::UnicodeUTF8));
        maxValSpinBox->setSuffix(QApplication::translate("MissionPlanner", " m", 0, QApplication::UnicodeUTF8));
        manualMissionButton->setText(QApplication::translate("MissionPlanner", "Manual Mission", 0, QApplication::UnicodeUTF8));
        minValLabel->setText(QApplication::translate("MissionPlanner", "Altitude Min:", 0, QApplication::UnicodeUTF8));
        maxValLabel->setText(QApplication::translate("MissionPlanner", "Altitude Max: ", 0, QApplication::UnicodeUTF8));
        showWindButton->setText(QApplication::translate("MissionPlanner", "Wind Conditions", 0, QApplication::UnicodeUTF8));
        loadFileButton->setText(QApplication::translate("MissionPlanner", "Load File", 0, QApplication::UnicodeUTF8));
        editFileButton->setText(QApplication::translate("MissionPlanner", "Edit File", 0, QApplication::UnicodeUTF8));
        saveLocationButton->setText(QApplication::translate("MissionPlanner", "Save Location", 0, QApplication::UnicodeUTF8));
        longitudeLabel->setText(QApplication::translate("MissionPlanner", "Longitude:", 0, QApplication::UnicodeUTF8));
        setCenterButton->setText(QApplication::translate("MissionPlanner", "Set Center", 0, QApplication::UnicodeUTF8));
        locationsComboBox->clear();
        locationsComboBox->insertItems(0, QStringList()
         << QApplication::translate("MissionPlanner", "Saved Locations", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MissionPlanner", "Edit Locations", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class MissionPlanner: public Ui_MissionPlanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISSIONPLANNER_H
