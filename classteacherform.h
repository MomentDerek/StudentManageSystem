#ifndef CLASSTEACHERFORM_H
#define CLASSTEACHERFORM_H

#include <QDialog>

namespace Ui {
class ClassTeacherForm;
}

class ClassTeacherForm : public QDialog
{
    Q_OBJECT

public:
    explicit ClassTeacherForm(QWidget *parent = nullptr);
    ~ClassTeacherForm();

private:
    Ui::ClassTeacherForm *ui;
};

#endif // CLASSTEACHERFORM_H
