#include "loginwindow.h"
#include "ui_loginwindow.h"


LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->LoginBtn,&QPushButton::clicked,this,&LoginWindow::CheckUser);
    connect(ui->HelpBtn,&QPushButton::clicked,this,&LoginWindow::help);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::CheckUser()
{
    QSqlQuery query;
    int status = 0;//记录check的状态
    userName = ui->UsernameTxt->text();
    userPassword = ui->PasswordTxt->text();

    query.exec("select name, usergroup, password from user");
    while(query.next())
    {
        QString name = query.value(0).toString();
        int userGroup = query.value(1).toInt();
        QString password = query.value(2).toString();
        if(userName == name)
        {
            if(userPassword == password)
            {
                openWindow(userGroup);
                status = 3;
                break;
            }else {
                status = 1;
            }
        }
    }
    switch (status) {//根据check状态来进行错误提示
    case 0:
        QMessageBox::about(this,"登陆失败","用户名或密码错误，请重新输入");
        ui->UsernameTxt->setText("");
        ui->PasswordTxt->setText("");
        break;
    case 1:
        QMessageBox::about(this,"登陆失败","密码错误，请重新输入密码");
        ui->PasswordTxt->setText("");
        break;
    default:
        break;
    }
}

void LoginWindow::openWindow(int usergroup)
{
    switch (usergroup) {
    case 0://管理员页面
    {
        AdminForm adminForm;
        this->hide();
        adminForm.exec();
        this->show();
        break;
    }
    case 1://教师页面
    case 2:
    {
        ClassTeacherForm classteacherForm(userName,usergroup);
        this->hide();
        classteacherForm.exec();
        this->show();
        break;
    }
    case 3:{
        StudentForm studentForm(userName);
        this->hide();
        studentForm.exec();
        this->show();
        break;
    }
    }
}

void LoginWindow::help()
{
    QString helpMessage;
    helpMessage = "输入对应的用户名和密码就可以进入对应的界面\n"
                  "初始的管理员账号为admin，密码为123456";
    QMessageBox::about(this,"使用帮助",helpMessage);
}

