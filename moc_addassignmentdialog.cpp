/****************************************************************************
** Meta object code from reading C++ file 'addassignmentdialog.h'
**
** Created: Wed Dec 19 22:43:44 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "addassignmentdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addassignmentdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AssignmentDialogBase[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_AssignmentDialogBase[] = {
    "AssignmentDialogBase\0"
};

void AssignmentDialogBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData AssignmentDialogBase::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AssignmentDialogBase::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AssignmentDialogBase,
      qt_meta_data_AssignmentDialogBase, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AssignmentDialogBase::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AssignmentDialogBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AssignmentDialogBase::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AssignmentDialogBase))
        return static_cast<void*>(const_cast< AssignmentDialogBase*>(this));
    return QDialog::qt_metacast(_clname);
}

int AssignmentDialogBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_AddAssignmentDialog[] = {

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
      21,   20,   20,   20, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   20,   20,   20, 0x08,
      60,   55,   20,   20, 0x08,
      88,   20,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddAssignmentDialog[] = {
    "AddAssignmentDialog\0\0assignmentAdded()\0"
    "addAssignment()\0text\0enableSubmitButton(QString)\0"
    "close()\0"
};

void AddAssignmentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddAssignmentDialog *_t = static_cast<AddAssignmentDialog *>(_o);
        switch (_id) {
        case 0: _t->assignmentAdded(); break;
        case 1: _t->addAssignment(); break;
        case 2: _t->enableSubmitButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->close(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddAssignmentDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddAssignmentDialog::staticMetaObject = {
    { &AssignmentDialogBase::staticMetaObject, qt_meta_stringdata_AddAssignmentDialog,
      qt_meta_data_AddAssignmentDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddAssignmentDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddAssignmentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddAssignmentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddAssignmentDialog))
        return static_cast<void*>(const_cast< AddAssignmentDialog*>(this));
    return AssignmentDialogBase::qt_metacast(_clname);
}

int AddAssignmentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AssignmentDialogBase::qt_metacall(_c, _id, _a);
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
void AddAssignmentDialog::assignmentAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_AddIndvAssignmentDialog[] = {

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
      43,   24,   24,   24, 0x08,
      64,   59,   24,   24, 0x08,
      92,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddIndvAssignmentDialog[] = {
    "AddIndvAssignmentDialog\0\0assignmentAdded()\0"
    "addAssignment()\0text\0enableSubmitButton(QString)\0"
    "close()\0"
};

void AddIndvAssignmentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddIndvAssignmentDialog *_t = static_cast<AddIndvAssignmentDialog *>(_o);
        switch (_id) {
        case 0: _t->assignmentAdded(); break;
        case 1: _t->addAssignment(); break;
        case 2: _t->enableSubmitButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->close(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddIndvAssignmentDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddIndvAssignmentDialog::staticMetaObject = {
    { &AssignmentDialogBase::staticMetaObject, qt_meta_stringdata_AddIndvAssignmentDialog,
      qt_meta_data_AddIndvAssignmentDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddIndvAssignmentDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddIndvAssignmentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddIndvAssignmentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddIndvAssignmentDialog))
        return static_cast<void*>(const_cast< AddIndvAssignmentDialog*>(this));
    return AssignmentDialogBase::qt_metacast(_clname);
}

int AddIndvAssignmentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AssignmentDialogBase::qt_metacall(_c, _id, _a);
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
void AddIndvAssignmentDialog::assignmentAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_EditIndvAssignmentDialog[] = {

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
      50,   45,   25,   25, 0x08,
      78,   25,   25,   25, 0x08,
      95,   25,   25,   25, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_EditIndvAssignmentDialog[] = {
    "EditIndvAssignmentDialog\0\0assignmentEdited()\0"
    "text\0enableSubmitButton(QString)\0"
    "editAssignment()\0close()\0"
};

void EditIndvAssignmentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditIndvAssignmentDialog *_t = static_cast<EditIndvAssignmentDialog *>(_o);
        switch (_id) {
        case 0: _t->assignmentEdited(); break;
        case 1: _t->enableSubmitButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->editAssignment(); break;
        case 3: _t->close(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditIndvAssignmentDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditIndvAssignmentDialog::staticMetaObject = {
    { &AssignmentDialogBase::staticMetaObject, qt_meta_stringdata_EditIndvAssignmentDialog,
      qt_meta_data_EditIndvAssignmentDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditIndvAssignmentDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditIndvAssignmentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditIndvAssignmentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditIndvAssignmentDialog))
        return static_cast<void*>(const_cast< EditIndvAssignmentDialog*>(this));
    return AssignmentDialogBase::qt_metacast(_clname);
}

int EditIndvAssignmentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AssignmentDialogBase::qt_metacall(_c, _id, _a);
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
void EditIndvAssignmentDialog::assignmentEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_AddExtraPointsDialog[] = {

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
      22,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   21,   21,   21, 0x08,
      49,   21,   21,   21, 0x08,
      71,   66,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddExtraPointsDialog[] = {
    "AddExtraPointsDialog\0\0extraPointsAdded()\0"
    "close()\0addExtraPoints()\0text\0"
    "enableSubmitButton(QString)\0"
};

void AddExtraPointsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AddExtraPointsDialog *_t = static_cast<AddExtraPointsDialog *>(_o);
        switch (_id) {
        case 0: _t->extraPointsAdded(); break;
        case 1: _t->close(); break;
        case 2: _t->addExtraPoints(); break;
        case 3: _t->enableSubmitButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AddExtraPointsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AddExtraPointsDialog::staticMetaObject = {
    { &AssignmentDialogBase::staticMetaObject, qt_meta_stringdata_AddExtraPointsDialog,
      qt_meta_data_AddExtraPointsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddExtraPointsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddExtraPointsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddExtraPointsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddExtraPointsDialog))
        return static_cast<void*>(const_cast< AddExtraPointsDialog*>(this));
    return AssignmentDialogBase::qt_metacast(_clname);
}

int AddExtraPointsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AssignmentDialogBase::qt_metacall(_c, _id, _a);
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
void AddExtraPointsDialog::extraPointsAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
