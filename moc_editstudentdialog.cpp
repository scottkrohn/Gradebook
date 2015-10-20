/****************************************************************************
** Meta object code from reading C++ file 'editstudentdialog.h'
**
** Created: Wed Dec 19 22:43:44 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editstudentdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editstudentdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditStudentDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,
      38,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   18,   18,   18, 0x08,
      70,   18,   18,   18, 0x08,
      90,   18,   18,   18, 0x08,
     111,   18,   18,   18, 0x08,
     134,   18,   18,   18, 0x08,
     155,   18,   18,   18, 0x08,
     167,   18,   18,   18, 0x08,
     174,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditStudentDialog[] = {
    "EditStudentDialog\0\0assignmentEdited()\0"
    "gradebookSaved()\0closeConfirm()\0"
    "addAssignmentSlot()\0editAssignmentSlot()\0"
    "deleteAssignmentSlot()\0addExtraPointsSlot()\0"
    "setEdited()\0save()\0updateStudentInfo()\0"
};

void EditStudentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditStudentDialog *_t = static_cast<EditStudentDialog *>(_o);
        switch (_id) {
        case 0: _t->assignmentEdited(); break;
        case 1: _t->gradebookSaved(); break;
        case 2: _t->closeConfirm(); break;
        case 3: _t->addAssignmentSlot(); break;
        case 4: _t->editAssignmentSlot(); break;
        case 5: _t->deleteAssignmentSlot(); break;
        case 6: _t->addExtraPointsSlot(); break;
        case 7: _t->setEdited(); break;
        case 8: _t->save(); break;
        case 9: _t->updateStudentInfo(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData EditStudentDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditStudentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditStudentDialog,
      qt_meta_data_EditStudentDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditStudentDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditStudentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditStudentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditStudentDialog))
        return static_cast<void*>(const_cast< EditStudentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditStudentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void EditStudentDialog::assignmentEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void EditStudentDialog::gradebookSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
