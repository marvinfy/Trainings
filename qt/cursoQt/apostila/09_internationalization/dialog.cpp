#include "dialog.h"
#include "ui_dialog.h"

#include <QCloseEvent>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

	ui->label->setText( tr("Sample Text") );
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::closeEvent(QCloseEvent * event)
{
	if ( QMessageBox::question( this, tr("Close"),
								tr("Close whithout save changes?") ,
								QMessageBox::Yes | QMessageBox::No )
		!= QMessageBox::Yes )
	{
		event->ignore();
	}
}

