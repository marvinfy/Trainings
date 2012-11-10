#include "aboutdlg.h"
#include "ui_aboutdlg.h"

AboutDlg::AboutDlg(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::AboutDlg)
{
    m_ui->setupUi(this);
}

AboutDlg::~AboutDlg()
{
    delete m_ui;
}

void AboutDlg::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
