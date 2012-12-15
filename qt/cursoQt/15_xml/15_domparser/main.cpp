#include <QtGui>
#include <iostream>

#include "domparser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QStringList labels;
	 labels << QObject::tr("Terms") << QObject::tr("Pages");

    QTreeWidget treeWidget;
    treeWidget.setHeaderLabels(labels);
    treeWidget.header()->setResizeMode(QHeaderView::Stretch);
    treeWidget.setWindowTitle(QObject::tr("DOM Parser"));
    treeWidget.show();

    DomParser parser(&treeWidget);
	 
	 parser.readFile("in1.xml");

    return app.exec();
}
