/********************************************************************************
** Form generated from reading UI file 'classteacherform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSTEACHERFORM_H
#define UI_CLASSTEACHERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassTeacherForm
{
public:
    QTableView *tableView;
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *ClassBox_1;
    QLabel *label;
    QLabel *label_2;
    QComboBox *SexBox_1;
    QGroupBox *ClassTeacherBox;
    QLineEdit *StudentID;
    QLineEdit *StudentName;
    QLineEdit *StudentClass;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *StudentBirth;
    QLabel *label_7;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QComboBox *StudentSex;
    QLabel *infoLabel;
    QGroupBox *SubjectTeacherBox;
    QPushButton *ChooseButton;
    QPushButton *AddButton_2;
    QLineEdit *ChooseLine;
    QLineEdit *AddTest;
    QComboBox *ChooseBox;
    QLabel *label_8;
    QComboBox *ClassBox_Score;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QFrame *line;
    QLabel *label_15;
    QLineEdit *ChooseTest;

    void setupUi(QDialog *ClassTeacherForm)
    {
        if (ClassTeacherForm->objectName().isEmpty())
            ClassTeacherForm->setObjectName(QString::fromUtf8("ClassTeacherForm"));
        ClassTeacherForm->resize(721, 445);
        tableView = new QTableView(ClassTeacherForm);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(280, 10, 431, 411));
        tableView->setCornerButtonEnabled(true);
        tabWidget = new QTabWidget(ClassTeacherForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 261, 131));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        ClassBox_1 = new QComboBox(tab);
        ClassBox_1->setObjectName(QString::fromUtf8("ClassBox_1"));
        ClassBox_1->setGeometry(QRect(60, 10, 181, 31));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 31, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 31, 31));
        SexBox_1 = new QComboBox(tab);
        SexBox_1->addItem(QString());
        SexBox_1->addItem(QString());
        SexBox_1->addItem(QString());
        SexBox_1->setObjectName(QString::fromUtf8("SexBox_1"));
        SexBox_1->setGeometry(QRect(60, 60, 181, 31));
        tabWidget->addTab(tab, QString());
        ClassTeacherBox = new QGroupBox(ClassTeacherForm);
        ClassTeacherBox->setObjectName(QString::fromUtf8("ClassTeacherBox"));
        ClassTeacherBox->setGeometry(QRect(10, 150, 261, 271));
        StudentID = new QLineEdit(ClassTeacherBox);
        StudentID->setObjectName(QString::fromUtf8("StudentID"));
        StudentID->setGeometry(QRect(70, 20, 171, 31));
        StudentName = new QLineEdit(ClassTeacherBox);
        StudentName->setObjectName(QString::fromUtf8("StudentName"));
        StudentName->setGeometry(QRect(70, 60, 171, 31));
        StudentClass = new QLineEdit(ClassTeacherBox);
        StudentClass->setObjectName(QString::fromUtf8("StudentClass"));
        StudentClass->setGeometry(QRect(70, 100, 171, 31));
        label_3 = new QLabel(ClassTeacherBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 31, 31));
        label_4 = new QLabel(ClassTeacherBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 60, 31, 31));
        label_5 = new QLabel(ClassTeacherBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 100, 31, 31));
        label_6 = new QLabel(ClassTeacherBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 140, 31, 31));
        StudentBirth = new QLineEdit(ClassTeacherBox);
        StudentBirth->setObjectName(QString::fromUtf8("StudentBirth"));
        StudentBirth->setGeometry(QRect(70, 180, 171, 31));
        label_7 = new QLabel(ClassTeacherBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 180, 31, 31));
        AddButton = new QPushButton(ClassTeacherBox);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(30, 230, 81, 21));
        DeleteButton = new QPushButton(ClassTeacherBox);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setGeometry(QRect(140, 230, 81, 21));
        StudentSex = new QComboBox(ClassTeacherBox);
        StudentSex->addItem(QString());
        StudentSex->addItem(QString());
        StudentSex->addItem(QString());
        StudentSex->setObjectName(QString::fromUtf8("StudentSex"));
        StudentSex->setGeometry(QRect(69, 141, 172, 31));
        infoLabel = new QLabel(ClassTeacherForm);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setGeometry(QRect(10, 420, 701, 21));
        SubjectTeacherBox = new QGroupBox(ClassTeacherForm);
        SubjectTeacherBox->setObjectName(QString::fromUtf8("SubjectTeacherBox"));
        SubjectTeacherBox->setEnabled(true);
        SubjectTeacherBox->setGeometry(QRect(10, 150, 261, 271));
        ChooseButton = new QPushButton(SubjectTeacherBox);
        ChooseButton->setObjectName(QString::fromUtf8("ChooseButton"));
        ChooseButton->setGeometry(QRect(20, 138, 221, 31));
        AddButton_2 = new QPushButton(SubjectTeacherBox);
        AddButton_2->setObjectName(QString::fromUtf8("AddButton_2"));
        AddButton_2->setGeometry(QRect(20, 230, 221, 31));
        ChooseLine = new QLineEdit(SubjectTeacherBox);
        ChooseLine->setObjectName(QString::fromUtf8("ChooseLine"));
        ChooseLine->setGeometry(QRect(50, 58, 191, 31));
        AddTest = new QLineEdit(SubjectTeacherBox);
        AddTest->setObjectName(QString::fromUtf8("AddTest"));
        AddTest->setGeometry(QRect(65, 190, 181, 31));
        ChooseBox = new QComboBox(SubjectTeacherBox);
        ChooseBox->addItem(QString());
        ChooseBox->addItem(QString());
        ChooseBox->addItem(QString());
        ChooseBox->setObjectName(QString::fromUtf8("ChooseBox"));
        ChooseBox->setGeometry(QRect(50, 100, 61, 31));
        label_8 = new QLabel(SubjectTeacherBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 20, 31, 31));
        ClassBox_Score = new QComboBox(SubjectTeacherBox);
        ClassBox_Score->setObjectName(QString::fromUtf8("ClassBox_Score"));
        ClassBox_Score->setGeometry(QRect(51, 20, 190, 31));
        label_12 = new QLabel(SubjectTeacherBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(6, 59, 41, 31));
        label_13 = new QLabel(SubjectTeacherBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 99, 41, 31));
        label_14 = new QLabel(SubjectTeacherBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 190, 51, 31));
        line = new QFrame(SubjectTeacherBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(15, 172, 236, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_15 = new QLabel(SubjectTeacherBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(116, 97, 41, 33));
        ChooseTest = new QLineEdit(SubjectTeacherBox);
        ChooseTest->setObjectName(QString::fromUtf8("ChooseTest"));
        ChooseTest->setGeometry(QRect(145, 99, 94, 31));

        retranslateUi(ClassTeacherForm);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClassTeacherForm);
    } // setupUi

    void retranslateUi(QDialog *ClassTeacherForm)
    {
        ClassTeacherForm->setWindowTitle(QApplication::translate("ClassTeacherForm", "\347\217\255\344\270\273\344\273\273\347\225\214\351\235\242", nullptr));
        label->setText(QApplication::translate("ClassTeacherForm", "\347\217\255\347\272\247", nullptr));
        label_2->setText(QApplication::translate("ClassTeacherForm", "\346\200\247\345\210\253", nullptr));
        SexBox_1->setItemText(0, QString());
        SexBox_1->setItemText(1, QApplication::translate("ClassTeacherForm", "\347\224\267", nullptr));
        SexBox_1->setItemText(2, QApplication::translate("ClassTeacherForm", "\345\245\263", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ClassTeacherForm", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        ClassTeacherBox->setTitle(QApplication::translate("ClassTeacherForm", "\345\255\246\347\224\237\344\277\241\346\201\257\345\242\236\345\210\240", nullptr));
        label_3->setText(QApplication::translate("ClassTeacherForm", "\345\255\246\345\217\267", nullptr));
        label_4->setText(QApplication::translate("ClassTeacherForm", "\345\247\223\345\220\215", nullptr));
        label_5->setText(QApplication::translate("ClassTeacherForm", "\347\217\255\347\272\247", nullptr));
        label_6->setText(QApplication::translate("ClassTeacherForm", "\346\200\247\345\210\253", nullptr));
        label_7->setText(QApplication::translate("ClassTeacherForm", "\347\224\237\346\227\245", nullptr));
        AddButton->setText(QApplication::translate("ClassTeacherForm", "\346\226\260\345\242\236", nullptr));
        DeleteButton->setText(QApplication::translate("ClassTeacherForm", "\345\210\240\351\231\244", nullptr));
        StudentSex->setItemText(0, QString());
        StudentSex->setItemText(1, QApplication::translate("ClassTeacherForm", "\347\224\267", nullptr));
        StudentSex->setItemText(2, QApplication::translate("ClassTeacherForm", "\345\245\263", nullptr));

        infoLabel->setText(QApplication::translate("ClassTeacherForm", "TextLabel", nullptr));
        SubjectTeacherBox->setTitle(QApplication::translate("ClassTeacherForm", "\345\255\246\347\224\237\346\210\220\347\273\251\347\256\241\347\220\206", nullptr));
        ChooseButton->setText(QApplication::translate("ClassTeacherForm", "\347\255\233\351\200\211", nullptr));
        AddButton_2->setText(QApplication::translate("ClassTeacherForm", "\346\226\260\345\242\236\350\200\203\350\257\225", nullptr));
        ChooseBox->setItemText(0, QString());
        ChooseBox->setItemText(1, QApplication::translate("ClassTeacherForm", "<", nullptr));
        ChooseBox->setItemText(2, QApplication::translate("ClassTeacherForm", ">=", nullptr));

        label_8->setText(QApplication::translate("ClassTeacherForm", "\347\217\255\347\272\247", nullptr));
        label_12->setText(QApplication::translate("ClassTeacherForm", "\347\255\233\351\200\211\347\272\277", nullptr));
        label_13->setText(QApplication::translate("ClassTeacherForm", "\347\255\233\351\200\211", nullptr));
        label_14->setText(QApplication::translate("ClassTeacherForm", "\350\200\203\350\257\225\345\220\215\347\247\260", nullptr));
        label_15->setText(QApplication::translate("ClassTeacherForm", "\350\200\203\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClassTeacherForm: public Ui_ClassTeacherForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSTEACHERFORM_H
