/****************************************************************************
** Meta object code from reading C++ file 'flightvisualization.hpp'
**
** Created: Fri May 24 12:24:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/AU_UAV_GUI/flightvisualization.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flightvisualization.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FlightVisualization[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      56,   21,   20,   20, 0x0a,
     133,  100,   20,   20, 0x0a,
     293,  167,   20,   20, 0x0a,
     379,  360,   20,   20, 0x08,
     407,   21,   20,   20, 0x08,
     473,  446,   20,   20, 0x08,
     515,  509,   20,   20, 0x08,
     537,  509,   20,   20, 0x08,
     558,  509,   20,   20, 0x08,
     580,  509,   20,   20, 0x08,
     599,  100,   20,   20, 0x08,
     630,   20,   20,   20, 0x08,
     653,  648,   20,   20, 0x08,
     672,   20,   20,   20, 0x08,
     702,  691,   20,   20, 0x08,
     723,   20,   20,   20, 0x08,
     748,  743,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FlightVisualization[] = {
    "FlightVisualization\0\0"
    "latitude,longitude,bearing,planeID\0"
    "updateCoordinates(double,double,double,int)\0"
    "wp_Latitude,wp_Longitude,planeID\0"
    "updateWayPoint(double,double,int)\0"
    "planeID,currentLatitude,currentLongitude,currentAltitude,groundSpeed,t"
    "argetBearing,currentWaypointIndex,distanceToDestination\0"
    "updatePlaneInfo(int,double,double,double,double,double,int,double)\0"
    "latitude,longitude\0setMapCenter(double,double)\0"
    "updateMarker(double,double,double,int)\0"
    "latitude,longitude,planeID\0"
    "updateFlightPath(double,double,int)\0"
    "state\0toggleFlightPath(int)\0"
    "toggleWayPoints(int)\0toggleAutoCenter(int)\0"
    "toggleAutoFit(int)\0setWayPoint(double,double,int)\0"
    "adjustMapCenter()\0okay\0loadFinished(bool)\0"
    "resetFlightPaths()\0comboIndex\0"
    "setCurrentPlane(int)\0showPlaneSelector()\0"
    "item\0togglePlaneVisibility(QListWidgetItem*)\0"
};

void FlightVisualization::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FlightVisualization *_t = static_cast<FlightVisualization *>(_o);
        switch (_id) {
        case 0: _t->updateCoordinates((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->updateWayPoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->updatePlaneInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8]))); break;
        case 3: _t->setMapCenter((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->updateMarker((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->updateFlightPath((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->toggleFlightPath((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->toggleWayPoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->toggleAutoCenter((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->toggleAutoFit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setWayPoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->adjustMapCenter(); break;
        case 12: _t->loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->resetFlightPaths(); break;
        case 14: _t->setCurrentPlane((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->showPlaneSelector(); break;
        case 16: _t->togglePlaneVisibility((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FlightVisualization::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FlightVisualization::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FlightVisualization,
      qt_meta_data_FlightVisualization, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FlightVisualization::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FlightVisualization::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FlightVisualization::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FlightVisualization))
        return static_cast<void*>(const_cast< FlightVisualization*>(this));
    return QWidget::qt_metacast(_clname);
}

int FlightVisualization::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
