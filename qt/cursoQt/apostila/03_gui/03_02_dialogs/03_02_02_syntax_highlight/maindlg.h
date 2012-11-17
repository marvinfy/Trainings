
#ifndef _DLG1_H_
#define _DLG1_H_

#include <QDialog>
#include <QSyntaxHighlighter>
#include <QStringList>

class QCheckBox;
class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

class QSyntaxHighlighter;
class _SyntaxHighlighter;

class MainDlg : public QDialog
{
	Q_OBJECT

	friend class _SyntaxHighlighter;
	public:
		MainDlg(QWidget * pParent=NULL);

	private slots:
		void _findBtnClicked();
		void _enableFindBtn(const QString & text);

	private:
		QLabel * label;
		QLineEdit * _m_LineEdit;
		QTextEdit * _m_TextEdit;
		_SyntaxHighlighter * _m_HighLighter;
		QCheckBox * _m_ckbCaseSens;
		QPushButton * btnFind;
};

class _SyntaxHighlighter : public QSyntaxHighlighter
{
	friend class MainDlg;
	private:
		_SyntaxHighlighter (QTextDocument * pTextDocument)
			:QSyntaxHighlighter(pTextDocument)
		{}

		// busca palavras considerando ou desprezando maiúsculas/minúsculas;
		Qt::CaseSensitivity _m_cs;
		QStringList _m_WordsList;
		MainDlg * _m_pDlg;

		// redefine virtual da base
		void highlightBlock(const QString &text);
};


#endif // ( _DLG1_H_ )

