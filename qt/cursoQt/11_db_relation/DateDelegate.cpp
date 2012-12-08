#include <QDate>
#include <QApplication>
#include <QLineEdit>

#include "DateDelegate.h"

DateDelegate::DateDelegate(int delegateColumn, QObject *parent)
	: QItemDelegate(parent)
	, m_delegateColumn(delegateColumn)
{
}
// ============= paint:

// Definir opções e exibir o DateDelegate
void DateDelegate::paint(QPainter *painter,
						  const QStyleOptionViewItem &paintOption,
						  const QModelIndex &index) const
{
		 if (index.column() == m_delegateColumn)
		 {
			  QStyleOptionViewItem option(paintOption);
			  option.displayAlignment = Qt::AlignHCenter | Qt::AlignVCenter;

			  QVariant colData = index.data( Qt::DisplayRole );
			  if ( colData.isValid())
				{
					QDate date  ( colData.toDate() );
					drawDisplay(painter, option, option.rect, date.toString("dd/MM/yyyy"));
				}
				else
					drawDisplay(painter, option, option.rect, "");

				 drawFocus(painter, option, option.rect);
			}
		  else
				QItemDelegate::paint(painter, paintOption, index);
				// ou, se derivasse de QSqlRelationalDelegate:
				// QSqlRelationalDelegate::paint(painter, paintOption, index);

}

// ============= sizeHint:

QSize DateDelegate::sizeHint ( const QStyleOptionViewItem & option,
										 const QModelIndex & index ) const
{
	if (index.column() == m_delegateColumn)
	{
		QString text ( index.data(Qt::DisplayRole).toString());
		if ( text.isEmpty())
			text = "00/00/0000";

		int w = option.fontMetrics.width(text) + (option.fontMetrics.width('M')*2);
		w+=  (2 * qApp->style()->pixelMetric(QStyle::PM_FocusFrameHMargin));
		return QSize( w, option.rect.height() );
	}
	else
			return QItemDelegate::sizeHint(option, index);
	// ou, se derivasse de QSqlRelationalDelegate:
	// QSqlRelationalDelegate::paint(painter, paintOption, index);
}

