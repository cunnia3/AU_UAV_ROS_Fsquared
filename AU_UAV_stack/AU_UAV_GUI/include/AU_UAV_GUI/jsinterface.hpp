/***************************************************
 Coder: Jacob Dalton Conaway - jdc0019@auburn.edu
 Reviewer/Tester: Kayla Casteel - klc0025@auburn.edu
 Senior Design - Spring 2013
 Sources are in-line
 ***************************************************/

#ifndef JSINTERFACE_H
#define JSINTERFACE_H

#include <QObject>

class JSInterface: public QObject
{
    Q_OBJECT

public:
    JSInterface(QObject *parent);
signals:
    void saveAltitude();
    void updateFilePreview();

};
#endif // JSINTERFACE_H
