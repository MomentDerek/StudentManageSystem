/********************************************************************************
** Form generated from reading UI file 'studentform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTFORM_H
#define UI_STUDENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_StudentForm
{
public:
    QTableView *Chinese_table;
    QTableView *Maths_table;
    QTableView *English_table;
    QLabel *WelcomeLable;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *InfoLable;

    void setupUi(QDialog *StudentForm)
    {
        if (StudentForm->objectName().isEmpty())
            StudentForm->setObjectName(QString::fromUtf8("StudentForm"));
        StudentForm->resize(400, 300);
        Chinese_table = new QTableView(StudentForm);
        Chinese_table->setObjectName(QString::fromUtf8("Chinese_table"));
        Chinese_table->setGeometry(QRect(9, 93, 375, 48));
        Maths_table = new QTableView(StudentForm);
        Maths_table->setObjectName(QString::fromUtf8("Maths_table"));
        Maths_table->setGeometry(QRect(10, 164, 375, 48));
        English_table = new QTableView(StudentForm);
        English_table->setObjectName(QString::fromUtf8("English_table"));
        English_table->setGeometry(QRect(10, 235, 375, 48));
        WelcomeLable = new QLabel(StudentForm);
        WelcomeLable->setObjectName(QString::fromUtf8("WelcomeLable"));
        WelcomeLable->setGeometry(QRect(17, 7, 367, 16));
        label_3 = new QLabel(StudentForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(12, 76, 54, 12));
        label_4 = new QLabel(StudentForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(12, 217, 54, 12));
        label_5 = new QLabel(StudentForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(11, 147, 54, 12));
        InfoLable = new QLabel(StudentForm);
        InfoLable->setObjectName(QString::fromUtf8("InfoLable"));
        InfoLable->setGeometry(QRect(18, 26, 370, 36));

        retranslateUi(StudentForm);

        QMetaObject::connectSlotsByName(StudentForm);
    } // setupUi

    void retranslateUi(QDialog *StudentForm)
    {
        StudentForm->setWindowTitle(QApplication::translate("StudentForm", "\345\255\246\347\224\237\344\277\241\346\201\257\347\225\214\351\235\242", nullptr));
        WelcomeLable->setText(QApplication::translate("StudentForm", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("StudentForm", "\350\257\255\346\226\207\346\210\220\347\273\251", nullptr));
        label_4->setText(QApplication::translate("StudentForm", "\350\213\261\350\257\255\346\210\220\347\273\251", nullptr));
        label_5->setText(QApplication::translate("StudentForm", "\346\225\260\345\255\246\346\210\220\347\273\251", nullptr));
        InfoLable->setText(QApplication::translate("StudentForm", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentForm: public Ui_StudentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTFORM_H
