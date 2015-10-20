/****************************************************************************
** Meta object code from reading C++ file 'viewclassdialog.h'
**
** Created: Sat Dec 29 17:12:35 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "viewclassdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewclassdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewClassDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      39,   16,   16,   16, 0x08,
      46,   16,   16,   16, 0x08,
      59,   16,   16,   16, 0x08,
      88,   16,   16,   16, 0x08,
      99,   16,   16,   16, 0x08,
     111,   16,   16,   16, 0x08,
     127,   16,   16,   16, 0x08,
     141,   16,   16,   16, 0x08,
     154,   16,   16,   16, 0x08,
     170,   16,   16,   16, 0x08,
     187,   16,   16,   16, 0x08,
     210,   16,   16,   16, 0x08,
     229,   16,   16,   16, 0x08,
     246,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ViewClassDialog[] = {
    "ViewClassDialog\0\0populateStudentList()\0"
    "save()\0silentSave()\0loadRecentlySavedGradebook()\0"
    "closeWin()\0setEdited()\0addAssignment()\0"
    "editStudent()\0addStudent()\0deleteStudent()\0"
    "editAssignment()\0editAssignmentEarned()\0"
    "deleteAssignment()\0addExtraPoints()\0"
    "viewAllGrades()\0"
};

void ViewClassDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewClassDialog *_t = static_cast<ViewClassDialog *>(_o);
        switch (_id) {
        case 0: _t->populateStudentList(); break;
        case 1: _t->save(); break;
        case 2: _t->silentSave(); break;
        case 3: _t->loadRecentlySavedGradebook(); break;
        case 4: _t->closeWin(); break;
        case 5: _t->setEdited(); break;
        case 6: _t->addAssignment(); break;
        case 7: _t->editStudent(); break;
        case 8: _t->addStudent(); break;
        case 9: _t->deleteStudent(); break;
        case 10: _t->editAssignment(); break;
        case 11: _t->editAssignmentEarned(); break;
        case 12: _t->deleteAssignment(); break;
        case 13: _t->addExtraPoints(); break;
        case 14: _t->viewAllGrades(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ViewClassDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViewClassDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ViewClassDialog,
      qt_meta_data_ViewClassDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewClassDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewClassDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewClassDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewClassDialog))
        return static_cast<void*>(const_cast< ViewClassDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ViewClassDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
