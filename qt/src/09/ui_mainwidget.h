/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created: Sat Dec 1 12:21:29 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QSplitter *mainVSplitter;
    QTreeWidget *treeWidget;
    QSplitter *table_list_HSplitter;
    QTableWidget *tableWidget;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(414, 414);
        centralWidget = new QWidget(MainWidget);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setReadOnly(true);

        verticalLayout->addWidget(lineEdit);

        mainVSplitter = new QSplitter(centralWidget);
        mainVSplitter->setObjectName(QString::fromUtf8("mainVSplitter"));
        mainVSplitter->setOrientation(Qt::Vertical);
        mainVSplitter->setChildrenCollapsible(false);
        treeWidget = new QTreeWidget(mainVSplitter);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagens/down.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Items"));
        __qtreewidgetitem->setFont(0, font);
        __qtreewidgetitem->setIcon(0, icon);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        mainVSplitter->addWidget(treeWidget);
        table_list_HSplitter = new QSplitter(mainVSplitter);
        table_list_HSplitter->setObjectName(QString::fromUtf8("table_list_HSplitter"));
        table_list_HSplitter->setOrientation(Qt::Horizontal);
        table_list_HSplitter->setChildrenCollapsible(false);
        tableWidget = new QTableWidget(table_list_HSplitter);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagens/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagens/config.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Serif"));
        font1.setBold(true);
        font1.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setIcon(icon2);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagens/cd_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        __qtablewidgetitem2->setIcon(icon3);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagens/cd_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font3);
        __qtablewidgetitem3->setIcon(icon4);
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagens/ficheiro.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        __qtablewidgetitem4->setIcon(icon5);
        tableWidget->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        table_list_HSplitter->addWidget(tableWidget);
        listWidget = new QListWidget(table_list_HSplitter);
        QBrush brush(QColor(185, 8, 8, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(13, 179, 2, 255));
        brush1.setStyle(Qt::Dense6Pattern);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setBackground(brush1);
        __qlistwidgetitem->setForeground(brush);
        __qlistwidgetitem->setIcon(icon3);
        QBrush brush2(QColor(135, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        QBrush brush3(QColor(255, 219, 73, 255));
        brush3.setStyle(Qt::SolidPattern);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setBackground(brush3);
        __qlistwidgetitem1->setForeground(brush2);
        __qlistwidgetitem1->setIcon(icon4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        table_list_HSplitter->addWidget(listWidget);
        mainVSplitter->addWidget(table_list_HSplitter);

        verticalLayout->addWidget(mainVSplitter);

        MainWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWidget);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 414, 25));
        MainWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWidget);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWidget);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWidget->setStatusBar(statusBar);

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QMainWindow *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWidget", "Linha 1", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = ___qtreewidgetitem->child(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWidget", "Linha 1 Sub 1", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWidget", "Linha 1 Sub 1 Sub 1", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWidget", "Linha 1 Sub 2", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWidget", "Linha 2", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled);

        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWidget", "A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWidget", "B", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWidget", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWidget", "2", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWidget", "1-A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWidget", "1-B", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(1, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWidget", "2-A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(1, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWidget", "2-B", 0, QApplication::UnicodeUTF8));
        tableWidget->setSortingEnabled(__sortingEnabled1);


        const bool __sortingEnabled2 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWidget", "Linha 1", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem->setToolTip(QApplication::translate("MainWidget", "Esta e a linha 1", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWidget", "Linha 2", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ___qlistwidgetitem1->setToolTip(QApplication::translate("MainWidget", "Esta e a linha 2", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        listWidget->setSortingEnabled(__sortingEnabled2);

    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
