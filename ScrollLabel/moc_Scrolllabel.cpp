/****************************************************************************
** Meta object code from reading C++ file 'Scrolllabel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Scrolllabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Scrolllabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MYScrollLabel[] = {

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
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   14,   14,   14, 0x0a,
      55,   14,   14,   14, 0x08,
      65,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MYScrollLabel[] = {
    "MYScrollLabel\0\0currentTextChanged()\0"
    "mysetText(QString)\0metrics()\0startScroll()\0"
};

void MYScrollLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MYScrollLabel *_t = static_cast<MYScrollLabel *>(_o);
        switch (_id) {
        case 0: _t->currentTextChanged(); break;
        case 1: _t->mysetText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->metrics(); break;
        case 3: _t->startScroll(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MYScrollLabel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MYScrollLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MYScrollLabel,
      qt_meta_data_MYScrollLabel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MYScrollLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MYScrollLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MYScrollLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MYScrollLabel))
        return static_cast<void*>(const_cast< MYScrollLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int MYScrollLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void MYScrollLabel::currentTextChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
