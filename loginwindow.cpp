#include "adminform.h"
#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "classteacherform.h"


LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->LoginBtn,&QPushButton::clicked,this,&LoginWindow::CheckUser);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::CheckUser()
{
    QSqlQuery query;
    int status = 0;//记录check的状态
    userName = ui->UsernameTxt->toPlainText();
    userPassword = ui->PasswordTxt->toPlainText();

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
                status = 2;
                break;
            }else {
                status = 1;
            }
        }
    }
    switch (status) {//根据check状态来进行错误提示
    case 0:
        QMessageBox::about(this,"登陆失败","用户名或密码错误，请重新输入");
        ui->UsernameTxt->setPlainText("");
        ui->PasswordTxt->setPlainText("");
        break;
    case 1:
        QMessageBox::about(this,"登陆失败","密码错误，请重新输入密码");
        ui->PasswordTxt->setPlainText("");
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
    {
        ClassTeacherForm classteacherForm(userName);
        this->hide();
        classteacherForm.exec();
        this->show();
        break;
    }
    }
}
