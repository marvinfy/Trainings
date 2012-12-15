/****************************************************************************
** Meta object code from reading C++ file 'cli_main_dlg.h'
**
** Created: Sat Dec 15 14:20:37 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cli_main_dlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cli_main_dlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_cli_main_dlg[] = {

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
      14,   13,   13,   13, 0x08,
      39,   13,   13,   13, 0x08,
      63,   13,   13,   13, 0x08,
      94,   13,   13,   13, 0x08,
     108,   13,   13,   13, 0x08,
     121,   13,   13,   13, 0x08,
     140,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_cli_main_dlg[] = {
    "cli_main_dlg\0\0on_startButton_clicked()\0"
    "on_stopButton_clicked()\0"
    "on_sendRequestButton_clicked()\0"
    "sendRequest()\0clientRead()\0"
    "connectionClosed()\0errorOccurred()\0"
};

void cli_main_dlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        cli_main_dlg *_t = static_cast<cli_main_dlg *>(_o);
        switch (_id) {
        case 0: _t->on_startButton_clicked(); break;
        case 1: _t->on_stopButton_clicked(); break;
        case 2: _t->on_sendRequestButton_clicked(); break;
        case 3: _t->sendRequest(); break;
        case 4: _t->clientRead(); break;
        case 5: _t->connectionClosed(); break;
        case 6: _t->errorOccurred(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData cli_main_dlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject cli_main_dlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_cli_main_dlg,
      qt_meta_data_cli_main_dlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &cli_main_dlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *cli_main_dlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *cli_main_dlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cli_main_dlg))
        return static_cast<void*>(const_cast< cli_main_dlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int cli_main_dlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
