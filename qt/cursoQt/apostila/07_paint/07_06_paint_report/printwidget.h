#ifndef PrintWidget_H
#define PrintWidget_H

#include <QTextEdit>

#include <QPrinter>
#include <QMap>
class QPaintEvent;

class PrintWidget : public QWidget
{
   Q_OBJECT


public:
	PrintWidget(QWidget * parent);
	~PrintWidget();

	void printToSelectedPrinter();
	void printToPdf();
	void printToWidget();

protected:
	// para imprimir relatorio no textEdit, na printer ou PDF:
	void paintEvent(QPaintEvent * event);

private:
	QPrinter * m_printer;

	enum OutputType { Invalid, Printer, Widget };
	QMap<QString, QString> m_dataMap;

	OutputType m_outputType;

};

#endif // PrintWidget_H
