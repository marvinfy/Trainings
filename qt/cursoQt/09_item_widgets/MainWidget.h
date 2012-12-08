#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QModelIndex>

namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    Ui::MainWidget *ui;

private slots:
	 void anyViewActivated(const QModelIndex & index);
};

#endif // MAINWIDGET_H
