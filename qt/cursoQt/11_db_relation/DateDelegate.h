#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QItemDelegate>

class DateDelegate : public QItemDelegate
	// poderia derivar de:  QSqlRelationalDelegate
{
    Q_OBJECT
public:
	 explicit DateDelegate(int delegateColumn, QObject *parent = 0);

	 // virtuais da base:
protected:
	 void paint(QPainter *painter,
								const QStyleOptionViewItem &option,
								const QModelIndex &index) const;
	 QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;

private:
	int m_delegateColumn;

signals:

public slots:

};

#endif // DATEDELEGATE_H
