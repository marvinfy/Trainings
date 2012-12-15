/****************************************************************************
** Meta object code from reading C++ file 'TcpClient.h'
**
** Created: Sat Dec 15 14:53:47 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TcpClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   11,   10,   10, 0x05,
      33,   10,   10,   10, 0x05,
      44,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   10,   10,   10, 0x0a,
      76,   10,   10,   10, 0x0a,
     114,   10,   10,   10, 0x0a,
     133,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TcpClient[] = {
    "TcpClient\0\0data\0newData(QString)\0"
    "tcpError()\0tcpDisconnected()\0readNewData()\0"
    "onError(QAbstractSocket::SocketError)\0"
    "connectionOpened()\0connectionClosed()\0"
};

void TcpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpClient *_t = static_cast<TcpClient *>(_o);
        switch (_id) {
        case 0: _t->newData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->tcpError(); break;
        case 2: _t->tcpDisconnected(); break;
        case 3: _t->readNewData(); break;
        case 4: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 5: _t->connectionOpened(); break;
        case 6: _t->connectionClosed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TcpClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TcpClient::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_TcpClient,
      qt_meta_data_TcpClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpClient))
        return static_cast<void*>(const_cast< TcpClient*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int TcpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void TcpClient::newData(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpClient::tcpError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TcpClient::tcpDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
