#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QModelIndex>
#include <QMainWindow>

namespace Ui {
class MainWidget;
}

class MainWidget : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    
private:
    Ui::MainWidget *ui;

private slots:
    void anyViewActivated(const QModelIndex& index);
};

#endif // MAINWIDGET_H
