/****************************************************************************
** Meta object code from reading C++ file 'gradebookmaingui.h'
**
** Created: Sat Dec 29 17:12:35 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gradebookmaingui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gradebookmaingui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GradebookMain[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      33,   14,   14,   14, 0x08,
      61,   51,   14,   14, 0x08,
      83,   14,   14,   14, 0x08,
     104,   99,   14,   14, 0x08,
     141,   14,   14,   14, 0x08,
     162,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GradebookMain[] = {
    "GradebookMain\0\0addNewGradebook()\0"
    "deleteGradebook()\0classname\0"
    "addClassname(QString)\0openGradebook()\0"
    "item\0openGradebookClick(QListWidgetItem*)\0"
    "loadCurrentClasses()\0displayGradebook()\0"
};

void GradebookMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GradebookMain *_t = static_cast<GradebookMain *>(_o);
        switch (_id) {
        case 0: _t->addNewGradebook(); break;
        case 1: _t->deleteGradebook(); break;
        case 2: _t->addClassname((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->openGradebook(); break;
        case 4: _t->openGradebookClick((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->loadCurrentClasses(); break;
        case 6: _t->displayGradebook(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GradebookMain::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GradebookMain::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GradebookMain,
      qt_meta_data_GradebookMain, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GradebookMain::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GradebookMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GradebookMain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GradebookMain))
        return static_cast<void*>(const_cast< GradebookMain*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GradebookMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
