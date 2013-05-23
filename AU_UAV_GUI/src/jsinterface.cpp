/***************************************************
 Coder: Jacob Dalton Conaway - jdc0019@auburn.edu
 Reviewer/Tester: Kayla Casteel - klc0025@auburn.edu
 Senior Design - Spring 2013
 Sources are in-line
 ***************************************************/

#include <QDebug>
#include "AU_UAV_GUI/jsinterface.hpp"

//allows us to chose what we expose to javascript
JSInterface::JSInterface(QObject * parent) :
    QObject(parent)
{
}
