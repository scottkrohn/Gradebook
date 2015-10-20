/****************************************************************************
** Meta object code from reading C++ file 'editscoresdialog.h'
**
** Created: Sat Dec 29 17:12:36 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "editscoresdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editscoresdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditCommonDialog[] = {

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
      35,   17,   17,   17, 0x08,
      52,   17,   17,   17, 0x08,
      60,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditCommonDialog[] = {
    "EditCommonDialog\0\0gradebookSaved()\0"
    "editAssignment()\0close()\0emitSaved()\0"
};

void EditCommonDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditCommonDialog *_t = static_cast<EditCommonDialog *>(_o);
        switch (_id) {
        case 0: _t->gradebookSaved(); break;
        case 1: _t->editAssignment(); break;
        case 2: _t->close(); break;
        case 3: _t->emitSaved(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData EditCommonDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditCommonDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditCommonDialog,
      qt_meta_data_EditCommonDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditCommonDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditCommonDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditCommonDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditCommonDialog))
        return static_cast<void*>(const_cast< EditCommonDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditCommonDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void EditCommonDialog::gradebookSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_EditScoresDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditScoresDialog[] = {
    "EditScoresDialog\0\0gradebookSaved()\0"
    "save()\0"
};

void EditScoresDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditScoresDialog *_t = static_cast<EditScoresDialog *>(_o);
        switch (_id) {
        case 0: _t->gradebookSaved(); break;
        case 1: _t->save(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData EditScoresDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditScoresDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditScoresDialog,
      qt_meta_data_EditScoresDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditScoresDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditScoresDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditScoresDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditScoresDialog))
        return static_cast<void*>(const_cast< EditScoresDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditScoresDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void EditScoresDialog::gradebookSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
