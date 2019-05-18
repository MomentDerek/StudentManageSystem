#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QDebug>
#include "sqlite.h"

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
};

#endif // LOGINWINDOW_H
