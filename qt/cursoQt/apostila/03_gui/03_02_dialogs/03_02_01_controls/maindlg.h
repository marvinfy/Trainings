
#ifndef _DLG1_H_
#define _DLG1_H_

#include <QDialog>
#include <QCloseEvent>

class QComboBox;
class QRadioButton;
class QDialogButtonBox;
class QCheckBox;
class QLineEdit;

class MainDlg : public QDialog
{
	Q_OBJECT

	public:
		MainDlg(QWidget * pParent=NULL);

	private slots:
		void _nomeChanged(const QString & text);
		void _accept();
		void _reject();

	// eventos (com funções virtuais):
	protected:
		void closeEvent( QCloseEvent * event );

	// membros de dados:
	private:

		QLineEdit *_m_edNome;
		QRadioButton *_m_rbDivorciado;
		QRadioButton *_m_rbViuvo;
		QRadioButton *_m_rbCasado;
		QRadioButton *_m_rbSolteiro;
		QRadioButton *_m_rbFeminino;
		QRadioButton *_m_rbMasculino;
		QCheckBox *_m_ckbEmail;
		QComboBox *_m_cbUF;
		QDialogButtonBox * _m_buttonBox;

		bool _m_bAccept;
	
};



#endif // ( _DLG1_H_ )

