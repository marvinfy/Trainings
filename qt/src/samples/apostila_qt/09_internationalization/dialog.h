#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui/QDialog>

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

protected:
	void closeEvent(QCloseEvent *);

};

#endif // DIALOG_H
