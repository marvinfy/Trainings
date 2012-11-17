#ifndef DLG_DATABASE_H

#define DLG_DATABASE_H

#include <QSqlDatabase>
#include <QString>
#include <QList>

class dlg_database
{
public:
    dlg_database();
	bool open();

private:
	void createTables();
};

#endif // DLG_DATABASE_H
