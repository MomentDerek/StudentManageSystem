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

    void CheckUser();

private:
    Ui::LoginWindow *ui;
    void openWindow(int usergroup);
    QString userName;
    QString userPassword;
};

#endif // LOGINWINDOW_H
