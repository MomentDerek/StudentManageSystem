/********************************************************************************
** Form generated from reading UI file 'adminform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFORM_H
#define UI_ADMINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminForm
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *infoTable;
    QTableView *relationTable;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *classText;
    QLineEdit *nameText;
    QLabel *label_4;
    QLineEdit *idText;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *subjectText;
    QPushButton *FindButton;
    QPushButton *AddButton;
    QComboBox *sexBox;
    QLabel *label_9;
    QWidget *tab_2;
    QGroupBox *Box2_1;
    QLineEdit *idText_2;
    QLabel *label;
    QLineEdit *nameText_2;
    QLabel *label_2;
    QPushButton *FindButton_2;
    QPushButton *AddButton_2;
    QGroupBox *Box2_2;
    QLineEdit *teacherText_2;
    QGroupBox *Box2_3;
    QLineEdit *classText_2;
    QTableView *infoTable_2;
    QWidget *tab_3;
    QComboBox *comboBox;
    QPushButton *FreshButton;
    QPushButton *DoButtom;
    QTableView *tableView;
    QLineEdit *SqlOrder;

    void setupUi(QDialog *AdminForm)
    {
        if (AdminForm->objectName().isEmpty())
            AdminForm->setObjectName(QString::fromUtf8("AdminForm"));
        AdminForm->resize(707, 470);
        tabWidget = new QTabWidget(AdminForm);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 691, 451));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        infoTable = new QTableView(tab);
        infoTable->setObjectName(QString::fromUtf8("infoTable"));
        infoTable->setGeometry(QRect(10, 221, 311, 191));
        relationTable = new QTableView(tab);
        relationTable->setObjectName(QString::fromUtf8("relationTable"));
        relationTable->setGeometry(QRect(330, 30, 341, 381));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 200, 54, 12));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(330, 10, 54, 12));
        label_7->setLayoutDirection(Qt::LeftToRight);
        classText = new QLineEdit(tab);
        classText->setObjectName(QString::fromUtf8("classText"));
        classText->setGeometry(QRect(60, 140, 111, 31));
        nameText = new QLineEdit(tab);
        nameText->setObjectName(QString::fromUtf8("nameText"));
        nameText->setGeometry(QRect(60, 60, 241, 31));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 60, 31, 21));
        idText = new QLineEdit(tab);
        idText->setObjectName(QString::fromUtf8("idText"));
        idText->setGeometry(QRect(60, 20, 241, 31));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 140, 31, 21));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 31, 21));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 100, 31, 21));
        subjectText = new QLineEdit(tab);
        subjectText->setObjectName(QString::fromUtf8("subjectText"));
        subjectText->setGeometry(QRect(60, 100, 241, 31));
        FindButton = new QPushButton(tab);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));
        FindButton->setGeometry(QRect(80, 180, 101, 31));
        AddButton = new QPushButton(tab);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(200, 180, 101, 31));
        sexBox = new QComboBox(tab);
        sexBox->addItem(QString());
        sexBox->addItem(QString());
        sexBox->addItem(QString());
        sexBox->setObjectName(QString::fromUtf8("sexBox"));
        sexBox->setGeometry(QRect(210, 140, 91, 31));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(180, 140, 31, 21));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        Box2_1 = new QGroupBox(tab_2);
        Box2_1->setObjectName(QString::fromUtf8("Box2_1"));
        Box2_1->setGeometry(QRect(10, 10, 361, 131));
        Box2_1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        Box2_1->setFlat(false);
        Box2_1->setCheckable(false);
        idText_2 = new QLineEdit(Box2_1);
        idText_2->setObjectName(QString::fromUtf8("idText_2"));
        idText_2->setGeometry(QRect(20, 30, 261, 31));
        label = new QLabel(Box2_1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 51, 21));
        nameText_2 = new QLineEdit(Box2_1);
        nameText_2->setObjectName(QString::fromUtf8("nameText_2"));
        nameText_2->setGeometry(QRect(20, 80, 261, 31));
        label_2 = new QLabel(Box2_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 60, 51, 21));
        FindButton_2 = new QPushButton(Box2_1);
        FindButton_2->setObjectName(QString::fromUtf8("FindButton_2"));
        FindButton_2->setGeometry(QRect(290, 30, 51, 31));
        AddButton_2 = new QPushButton(Box2_1);
        AddButton_2->setObjectName(QString::fromUtf8("AddButton_2"));
        AddButton_2->setGeometry(QRect(290, 80, 51, 31));
        Box2_2 = new QGroupBox(tab_2);
        Box2_2->setObjectName(QString::fromUtf8("Box2_2"));
        Box2_2->setGeometry(QRect(390, 10, 271, 61));
        teacherText_2 = new QLineEdit(Box2_2);
        teacherText_2->setObjectName(QString::fromUtf8("teacherText_2"));
        teacherText_2->setGeometry(QRect(10, 20, 251, 31));
        Box2_3 = new QGroupBox(tab_2);
        Box2_3->setObjectName(QString::fromUtf8("Box2_3"));
        Box2_3->setGeometry(QRect(390, 80, 271, 61));
        classText_2 = new QLineEdit(Box2_3);
        classText_2->setObjectName(QString::fromUtf8("classText_2"));
        classText_2->setGeometry(QRect(10, 20, 251, 31));
        infoTable_2 = new QTableView(tab_2);
        infoTable_2->setObjectName(QString::fromUtf8("infoTable_2"));
        infoTable_2->setGeometry(QRect(10, 150, 651, 261));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        comboBox = new QComboBox(tab_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 10, 181, 22));
        FreshButton = new QPushButton(tab_3);
        FreshButton->setObjectName(QString::fromUtf8("FreshButton"));
        FreshButton->setGeometry(QRect(210, 10, 75, 23));
        DoButtom = new QPushButton(tab_3);
        DoButtom->setObjectName(QString::fromUtf8("DoButtom"));
        DoButtom->setGeometry(QRect(300, 10, 75, 23));
        tableView = new QTableView(tab_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 70, 651, 341));
        tableView->setAutoScrollMargin(10);
        tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
        tableView->setSortingEnabled(true);
        SqlOrder = new QLineEdit(tab_3);
        SqlOrder->setObjectName(QString::fromUtf8("SqlOrder"));
        SqlOrder->setGeometry(QRect(10, 40, 651, 21));
        tabWidget->addTab(tab_3, QString());

        retranslateUi(AdminForm);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(AdminForm);
    } // setupUi

    void retranslateUi(QDialog *AdminForm)
    {
        AdminForm->setWindowTitle(QApplication::translate("AdminForm", "\347\256\241\347\220\206\345\221\230\347\225\214\351\235\242", nullptr));
        label_6->setText(QApplication::translate("AdminForm", "\346\225\231\345\270\210\344\277\241\346\201\257", nullptr));
        label_7->setText(QApplication::translate("AdminForm", "\346\211\247\346\225\231\345\205\263\347\263\273", nullptr));
        label_4->setText(QApplication::translate("AdminForm", "\345\247\223\345\220\215", nullptr));
        label_8->setText(QApplication::translate("AdminForm", "\347\217\255\347\272\247", nullptr));
        label_3->setText(QApplication::translate("AdminForm", "\345\267\245\345\217\267", nullptr));
        label_5->setText(QApplication::translate("AdminForm", "\347\247\221\347\233\256", nullptr));
        FindButton->setText(QApplication::translate("AdminForm", "\346\237\245\350\257\242", nullptr));
        AddButton->setText(QApplication::translate("AdminForm", "\346\226\260\345\242\236", nullptr));
        sexBox->setItemText(0, QString());
        sexBox->setItemText(1, QApplication::translate("AdminForm", "\347\224\267", nullptr));
        sexBox->setItemText(2, QApplication::translate("AdminForm", "\345\245\263", nullptr));

        label_9->setText(QApplication::translate("AdminForm", "\346\200\247\345\210\253", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("AdminForm", "\344\277\256\346\224\271\346\225\231\345\270\210\344\277\241\346\201\257", nullptr));
        Box2_1->setTitle(QApplication::translate("AdminForm", "\346\240\271\346\215\256\345\255\246\347\224\237\344\277\241\346\201\257\346\237\245\346\211\276\346\210\226\346\267\273\345\212\240", nullptr));
        label->setText(QApplication::translate("AdminForm", "\345\255\246\345\217\267", nullptr));
        nameText_2->setText(QString());
        label_2->setText(QApplication::translate("AdminForm", "\345\247\223\345\220\215", nullptr));
        FindButton_2->setText(QApplication::translate("AdminForm", "\346\237\245\346\211\276", nullptr));
        AddButton_2->setText(QApplication::translate("AdminForm", "\346\267\273\345\212\240", nullptr));
        Box2_2->setTitle(QApplication::translate("AdminForm", "\346\240\271\346\215\256\346\225\231\345\270\210\346\237\245\346\211\276", nullptr));
        Box2_3->setTitle(QApplication::translate("AdminForm", "\346\240\271\346\215\256\347\217\255\347\272\247\346\237\245\346\211\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("AdminForm", "\344\277\256\346\224\271\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        comboBox->setItemText(0, QApplication::translate("AdminForm", "user", nullptr));
        comboBox->setItemText(1, QApplication::translate("AdminForm", "info", nullptr));
        comboBox->setItemText(2, QApplication::translate("AdminForm", "score", nullptr));
        comboBox->setItemText(3, QApplication::translate("AdminForm", "teacher", nullptr));
        comboBox->setItemText(4, QApplication::translate("AdminForm", "relation", nullptr));
        comboBox->setItemText(5, QApplication::translate("AdminForm", "score_chinese", nullptr));
        comboBox->setItemText(6, QApplication::translate("AdminForm", "score_maths", nullptr));
        comboBox->setItemText(7, QApplication::translate("AdminForm", "score_english", nullptr));

        comboBox->setCurrentText(QApplication::translate("AdminForm", "user", nullptr));
        FreshButton->setText(QApplication::translate("AdminForm", "\345\210\267\346\226\260\350\241\250", nullptr));
        DoButtom->setText(QApplication::translate("AdminForm", "\346\211\247\350\241\214", nullptr));
        SqlOrder->setText(QApplication::translate("AdminForm", "\345\234\250\346\255\244\350\276\223\345\205\245sqlite\346\214\207\344\273\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("AdminForm", "\351\253\230\347\272\247\344\277\256\346\224\271\346\250\241\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminForm: public Ui_AdminForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFORM_H
