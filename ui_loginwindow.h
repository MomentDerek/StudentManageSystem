/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout;
    QLabel *Label1;
    QLabel *Label2;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QLineEdit *UsernameTxt;
    QLineEdit *PasswordTxt;
    QSpacerItem *horizontalSpacer_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *LoginBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *HelpBtn;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(400, 306);
        LoginWindow->setMinimumSize(QSize(400, 0));
        LoginWindow->setMaximumSize(QSize(800, 400));
        verticalLayout_2 = new QVBoxLayout(LoginWindow);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        frame_4 = new QFrame(LoginWindow);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        frame_3 = new QFrame(frame_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Label1 = new QLabel(frame_3);
        Label1->setObjectName(QString::fromUtf8("Label1"));
        Label1->setTextFormat(Qt::AutoText);
        Label1->setScaledContents(false);

        verticalLayout->addWidget(Label1);

        Label2 = new QLabel(frame_3);
        Label2->setObjectName(QString::fromUtf8("Label2"));

        verticalLayout->addWidget(Label2);


        horizontalLayout_2->addWidget(frame_3);

        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        UsernameTxt = new QLineEdit(frame_2);
        UsernameTxt->setObjectName(QString::fromUtf8("UsernameTxt"));
        UsernameTxt->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(UsernameTxt, 0, 0, 1, 1);

        PasswordTxt = new QLineEdit(frame_2);
        PasswordTxt->setObjectName(QString::fromUtf8("PasswordTxt"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PasswordTxt->sizePolicy().hasHeightForWidth());
        PasswordTxt->setSizePolicy(sizePolicy);
        PasswordTxt->setMinimumSize(QSize(200, 30));

        gridLayout->addWidget(PasswordTxt, 1, 0, 1, 1);


        horizontalLayout_2->addWidget(frame_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(frame_4);

        frame = new QFrame(LoginWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        horizontalSpacer_2 = new QSpacerItem(40, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        LoginBtn = new QPushButton(frame);
        LoginBtn->setObjectName(QString::fromUtf8("LoginBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LoginBtn->sizePolicy().hasHeightForWidth());
        LoginBtn->setSizePolicy(sizePolicy1);
        LoginBtn->setMinimumSize(QSize(60, 30));

        horizontalLayout->addWidget(LoginBtn);

        horizontalSpacer = new QSpacerItem(40, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        HelpBtn = new QPushButton(frame);
        HelpBtn->setObjectName(QString::fromUtf8("HelpBtn"));
        sizePolicy1.setHeightForWidth(HelpBtn->sizePolicy().hasHeightForWidth());
        HelpBtn->setSizePolicy(sizePolicy1);
        HelpBtn->setMinimumSize(QSize(60, 30));

        horizontalLayout->addWidget(HelpBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);


        verticalLayout_2->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(verticalSpacer);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", nullptr));
        Label1->setText(QApplication::translate("LoginWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        Label2->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201", nullptr));
        LoginBtn->setText(QApplication::translate("LoginWindow", "\347\231\273\351\231\206", nullptr));
        HelpBtn->setText(QApplication::translate("LoginWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
