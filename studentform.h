#ifndef STUDENTFORM_H
#define STUDENTFORM_H

#include <QDialog>
#include <sqlite.h>

namespace Ui {
class StudentForm;
}

class StudentForm : public QDialog
{
    Q_OBJECT

public:
    explicit StudentForm(QString stuName,QWidget *parent = nullptr);
    ~StudentForm();

private:
    Ui::StudentForm *ui;
    QString stuName;

    void InitInfo();
};

#endif // STUDENTFORM_H
