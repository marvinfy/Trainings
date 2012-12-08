/****************************************************************************
** Meta object code from reading C++ file 'Widget.h'
**
** Created: Sat Dec 8 14:46:26 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      44,   38,    7,    7, 0x08,
      89,    7,    7,    7, 0x08,
     119,    7,    7,    7, 0x08,
     151,    7,    7,    7, 0x08,
     183,    7,    7,    7, 0x08,
     216,    7,    7,    7, 0x08,
     249,    7,    7,    7, 0x08,
     282,    7,    7,    7, 0x08,
     330,  316,    7,    7, 0x08,
     366,  316,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0on_clienteDeleteBtn_clicked()\0"
    "index\0on_movimentoTable_doubleClicked(QModelIndex)\0"
    "on_movimentoEditBtn_clicked()\0"
    "on_movimentoInsertBtn_clicked()\0"
    "on_movimentoDeleteBtn_clicked()\0"
    "on_movimentoNavLastBtn_clicked()\0"
    "on_movimentoNavNextBtn_clicked()\0"
    "on_movimentoNavPrevBtn_clicked()\0"
    "on_movimentoNavFirstBtn_clicked()\0"
    "clientesIndex\0atualizaMovimentoTable(QModelIndex)\0"
    "clienteDataChanged(QModelIndex)\0"
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget *_t = static_cast<Widget *>(_o);
        switch (_id) {
        case 0: _t->on_clienteDeleteBtn_clicked(); break;
        case 1: _t->on_movimentoTable_doubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_movimentoEditBtn_clicked(); break;
        case 3: _t->on_movimentoInsertBtn_clicked(); break;
        case 4: _t->on_movimentoDeleteBtn_clicked(); break;
        case 5: _t->on_movimentoNavLastBtn_clicked(); break;
        case 6: _t->on_movimentoNavNextBtn_clicked(); break;
        case 7: _t->on_movimentoNavPrevBtn_clicked(); break;
        case 8: _t->on_movimentoNavFirstBtn_clicked(); break;
        case 9: _t->atualizaMovimentoTable((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->clienteDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
