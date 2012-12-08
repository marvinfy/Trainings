#ifndef TASKEVENT_H
#define TASKEVENT_H

#include <QEvent>

class TaskEvent : public QEvent
{
public:
	 TaskEvent(QString * taskData)
		 : QEvent(m_type)
		 , m_taskData(taskData)
	 {}

	 QString * taskData() { return m_taskData; }
	 static QEvent::Type taskType () { return m_type; }

	private:
	 QString * m_taskData;
	 static const QEvent::Type  m_type = static_cast<QEvent::Type>(QEvent::User+1);
};

#endif // TASKEVENT_H
