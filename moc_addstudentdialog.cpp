/****************************************************************************
** Meta object code from reading C++ file 'addstudentdialog.h'
**
** Created: Wed Dec 19 22:43:46 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addstudentdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addstudentdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddStudentDialog[] = {

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
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   17,   17,   17, 0x08,
      41,   17,   17,   17, 0x08,
      59,   54,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddStudentDialog[] = {
    "AddStudentDialog\0\0studentAdded()\0"
    "close()\0addStudent()\0text\0"
    "enableSubmitButton(QString)\0"
};

void AddStudentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddStudentDialog *_t = static_cast<AddStudentDialog *>(_o);
        switch (_id) {
        case 0: _t->studentAdded(); break;
        case 1: _t->close(); break;
        case 2: _t->addStudent(); break;
        case 3: _t->enableSubmitButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddStudentDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddStudentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddStudentDialog,
      qt_meta_data_AddStudentDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddStudentDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddStudentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddStudentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddStudentDialog))
        return static_cast<void*>(const_cast< AddStudentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddStudentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AddStudentDialog::studentAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
