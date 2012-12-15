/****************************************************************************
** Meta object code from reading C++ file 'DataExchangeSocket.h'
**
** Created: Sat Dec 15 14:54:02 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DataExchangeSocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DataExchangeSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataExchangeSocket[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   20,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   19,   19,   19, 0x0a,
      70,   58,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DataExchangeSocket[] = {
    "DataExchangeSocket\0\0msg\0logMessage(QString)\0"
    "readNewData()\0socketError\0"
    "onError(QAbstractSocket::SocketError)\0"
};

void DataExchangeSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DataExchangeSocket *_t = static_cast<DataExchangeSocket *>(_o);
        switch (_id) {
        case 0: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->readNewData(); break;
        case 2: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DataExchangeSocket::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DataExchangeSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_DataExchangeSocket,
      qt_meta_data_DataExchangeSocket, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataExchangeSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataExchangeSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataExchangeSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataExchangeSocket))
        return static_cast<void*>(const_cast< DataExchangeSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int DataExchangeSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DataExchangeSocket::logMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
