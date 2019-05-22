#include "sqlite.h"

SQLite::SQLite(){
    if(connect("data.db")){
        QSqlTableModel model;
        model.setTable("user");
        model.setFilter("usergroup = '0'");
        if(!model.select()){
            //判定第一次创建数据库
            QSqlQuery query;
            if (!query.exec("create table user("
                            "id Integer Primary Key AUTOINCREMENT,"
                            "name varchar,"
                            "usergroup Interger,"
                            "password varchar)")) {
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }

            if(!query.exec("create table info("
                           "id Integer Primary Key AUTOINCREMENT,"
                           "name varchar,"
                           "class integer,"
                           "sex integer,"                //1=man, 2=woman
                           "birth varchar)")) {          //储存出生日期
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }

            if(!query.exec("create table teacher("
                           "id Integer Primary Key AUTOINCREMENT,"
                           "name varchar,"
                           "sex integer,"                //1=man, 2=woman
                           "subject varchar)")) {          //储存出生日期
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }

            if(!query.exec("create table score_chinese("
                           "id Integer Primary Key AUTOINCREMENT,"
                           "name Integer,"
                           "finalscore double)")) {
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }

            if(!query.exec("create table score_maths("
                           "id Integer Primary Key AUTOINCREMENT,"
                           "name Integer,"
                           "finalscore double)")) {
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }

            if(!query.exec("create table score_english("
                           "id Integer Primary Key AUTOINCREMENT,"
                           "name Integer,"
                           "finalscore double)")) {
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }
            if(!query.exec("create table relation("     //记录老师id与其教的班级
                           "id Integer ,"
                           "class integer)")) {
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }


            if (!query.exec("insert into user values(000000,'admin','0','123456')")) {
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }

            if (!query.exec("insert into user values(100000,'莫敏聪','1','123456')")) {
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }

            if (!query.exec("insert into user values(100001,'莫敏聪2','2','123456')")) {
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }

            if (!query.exec("insert into user values(200000,'莫敏聪3','3','123456')")) {
                QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                      query.lastError().text());
            }

            query.exec("SELECT * FROM user");
            while (query.next()) {
                QString name = query.value(1).toString();
                QString usergroup = query.value(2).toString();
                qDebug() << name << " " << usergroup;
            }
        }
    }
}

bool SQLite::connect(const QString &dbName){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if(!db.open()){
        QMessageBox::critical(nullptr,QObject::tr("Database Error"),
                              db.lastError().text());
        return false;
    }
    return true;
}

//bool SQLite::AddColumn(QString tableName){
//    QSqlTableModel model;
//    model.setTable(tableName);
//    int row = 0;
//    int columnNum = model.columnCount();
//    int id = columnNum + 1;
//    model.insertColumn(columnNum);
//    model.setData(model.index(row,1),"ww");
//    model.submitAll();
//    return true;
//}

