#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QDebug>
#include "sqlite.h"
#include "adminform.h"
#include "classteacherform.h"
#include "studentform.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
private:
    Ui::LoginWindow *ui;
    QString userName;
    QString userPassword;

    void openWindow(int usergroup);
    void CheckUser();
    void help();
};

#endif // LOGINWINDOW_H
