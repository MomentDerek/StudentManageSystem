#include "classteacherform.h"
#include "ui_classteacherform.h"

ClassTeacherForm::ClassTeacherForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassTeacherForm)
{
    ui->setupUi(this);
}

ClassTeacherForm::~ClassTeacherForm()
{
    delete ui;
}
