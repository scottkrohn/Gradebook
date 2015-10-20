/****************************************************************************
** Meta object code from reading C++ file 'deleteallassignmentdialog.h'
**
** Created: Wed Dec 19 22:43:47 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "deleteallassignmentdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deleteallassignmentdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeleteAllAssignmentDialog[] = {

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
      27,   26,   26,   26, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   26,   26,   26, 0x08,
      55,   26,   26,   26, 0x08,
      74,   26,   26,   26, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DeleteAllAssignmentDialog[] = {
    "DeleteAllAssignmentDialog\0\0"
    "assignmentDeleted()\0close()\0"
    "deleteAssignment()\0emitDeleted()\0"
};

void DeleteAllAssignmentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DeleteAllAssignmentDialog *_t = static_cast<DeleteAllAssignmentDialog *>(_o);
        switch (_id) {
        case 0: _t->assignmentDeleted(); break;
        case 1: _t->close(); break;
        case 2: _t->deleteAssignment(); break;
        case 3: _t->emitDeleted(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DeleteAllAssignmentDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DeleteAllAssignmentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DeleteAllAssignmentDialog,
      qt_meta_data_DeleteAllAssignmentDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeleteAllAssignmentDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeleteAllAssignmentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeleteAllAssignmentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeleteAllAssignmentDialog))
        return static_cast<void*>(const_cast< DeleteAllAssignmentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int DeleteAllAssignmentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DeleteAllAssignmentDialog::assignmentDeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_ConfirmDeleteAssignment[] = {

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
      25,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   45,   24,   24, 0x08,
      78,   24,   24,   24, 0x08,
      86,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConfirmDeleteAssignment[] = {
    "ConfirmDeleteAssignment\0\0assignmentDeleted()\0"
    "text\0enableDeleteButton(QString)\0"
    "close()\0deleteAssignment()\0"
};

void ConfirmDeleteAssignment::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConfirmDeleteAssignment *_t = static_cast<ConfirmDeleteAssignment *>(_o);
        switch (_id) {
        case 0: _t->assignmentDeleted(); break;
        case 1: _t->enableDeleteButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->close(); break;
        case 3: _t->deleteAssignment(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConfirmDeleteAssignment::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConfirmDeleteAssignment::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfirmDeleteAssignment,
      qt_meta_data_ConfirmDeleteAssignment, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfirmDeleteAssignment::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfirmDeleteAssignment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfirmDeleteAssignment::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfirmDeleteAssignment))
        return static_cast<void*>(const_cast< ConfirmDeleteAssignment*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfirmDeleteAssignment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ConfirmDeleteAssignment::assignmentDeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
