#ifndef EDITABLESQLMODEL_H
#define EDITABLESQLMODEL_H

#include <QObject>
/*
 * 从官方案例库中修改而来
 * 继承于QSqlQueryModel,赋予其可修改的特性
 * QSqlTableModel中不可用的setQuery方法在这里可用
 * 缺点：需要传入表的名称
 */
#include <QSqlTableModel>
#include <QMessageBox>

class EditableSqlModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    EditableSqlModel(QString table,QObject *parent = nullptr);
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

private:
    QString tableName;
};

#endif // EDITABLESQLMODEL_H
