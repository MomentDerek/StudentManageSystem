#include <QtSql>
#include "editablesqlmodel.h"
#include <QDebug>

EditableSqlModel::EditableSqlModel(QString table,QObject *parent)
    : QSqlQueryModel(parent)
{
    tableName = table;
}

//! [0]
Qt::ItemFlags EditableSqlModel::flags(
        const QModelIndex &index) const
{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);

    flags |= Qt::ItemIsEditable;
    return flags;
}
//! [0]

//! [1]
bool EditableSqlModel::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
    if(value.toString() == ""){
        QMessageBox::warning(nullptr,"违规操作","禁止输入空数据");
        return false;
    }

    QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
    QString id = data(primaryKeyIndex).toString();
    QString columnItem = headerData(index.column(),
                                                Qt::Horizontal, Qt::DisplayRole)
                                         .toString();

    QString querySentence = "update "+tableName+" set "+columnItem+" = '"+value.toString()+"' where id = "+id;
    QSqlQuery query;

    if (!query.exec(querySentence)) {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              query.lastError().text());
    }
    qDebug()<<id;
    qDebug()<<columnItem;
    qDebug()<<querySentence;
    setQuery("select * from "+tableName);
    return true;
}
