#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QDialog>
#include <sqlite.h>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class AdminForm;
}

class AdminForm : public QDialog
{
    Q_OBJECT

public:
    explicit AdminForm(QWidget *parent = nullptr);
    ~AdminForm();

private:
    Ui::AdminForm *ui;
};

#endif // ADMINFORM_H
