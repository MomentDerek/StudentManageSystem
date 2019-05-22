#ifndef SQLITE_H
#define SQLITE_H

#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <editablesqlmodel.h>

class SQLite
{
public:
    SQLite();
//    bool AddColumn(QString tableName);//在表的最后插入一行
//    bool AddColumn(QString tableName, int id);//在指定id后插入一行
//    bool DeletColumn();
//    bool AddRecord();
//    void CheckTableAll(QString tableName);

//    bool FromFile();

private:
    bool connect(const QString &dbName);
    QString userName;


};

#endif // SQLITE_H
