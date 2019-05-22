#include "classteacherform.h"
#include "ui_classteacherform.h"
#include "sqlite.h"

#include <QStandardItemModel>
ClassTeacherForm::ClassTeacherForm(QString Name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassTeacherForm)
{
    ui->setupUi(this);
    teacherName = Name;
    //读取老师信息
    QSqlQuery query;
    if(!query.exec("select * from teacher "
                   "where name = '"+Name+"'"))
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              query.lastError().text());
    QSqlRecord record;
    while (query.next()) {
        record = query.record();
        teacherID = record.value("id").toInt();
        teacherSex = record.value("sex").toString();
        teacherSubject = record.value("subject").toString();
        qDebug()<<teacherID<<teacherSex<<teacherSubject;
    }
    ui->infoLabel->setText("欢迎回来，"+teacherName+"老师");
    connect(ui->ClassBox_1,&QComboBox::currentTextChanged,this,&ClassTeacherForm::InfoClass);
    connect(ui->SexBox_1,&QComboBox::currentTextChanged,this,&ClassTeacherForm::InfoSex);
    connect(ui->ClassBox_2,&QComboBox::currentTextChanged,this,&ClassTeacherForm::ScoreClass);
    connect(ui->ChooseLine_2,&QLineEdit::textEdited,this,&ClassTeacherForm::ScoreChoose);
    connect(ui->ChooseBox_2,&QComboBox::currentTextChanged,this,&ClassTeacherForm::ScoreChoose);
    connect(ui->AddButton,&QPushButton::clicked,this,&ClassTeacherForm::StuAdd);
    connect(ui->DeleteButton,&QPushButton::clicked,this,&ClassTeacherForm::StuDel);
}

ClassTeacherForm::~ClassTeacherForm()
{
    delete ui;
}

void ClassTeacherForm::InfoClass(QString stuClass)
{

}

void ClassTeacherForm::InfoSex(QString stuSex)
{

}

void ClassTeacherForm::ScoreClass(QString studClass)
{

}

void ClassTeacherForm::ScoreChoose(QString choose)
{

}

void ClassTeacherForm::StuAdd()
{

}

void ClassTeacherForm::StuDel()
{

}



