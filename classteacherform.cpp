#include "classteacherform.h"
#include "ui_classteacherform.h"
#include "sqlite.h"

#include <QStandardItemModel>
ClassTeacherForm::ClassTeacherForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassTeacherForm)
{
    ui->setupUi(this);
    checkInfo("admin");
}

ClassTeacherForm::~ClassTeacherForm()
{
    delete ui;
}

void ClassTeacherForm::checkInfo(QString stdName)
{
    QSqlQuery query;
    if(!query.exec("select * from user inner join info "
                   "on user.id = info.id "
                   "where name = '"+stdName+"'"))
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              query.lastError().text());

    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    queryModel->setQuery(query);


    ui->tableView->setModel(queryModel);
    QHeaderView *header = ui->tableView->horizontalHeader();
    header->setStretchLastSection(true);


    query.next();
    qDebug() << query.value(0).toString() <<endl;
    qDebug() << query.value(1).toString() <<endl;
    qDebug() << query.value(2).toString() <<endl;
    qDebug() << query.value(3).toString() <<endl;
}
