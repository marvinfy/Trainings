#include <QtGui>
#include <iostream>

#include "xmlstreamreader.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	 QStringList labels;
    labels << QObject::tr("Terms") << QObject::tr("Pages");

    QTreeWidget treeWidget;
    treeWidget.setHeaderLabels(labels);
    treeWidget.header()->setResizeMode(QHeaderView::Stretch);
    treeWidget.setWindowTitle(QObject::tr("XML Stream Reader"));
    treeWidget.show();

    XmlStreamReader reader(&treeWidget);

	reader.readFile( "in1.xml" );

    return app.exec();
}
