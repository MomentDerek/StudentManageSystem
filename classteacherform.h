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
    explicit ClassTeacherForm(QString name,QWidget *parent = nullptr);
    ~ClassTeacherForm();

private:
    Ui::ClassTeacherForm *ui;
    QString teacherName;
    int teacherID;
    QString teacherSex;
    QString teacherSubject;

    void InfoClass(QString stuClass);
    void InfoSex(QString stuSex);
    void ScoreClass(QString studClass);
    void ScoreChoose(QString chooseScore);
};

#endif // CLASSTEACHERFORM_H
