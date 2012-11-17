/********************************************************************************
** Form generated from reading ui file 'designer.ui'
**
** Created: Tue 8. Apr 16:21:58 2008
**      by: Qt User Interface Compiler version 4.2.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DESIGNER_H
#define UI_DESIGNER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QLineEdit>

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QComboBox *comboBox;

    void setupUi(QDialog *Dialog)
    {
    Dialog->setObjectName(QString::fromUtf8("Dialog"));
    buttonBox = new QDialogButtonBox(Dialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setGeometry(QRect(30, 240, 341, 32));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);
    lineEdit = new QLineEdit(Dialog);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(20, 100, 113, 22));
    comboBox = new QComboBox(Dialog);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    comboBox->setGeometry(QRect(20, 50, 69, 21));
    comboBox->setEditable(false);
    comboBox->setMinimumContentsLength(10);

    retranslateUi(Dialog);

    QSize size(401, 300);
    size = size.expandedTo(Dialog->minimumSizeHint());
    Dialog->resize(size);

    QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));
    QObject::connect(comboBox, SIGNAL(currentIndexChanged(QString)), lineEdit, SLOT(setText(QString)));

    QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
    Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
    comboBox->clear();
    comboBox->addItem(QApplication::translate("Dialog", "SP", 0, QApplication::UnicodeUTF8));
    comboBox->addItem(QApplication::translate("Dialog", "RJ", 0, QApplication::UnicodeUTF8));
    comboBox->addItem(QApplication::translate("Dialog", "RS", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

#endif // UI_DESIGNER_H
