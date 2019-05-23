#include "studentform.h"
#include "ui_studentform.h"

StudentForm::StudentForm(QString stuName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentForm)
{
    ui->setupUi(this);
    StudentForm::stuName = stuName;
    InitInfo();
}

StudentForm::~StudentForm()
{
    delete ui;
}

void StudentForm::InitInfo()
{
    int stuClass;
    int stuID;
    QString stuSex;
    QString stuBirth;

    ui->WelcomeLable->setText("你好，"+stuName+"。你的个人信息如下：");
    QSqlQuery query;
    if (!query.exec("select * from info where name = '"+stuName+"'")) {
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              query.lastError().text());
    }
    QSqlRecord record;
    query.next();
    record = query.record();
    stuClass = record.value("class").toInt();
    stuID = record.value("id").toInt();
    if(record.value("sex").toInt() == 0)
        stuSex = "男";
    else
        stuSex = "女";
    stuBirth = record.value("birth").toString();
    ui->InfoLable->setText("学号："+QString::number(stuID)+"   性别："+stuSex+"   班级："+QString::number(stuClass)+"班   生日："+stuBirth);
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("score_chinese");
    model->setFilter("id = "+QString::number(stuID));
    model->select();
    ui->Chinese_table->setModel(model);
    ui->Chinese_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->setTable("score_maths");
    model->setFilter("id = "+QString::number(stuID));
    model->select();
    ui->Maths_table->setModel(model);
    ui->Maths_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->setTable("score_english");
    model->setFilter("id = "+QString::number(stuID));
    model->select();
    ui->English_table->setModel(model);
    ui->English_table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

