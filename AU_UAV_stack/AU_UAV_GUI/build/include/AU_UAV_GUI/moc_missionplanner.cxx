/****************************************************************************
** Meta object code from reading C++ file 'missionplanner.hpp'
**
** Created: Fri May 24 12:24:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/AU_UAV_GUI/missionplanner.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'missionplanner.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MissionPlanner[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      36,   15,   15,   15, 0x0a,
      88,   56,   51,   15, 0x08,
     129,  113,   51,   15, 0x28,
     158,  149,   51,   15, 0x28,
     173,   15,   51,   15, 0x28,
     191,  184,   15,   15, 0x08,
     230,  184,   15,   15, 0x08,
     266,   15,   15,   15, 0x08,
     277,   15,   15,   15, 0x08,
     293,   15,   15,   15, 0x08,
     304,   15,   15,   15, 0x08,
     329,  323,   15,   15, 0x08,
     358,  353,   15,   15, 0x08,
     393,   15,   15,   15, 0x08,
     404,   15,   15,   15, 0x08,
     434,  428,   15,   15, 0x08,
     454,   15,   15,   15, 0x08,
     465,   15,   15,   15, 0x08,
     484,   15,   15,   15, 0x08,
     500,   15,   15,   15, 0x08,
     521,   15,   15,   15, 0x08,
     545,  539,   15,   15, 0x08,
     572,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MissionPlanner[] = {
    "MissionPlanner\0\0updateFilePreview()\0"
    "saveAltitude()\0bool\0noCancel,silent,resetPreviewBox\0"
    "resetMap(bool,bool,bool)\0noCancel,silent\0"
    "resetMap(bool,bool)\0noCancel\0"
    "resetMap(bool)\0resetMap()\0button\0"
    "missionButtonClicked(QAbstractButton*)\0"
    "fileButtonClicked(QAbstractButton*)\0"
    "saveFile()\0resetFileData()\0editFile()\0"
    "setCenterFromGUI()\0newID\0"
    "updatePlaneIDInMap(int)\0item\0"
    "toggleFlightPath(QListWidgetItem*)\0"
    "editPath()\0generateRandomMission()\0"
    "value\0setMaxStartVal(int)\0loadFile()\0"
    "attachObjectToJS()\0doneWithPlane()\0"
    "showWindConditions()\0saveMapLocation()\0"
    "index\0goToSavedLocation(QString)\0"
    "processEditedLocations()\0"
};

void MissionPlanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MissionPlanner *_t = static_cast<MissionPlanner *>(_o);
        switch (_id) {
        case 0: _t->updateFilePreview(); break;
        case 1: _t->saveAltitude(); break;
        case 2: { bool _r = _t->resetMap((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->resetMap((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->resetMap((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->resetMap();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->missionButtonClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 7: _t->fileButtonClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 8: _t->saveFile(); break;
        case 9: _t->resetFileData(); break;
        case 10: _t->editFile(); break;
        case 11: _t->setCenterFromGUI(); break;
        case 12: _t->updatePlaneIDInMap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->toggleFlightPath((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->editPath(); break;
        case 15: _t->generateRandomMission(); break;
        case 16: _t->setMaxStartVal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->loadFile(); break;
        case 18: _t->attachObjectToJS(); break;
        case 19: _t->doneWithPlane(); break;
        case 20: _t->showWindConditions(); break;
        case 21: _t->saveMapLocation(); break;
        case 22: _t->goToSavedLocation((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->processEditedLocations(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MissionPlanner::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MissionPlanner::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MissionPlanner,
      qt_meta_data_MissionPlanner, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MissionPlanner::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MissionPlanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MissionPlanner::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MissionPlanner))
        return static_cast<void*>(const_cast< MissionPlanner*>(this));
    return QWidget::qt_metacast(_clname);
}

int MissionPlanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
