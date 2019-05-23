#ifndef CLASSTEACHERFORM_H
#define CLASSTEACHERFORM_H

#include <QDialog>
#include <vector>
#include <sqlite.h>

namespace Ui {
class ClassTeacherForm;
}

class ClassTeacherForm : public QDialog
{
    Q_OBJECT

public:
    explicit ClassTeacherForm(QString name,int usergroup,QWidget *parent = nullptr);
    ~ClassTeacherForm();

private:
    Ui::ClassTeacherForm *ui;
    int usergroup;
    QString teacherName;
    int teacherID;
    QString teacherSex;
    QString teacherSubject;
    QList<int> classList;

    void InitTeacherInfo(QString name);
    void InitClassInfo(int id);
    void InitUiInfo();

    QString infoClass;
    QString infoSex;
    QString scoreClass;
    QString scoreLine;
    QString scoreChoose;

    void InfoChoose();
    void ScoreChoose();
    void ScoreAdd();
    void StuAdd();
    void StuDel();

};

#endif // CLASSTEACHERFORM_H
