/****************************************************************************
** Meta object code from reading C++ file 'mainwidget.h'
**
** Created: Fri Oct 23 13:49:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      43,   11,   11,   11, 0x08,
      67,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     185,  175,   11,   11, 0x08,
     216,   11,   11,   11, 0x08,
     245,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWidget[] = {
    "MainWidget\0\0on_ckbUpperName_stateChanged()\0"
    "on_edName_textChanged()\0on_edMail_textChanged()\0"
    "on_okButton_clicked()\0"
    "on_edNameMinLen_textChanged()\0"
    "on_ckbMailArroba_stateChanged()\0"
    "styleName\0on_cbStyles_activated(QString)\0"
    "on_ckbPalette_stateChanged()\0"
    "updateStatus()\0"
};

const QMetaObject MainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWidget,
      qt_meta_data_MainWidget, 0 }
};

const QMetaObject *MainWidget::metaObject() const
{
    return &staticMetaObject;
}

void *MainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWidget))
        return static_cast<void*>(const_cast< MainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_ckbUpperName_stateChanged(); break;
        case 1: on_edName_textChanged(); break;
        case 2: on_edMail_textChanged(); break;
        case 3: on_okButton_clicked(); break;
        case 4: on_edNameMinLen_textChanged(); break;
        case 5: on_ckbMailArroba_stateChanged(); break;
        case 6: on_cbStyles_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: on_ckbPalette_stateChanged(); break;
        case 8: updateStatus(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
