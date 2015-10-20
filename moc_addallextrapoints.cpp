/****************************************************************************
** Meta object code from reading C++ file 'addallextrapoints.h'
**
** Created: Wed Dec 19 22:43:48 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addallextrapoints.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addallextrapoints.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddAllExtraPoints[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   18,   18,   18, 0x08,
      51,   46,   18,   18, 0x08,
      79,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddAllExtraPoints[] = {
    "AddAllExtraPoints\0\0extraPointsAdded()\0"
    "close()\0text\0enableSubmitButton(QString)\0"
    "addPoints()\0"
};

void AddAllExtraPoints::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddAllExtraPoints *_t = static_cast<AddAllExtraPoints *>(_o);
        switch (_id) {
        case 0: _t->extraPointsAdded(); break;
        case 1: _t->close(); break;
        case 2: _t->enableSubmitButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->addPoints(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddAllExtraPoints::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddAllExtraPoints::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddAllExtraPoints,
      qt_meta_data_AddAllExtraPoints, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddAllExtraPoints::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddAllExtraPoints::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddAllExtraPoints::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddAllExtraPoints))
        return static_cast<void*>(const_cast< AddAllExtraPoints*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddAllExtraPoints::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AddAllExtraPoints::extraPointsAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
