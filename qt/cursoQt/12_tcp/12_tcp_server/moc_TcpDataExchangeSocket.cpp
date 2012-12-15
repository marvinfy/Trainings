/****************************************************************************
** Meta object code from reading C++ file 'TcpDataExchangeSocket.h'
**
** Created: Sat Dec 15 14:20:20 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "TcpDataExchangeSocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TcpDataExchangeSocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpDataExchangeSocket[] = {

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
      27,   23,   22,   22, 0x05,

 // slots: signature, parameters, type, tag, flags
      47,   22,   22,   22, 0x08,
      60,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpDataExchangeSocket[] = {
    "TcpDataExchangeSocket\0\0msg\0"
    "logMessage(QString)\0readClient()\0"
    "onError(QAbstractSocket::SocketError)\0"
};

void TcpDataExchangeSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TcpDataExchangeSocket *_t = static_cast<TcpDataExchangeSocket *>(_o);
        switch (_id) {
        case 0: _t->logMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->readClient(); break;
        case 2: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TcpDataExchangeSocket::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TcpDataExchangeSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_TcpDataExchangeSocket,
      qt_meta_data_TcpDataExchangeSocket, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpDataExchangeSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpDataExchangeSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpDataExchangeSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpDataExchangeSocket))
        return static_cast<void*>(const_cast< TcpDataExchangeSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int TcpDataExchangeSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TcpDataExchangeSocket::logMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
