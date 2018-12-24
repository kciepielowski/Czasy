/****************************************************************************
** Meta object code from reading C++ file 'przyklczasy.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "przyklczasy.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'przyklczasy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Przyklczasy[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      30,   12,   12,   12, 0x08,
      53,   12,   12,   12, 0x08,
      76,   12,   12,   12, 0x08,
      98,   12,   12,   12, 0x08,
     123,   12,   12,   12, 0x08,
     144,   12,   12,   12, 0x08,
     165,   12,   12,   12, 0x08,
     187,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Przyklczasy[] = {
    "Przyklczasy\0\0on_pOK_clicked()\0"
    "on_rPerfectP_clicked()\0on_rPerfectC_clicked()\0"
    "on_rPerfect_clicked()\0on_rContinuous_clicked()\0"
    "on_rSimple_clicked()\0on_rFuture_clicked()\0"
    "on_rPresent_clicked()\0on_rPast_clicked()\0"
};

void Przyklczasy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Przyklczasy *_t = static_cast<Przyklczasy *>(_o);
        switch (_id) {
        case 0: _t->on_pOK_clicked(); break;
        case 1: _t->on_rPerfectP_clicked(); break;
        case 2: _t->on_rPerfectC_clicked(); break;
        case 3: _t->on_rPerfect_clicked(); break;
        case 4: _t->on_rContinuous_clicked(); break;
        case 5: _t->on_rSimple_clicked(); break;
        case 6: _t->on_rFuture_clicked(); break;
        case 7: _t->on_rPresent_clicked(); break;
        case 8: _t->on_rPast_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Przyklczasy::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Przyklczasy::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Przyklczasy,
      qt_meta_data_Przyklczasy, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Przyklczasy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Przyklczasy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Przyklczasy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Przyklczasy))
        return static_cast<void*>(const_cast< Przyklczasy*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Przyklczasy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
