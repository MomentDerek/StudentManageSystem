#include "loginwindow.h"
#include "sqlite.h"
#include "classteacherform.h"
#include <QApplication>
#include <QDebug>
/***********************************************************/
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QTableView>
#include <QHeaderView>
/***********************************************************/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    LoginWindow lForm;
    lForm.show();

    SQLite mainSql;


//sql显示示例代码
//    QSqlTableModel model;
//    model.setTable("user");
//    model.select();

//    QSqlQueryModel queryModel;
//    queryModel.setQuery("select * from user inner join info on user.id = info.id where name = 'admin'");

//    QTableView *view = new QTableView;
//    view->setModel(&queryModel);
//    view->setSelectionMode(QAbstractItemView::SingleSelection);
//    view->setSelectionBehavior(QAbstractItemView::SelectRows);
//    view->resizeColumnsToContents();
//    view->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    QHeaderView *header = view->horizontalHeader();
//    header->setStretchLastSection(true);
//    view->show();

    return a.exec();
}
