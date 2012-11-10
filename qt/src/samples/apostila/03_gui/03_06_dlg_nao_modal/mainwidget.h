#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QtGui/QWidget>
#include <QMessageBox>

namespace Ui
{
    class MainWidgetClass;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();


private:
    Ui::MainWidgetClass *ui;


	// neste exemplo, usaremos uma "MessageBox" personalizada
	// para testar mudança de cores.
	QMessageBox msgBox;

// === slots:

private slots:

// slot para o signal "textChanged" do "lineEdit":
	void on_lineEdit_textChanged();

};

#endif // MAINWIDGET_H
