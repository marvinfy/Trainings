/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created: Sat 6. Oct 17:17:19 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *clientes_movimento_VSplitter;
    QFrame *clientesFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *clientesLabel;
    QTableView *clientesTable;
    QHBoxLayout *clientesButtonsHLayout;
    QPushButton *clienteDeleteBtn;
    QSpacerItem *clientesButtonsHSpacer;
    QFrame *movimentoFrame;
    QVBoxLayout *verticalLayout;
    QLabel *movimentoLabel;
    QTableView *movimentoTable;
    QHBoxLayout *movimentoButtonsHLayout;
    QGroupBox *movimentoEditGroup;
    QHBoxLayout *horizontalLayout;
    QPushButton *movimentoEditBtn;
    QPushButton *movimentoInsertBtn;
    QPushButton *movimentoDeleteBtn;
    QGroupBox *movimentoNavGroup;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *movimentoNavFirstBtn;
    QPushButton *movimentoNavPrevBtn;
    QPushButton *movimentoNavNextBtn;
    QPushButton *movimentoNavLastBtn;
    QSpacerItem *movimentoButtonsHSpacer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(615, 459);
        verticalLayout_3 = new QVBoxLayout(Widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        clientes_movimento_VSplitter = new QSplitter(Widget);
        clientes_movimento_VSplitter->setObjectName(QString::fromUtf8("clientes_movimento_VSplitter"));
        clientes_movimento_VSplitter->setOrientation(Qt::Vertical);
        clientes_movimento_VSplitter->setChildrenCollapsible(false);
        clientesFrame = new QFrame(clientes_movimento_VSplitter);
        clientesFrame->setObjectName(QString::fromUtf8("clientesFrame"));
        clientesFrame->setFrameShape(QFrame::StyledPanel);
        clientesFrame->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(clientesFrame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 5, -1, 5);
        clientesLabel = new QLabel(clientesFrame);
        clientesLabel->setObjectName(QString::fromUtf8("clientesLabel"));
        clientesLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: bold 10pt \"Verdana\";"));

        verticalLayout_2->addWidget(clientesLabel);

        clientesTable = new QTableView(clientesFrame);
        clientesTable->setObjectName(QString::fromUtf8("clientesTable"));

        verticalLayout_2->addWidget(clientesTable);

        clientesButtonsHLayout = new QHBoxLayout();
        clientesButtonsHLayout->setSpacing(6);
        clientesButtonsHLayout->setObjectName(QString::fromUtf8("clientesButtonsHLayout"));
        clientesButtonsHLayout->setContentsMargins(-1, 0, -1, -1);
        clienteDeleteBtn = new QPushButton(clientesFrame);
        clienteDeleteBtn->setObjectName(QString::fromUtf8("clienteDeleteBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagens/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        clienteDeleteBtn->setIcon(icon);
        clienteDeleteBtn->setDefault(false);

        clientesButtonsHLayout->addWidget(clienteDeleteBtn);

        clientesButtonsHSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        clientesButtonsHLayout->addItem(clientesButtonsHSpacer);


        verticalLayout_2->addLayout(clientesButtonsHLayout);

        clientes_movimento_VSplitter->addWidget(clientesFrame);
        movimentoFrame = new QFrame(clientes_movimento_VSplitter);
        movimentoFrame->setObjectName(QString::fromUtf8("movimentoFrame"));
        movimentoFrame->setFrameShape(QFrame::StyledPanel);
        movimentoFrame->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(movimentoFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 5, -1, 5);
        movimentoLabel = new QLabel(movimentoFrame);
        movimentoLabel->setObjectName(QString::fromUtf8("movimentoLabel"));
        movimentoLabel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"font: bold 10pt \"Verdana\";"));

        verticalLayout->addWidget(movimentoLabel);

        movimentoTable = new QTableView(movimentoFrame);
        movimentoTable->setObjectName(QString::fromUtf8("movimentoTable"));

        verticalLayout->addWidget(movimentoTable);

        movimentoButtonsHLayout = new QHBoxLayout();
        movimentoButtonsHLayout->setSpacing(6);
        movimentoButtonsHLayout->setObjectName(QString::fromUtf8("movimentoButtonsHLayout"));
        movimentoEditGroup = new QGroupBox(movimentoFrame);
        movimentoEditGroup->setObjectName(QString::fromUtf8("movimentoEditGroup"));
        horizontalLayout = new QHBoxLayout(movimentoEditGroup);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 3, 5, 3);
        movimentoEditBtn = new QPushButton(movimentoEditGroup);
        movimentoEditBtn->setObjectName(QString::fromUtf8("movimentoEditBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagens/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoEditBtn->setIcon(icon1);

        horizontalLayout->addWidget(movimentoEditBtn);

        movimentoInsertBtn = new QPushButton(movimentoEditGroup);
        movimentoInsertBtn->setObjectName(QString::fromUtf8("movimentoInsertBtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagens/insert.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoInsertBtn->setIcon(icon2);

        horizontalLayout->addWidget(movimentoInsertBtn);

        movimentoDeleteBtn = new QPushButton(movimentoEditGroup);
        movimentoDeleteBtn->setObjectName(QString::fromUtf8("movimentoDeleteBtn"));
        movimentoDeleteBtn->setIcon(icon);
        movimentoDeleteBtn->setFlat(false);

        horizontalLayout->addWidget(movimentoDeleteBtn);


        movimentoButtonsHLayout->addWidget(movimentoEditGroup);

        movimentoNavGroup = new QGroupBox(movimentoFrame);
        movimentoNavGroup->setObjectName(QString::fromUtf8("movimentoNavGroup"));
        horizontalLayout_2 = new QHBoxLayout(movimentoNavGroup);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 3, 5, 3);
        movimentoNavFirstBtn = new QPushButton(movimentoNavGroup);
        movimentoNavFirstBtn->setObjectName(QString::fromUtf8("movimentoNavFirstBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagens/first.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoNavFirstBtn->setIcon(icon3);

        horizontalLayout_2->addWidget(movimentoNavFirstBtn);

        movimentoNavPrevBtn = new QPushButton(movimentoNavGroup);
        movimentoNavPrevBtn->setObjectName(QString::fromUtf8("movimentoNavPrevBtn"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagens/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoNavPrevBtn->setIcon(icon4);

        horizontalLayout_2->addWidget(movimentoNavPrevBtn);

        movimentoNavNextBtn = new QPushButton(movimentoNavGroup);
        movimentoNavNextBtn->setObjectName(QString::fromUtf8("movimentoNavNextBtn"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagens/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoNavNextBtn->setIcon(icon5);

        horizontalLayout_2->addWidget(movimentoNavNextBtn);

        movimentoNavLastBtn = new QPushButton(movimentoNavGroup);
        movimentoNavLastBtn->setObjectName(QString::fromUtf8("movimentoNavLastBtn"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imagens/last.png"), QSize(), QIcon::Normal, QIcon::Off);
        movimentoNavLastBtn->setIcon(icon6);

        horizontalLayout_2->addWidget(movimentoNavLastBtn);


        movimentoButtonsHLayout->addWidget(movimentoNavGroup);

        movimentoButtonsHSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        movimentoButtonsHLayout->addItem(movimentoButtonsHSpacer);


        verticalLayout->addLayout(movimentoButtonsHLayout);

        clientes_movimento_VSplitter->addWidget(movimentoFrame);

        verticalLayout_3->addWidget(clientes_movimento_VSplitter);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        clientesLabel->setText(QApplication::translate("Widget", "Clientes: ", 0, QApplication::UnicodeUTF8));
        clienteDeleteBtn->setText(QApplication::translate("Widget", "Excluir", 0, QApplication::UnicodeUTF8));
        movimentoLabel->setText(QApplication::translate("Widget", "Movimentos: ", 0, QApplication::UnicodeUTF8));
        movimentoEditGroup->setTitle(QApplication::translate("Widget", " Edi\303\247\303\243o: ", 0, QApplication::UnicodeUTF8));
        movimentoEditBtn->setText(QApplication::translate("Widget", "Editar", 0, QApplication::UnicodeUTF8));
        movimentoInsertBtn->setText(QApplication::translate("Widget", "Inserir", 0, QApplication::UnicodeUTF8));
        movimentoDeleteBtn->setText(QApplication::translate("Widget", "Excluir", 0, QApplication::UnicodeUTF8));
        movimentoNavGroup->setTitle(QApplication::translate("Widget", "Navega\303\247\303\243o: ", 0, QApplication::UnicodeUTF8));
        movimentoNavFirstBtn->setText(QString());
        movimentoNavPrevBtn->setText(QString());
        movimentoNavNextBtn->setText(QString());
        movimentoNavLastBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
