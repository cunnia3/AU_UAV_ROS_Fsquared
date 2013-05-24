/********************************************************************************
** Form generated from reading UI file 'flightvisualization.ui'
**
** Created: Fri May 24 12:24:00 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLIGHTVISUALIZATION_H
#define UI_FLIGHTVISUALIZATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QFrame *line;
    QFrame *line_2;
    QLCDNumber *latitudeValue;
    QFrame *seperatorLine;
    QLCDNumber *bearingValue;
    QLabel *bearingLabel;
    QLCDNumber *altitudeValue;
    QComboBox *planeSelectorComboBox;
    QLCDNumber *longitudeValue;
    QWebView *webView;
    QPushButton *resetFlightPathButton;
    QCheckBox *flightPathCheckBox;
    QCheckBox *wayPointCheckBox;
    QLCDNumber *groundSpeedValue;
    QLabel *planeInfoLabel;
    QCheckBox *autoCenterCheckBox;
    QLabel *longitudeLabel;
    QLabel *altitudeLabel;
    QPushButton *selectPlaneButton;
    QLabel *latitudeLabel;
    QCheckBox *autoFitCheckBox;
    QLabel *groundSpeedLabel;
    QLabel *wayPointIndexLabel;
    QLCDNumber *distToDestValue;
    QLabel *distToDestLabel;
    QLabel *directionLabel;
    QLCDNumber *wayPointIndexValue;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(837, 656);
        Form->setAutoFillBackground(false);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line = new QFrame(Form);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 4, 18, 1);

        line_2 = new QFrame(Form);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 19, 5, 1, 3);

        latitudeValue = new QLCDNumber(Form);
        latitudeValue->setObjectName(QString::fromUtf8("latitudeValue"));
        latitudeValue->setSmallDecimalPoint(false);
        latitudeValue->setNumDigits(9);

        gridLayout->addWidget(latitudeValue, 6, 5, 1, 3);

        seperatorLine = new QFrame(Form);
        seperatorLine->setObjectName(QString::fromUtf8("seperatorLine"));
        seperatorLine->setFrameShape(QFrame::HLine);
        seperatorLine->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(seperatorLine, 1, 5, 1, 3);

        bearingValue = new QLCDNumber(Form);
        bearingValue->setObjectName(QString::fromUtf8("bearingValue"));
        bearingValue->setSmallDecimalPoint(false);
        bearingValue->setNumDigits(6);
        bearingValue->setDigitCount(6);

        gridLayout->addWidget(bearingValue, 14, 5, 1, 1);

        bearingLabel = new QLabel(Form);
        bearingLabel->setObjectName(QString::fromUtf8("bearingLabel"));

        gridLayout->addWidget(bearingLabel, 13, 5, 1, 3);

        altitudeValue = new QLCDNumber(Form);
        altitudeValue->setObjectName(QString::fromUtf8("altitudeValue"));
        altitudeValue->setSmallDecimalPoint(false);
        altitudeValue->setNumDigits(9);

        gridLayout->addWidget(altitudeValue, 10, 5, 1, 3);

        planeSelectorComboBox = new QComboBox(Form);
        planeSelectorComboBox->setObjectName(QString::fromUtf8("planeSelectorComboBox"));
        planeSelectorComboBox->setEnabled(true);
        QFont font;
        font.setPointSize(11);
        planeSelectorComboBox->setFont(font);
        planeSelectorComboBox->setEditable(false);
        planeSelectorComboBox->setInsertPolicy(QComboBox::InsertAtBottom);
        planeSelectorComboBox->setFrame(true);

        gridLayout->addWidget(planeSelectorComboBox, 3, 5, 1, 3);

        longitudeValue = new QLCDNumber(Form);
        longitudeValue->setObjectName(QString::fromUtf8("longitudeValue"));
        longitudeValue->setSmallDecimalPoint(false);
        longitudeValue->setNumDigits(9);

        gridLayout->addWidget(longitudeValue, 8, 5, 1, 3);

        webView = new QWebView(Form);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webView, 1, 0, 19, 4);

        resetFlightPathButton = new QPushButton(Form);
        resetFlightPathButton->setObjectName(QString::fromUtf8("resetFlightPathButton"));

        gridLayout->addWidget(resetFlightPathButton, 0, 5, 1, 3);

        flightPathCheckBox = new QCheckBox(Form);
        flightPathCheckBox->setObjectName(QString::fromUtf8("flightPathCheckBox"));
        flightPathCheckBox->setChecked(true);

        gridLayout->addWidget(flightPathCheckBox, 0, 0, 1, 1);

        wayPointCheckBox = new QCheckBox(Form);
        wayPointCheckBox->setObjectName(QString::fromUtf8("wayPointCheckBox"));
        wayPointCheckBox->setChecked(true);

        gridLayout->addWidget(wayPointCheckBox, 0, 1, 1, 1);

        groundSpeedValue = new QLCDNumber(Form);
        groundSpeedValue->setObjectName(QString::fromUtf8("groundSpeedValue"));
        groundSpeedValue->setSmallDecimalPoint(false);
        groundSpeedValue->setNumDigits(9);

        gridLayout->addWidget(groundSpeedValue, 12, 5, 1, 3);

        planeInfoLabel = new QLabel(Form);
        planeInfoLabel->setObjectName(QString::fromUtf8("planeInfoLabel"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        planeInfoLabel->setFont(font1);

        gridLayout->addWidget(planeInfoLabel, 2, 5, 1, 4);

        autoCenterCheckBox = new QCheckBox(Form);
        autoCenterCheckBox->setObjectName(QString::fromUtf8("autoCenterCheckBox"));
        autoCenterCheckBox->setEnabled(true);
        autoCenterCheckBox->setChecked(false);

        gridLayout->addWidget(autoCenterCheckBox, 0, 2, 1, 1);

        longitudeLabel = new QLabel(Form);
        longitudeLabel->setObjectName(QString::fromUtf8("longitudeLabel"));

        gridLayout->addWidget(longitudeLabel, 7, 5, 1, 3);

        altitudeLabel = new QLabel(Form);
        altitudeLabel->setObjectName(QString::fromUtf8("altitudeLabel"));
        altitudeLabel->setAutoFillBackground(false);

        gridLayout->addWidget(altitudeLabel, 9, 5, 1, 3);

        selectPlaneButton = new QPushButton(Form);
        selectPlaneButton->setObjectName(QString::fromUtf8("selectPlaneButton"));
        selectPlaneButton->setFont(font);

        gridLayout->addWidget(selectPlaneButton, 4, 5, 1, 3);

        latitudeLabel = new QLabel(Form);
        latitudeLabel->setObjectName(QString::fromUtf8("latitudeLabel"));

        gridLayout->addWidget(latitudeLabel, 5, 5, 1, 3);

        autoFitCheckBox = new QCheckBox(Form);
        autoFitCheckBox->setObjectName(QString::fromUtf8("autoFitCheckBox"));
        autoFitCheckBox->setChecked(true);

        gridLayout->addWidget(autoFitCheckBox, 0, 3, 1, 1);

        groundSpeedLabel = new QLabel(Form);
        groundSpeedLabel->setObjectName(QString::fromUtf8("groundSpeedLabel"));

        gridLayout->addWidget(groundSpeedLabel, 11, 5, 1, 3);

        wayPointIndexLabel = new QLabel(Form);
        wayPointIndexLabel->setObjectName(QString::fromUtf8("wayPointIndexLabel"));

        gridLayout->addWidget(wayPointIndexLabel, 15, 5, 1, 1);

        distToDestValue = new QLCDNumber(Form);
        distToDestValue->setObjectName(QString::fromUtf8("distToDestValue"));
        distToDestValue->setSmallDecimalPoint(false);
        distToDestValue->setNumDigits(9);

        gridLayout->addWidget(distToDestValue, 18, 5, 1, 3);

        distToDestLabel = new QLabel(Form);
        distToDestLabel->setObjectName(QString::fromUtf8("distToDestLabel"));

        gridLayout->addWidget(distToDestLabel, 17, 5, 1, 3);

        directionLabel = new QLabel(Form);
        directionLabel->setObjectName(QString::fromUtf8("directionLabel"));
        QFont font2;
        font2.setPointSize(13);
        directionLabel->setFont(font2);
        directionLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(directionLabel, 14, 6, 1, 3);

        wayPointIndexValue = new QLCDNumber(Form);
        wayPointIndexValue->setObjectName(QString::fromUtf8("wayPointIndexValue"));
        wayPointIndexValue->setSmallDecimalPoint(false);
        wayPointIndexValue->setNumDigits(9);
        wayPointIndexValue->setProperty("intValue", QVariant(0));

        gridLayout->addWidget(wayPointIndexValue, 16, 5, 1, 3);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        bearingLabel->setText(QApplication::translate("Form", "Current Bearing: (\302\260 From N)", 0, QApplication::UnicodeUTF8));
        planeSelectorComboBox->clear();
        planeSelectorComboBox->insertItems(0, QStringList()
         << QApplication::translate("Form", "Select A Plane", 0, QApplication::UnicodeUTF8)
        );
        resetFlightPathButton->setText(QApplication::translate("Form", "Reset Flight Path(s)", 0, QApplication::UnicodeUTF8));
        flightPathCheckBox->setText(QApplication::translate("Form", "Show Flight Paths", 0, QApplication::UnicodeUTF8));
        wayPointCheckBox->setText(QApplication::translate("Form", "Show Waypoints", 0, QApplication::UnicodeUTF8));
        planeInfoLabel->setText(QApplication::translate("Form", "Plane Information", 0, QApplication::UnicodeUTF8));
        autoCenterCheckBox->setText(QApplication::translate("Form", "Auto Center Map", 0, QApplication::UnicodeUTF8));
        longitudeLabel->setText(QApplication::translate("Form", "Longitude: (\302\260 W)", 0, QApplication::UnicodeUTF8));
        altitudeLabel->setText(QApplication::translate("Form", "Altitude: (m)", 0, QApplication::UnicodeUTF8));
        selectPlaneButton->setText(QApplication::translate("Form", "Show Planes", 0, QApplication::UnicodeUTF8));
        latitudeLabel->setText(QApplication::translate("Form", "Latitude: (\302\260 S)", 0, QApplication::UnicodeUTF8));
        autoFitCheckBox->setText(QApplication::translate("Form", "Auto Zoom Map", 0, QApplication::UnicodeUTF8));
        groundSpeedLabel->setText(QApplication::translate("Form", "Ground Speed: (m/s)", 0, QApplication::UnicodeUTF8));
        wayPointIndexLabel->setText(QApplication::translate("Form", "Waypoint Index:", 0, QApplication::UnicodeUTF8));
        distToDestLabel->setText(QApplication::translate("Form", "Distance To Dest: (m)", 0, QApplication::UnicodeUTF8));
        directionLabel->setText(QApplication::translate("Form", "(N)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLIGHTVISUALIZATION_H
