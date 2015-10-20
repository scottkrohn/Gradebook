/****************************************************************************
** Meta object code from reading C++ file 'editallassignmentsdialog.h'
**
** Created: Wed Dec 19 22:43:47 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editallassignmentsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editallassignmentsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditAllAssignmentsDialog[] = {

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
      26,   25,   25,   25, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   25,   25,   25, 0x08,
      59,   25,   25,   25, 0x08,
      67,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditAllAssignmentsDialog[] = {
    "EditAllAssignmentsDialog\0\0saveGradebook()\0"
    "editAssignment()\0close()\0emitSaveGradebook()\0"
};

void EditAllAssignmentsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditAllAssignmentsDialog *_t = static_cast<EditAllAssignmentsDialog *>(_o);
        switch (_id) {
        case 0: _t->saveGradebook(); break;
        case 1: _t->editAssignment(); break;
        case 2: _t->close(); break;
        case 3: _t->emitSaveGradebook(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData EditAllAssignmentsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditAllAssignmentsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditAllAssignmentsDialog,
      qt_meta_data_EditAllAssignmentsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditAllAssignmentsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditAllAssignmentsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditAllAssignmentsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditAllAssignmentsDialog))
        return static_cast<void*>(const_cast< EditAllAssignmentsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditAllAssignmentsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void EditAllAssignmentsDialog::saveGradebook()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_EditMultipleAssignments[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x05,
      41,   24,   24,   24, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   56,   24,   24, 0x08,
      87,   24,   24,   24, 0x08,
     104,   24,   24,   24, 0x08,
     112,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditMultipleAssignments[] = {
    "EditMultipleAssignments\0\0saveGradebook()\0"
    "editComplete()\0text\0enableSaveButton(QString)\0"
    "editAssignment()\0close()\0save()\0"
};

void EditMultipleAssignments::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditMultipleAssignments *_t = static_cast<EditMultipleAssignments *>(_o);
        switch (_id) {
        case 0: _t->saveGradebook(); break;
        case 1: _t->editComplete(); break;
        case 2: _t->enableSaveButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->editAssignment(); break;
        case 4: _t->close(); break;
        case 5: _t->save(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditMultipleAssignments::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditMultipleAssignments::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditMultipleAssignments,
      qt_meta_data_EditMultipleAssignments, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditMultipleAssignments::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditMultipleAssignments::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditMultipleAssignments::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditMultipleAssignments))
        return static_cast<void*>(const_cast< EditMultipleAssignments*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditMultipleAssignments::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void EditMultipleAssignments::saveGradebook()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EditMultipleAssignments::editComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
