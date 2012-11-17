#ifndef QT_TEST_FTP1_H_INC_
#define QT_TEST_FTP1_H_INC_

#include <iostream>
#include <string>
#include <list>

#include <QObject>
#include <QUrlInfo>
#include <QFtp>
#include <QString>

class qt_test_ftp1 : public QObject
{
	Q_OBJECT

	private slots:
		void on_ftp_commandStarted (int id);
		void on_ftp_commandFinished(int id, bool bError);
		
		void on_ftp_listInfo(const QUrlInfo & urinfo );

		// e poderia ter outros "slots"
		// para os "signals" de transferência de arquivo
public:
	signals:
		void endSession(void);

	public:
		qt_test_ftp1();
		
		void beginSession();

		bool error() const { return m_bError; }
		
	private:

		void endConnect(bool bError);
		void endLogin(bool bError);
		void endCD(bool bError);
		void endList(bool bError);
		void endMkdir(bool bError);

		QFtp m_Ftp ;
		QString m_qsInitialDir;

		bool m_bCDFirstTry;
		bool m_bError;

		std::list< std::string > m_lsFiles;
};

#endif // ( QT_TEST_FTP1_H_INC_ )

