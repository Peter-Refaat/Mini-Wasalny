/********************************************************************************
** Form generated from reading UI file 'regesteration.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGESTERATION_H
#define UI_REGESTERATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_regesterationClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label_3;
    QPushButton *backtologib;
    QPushButton *backToLogin;
    QLabel *label;

    void setupUi(QMainWindow *regesterationClass)
    {
        if (regesterationClass->objectName().isEmpty())
            regesterationClass->setObjectName("regesterationClass");
        regesterationClass->resize(2000, 1100);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(regesterationClass->sizePolicy().hasHeightForWidth());
        regesterationClass->setSizePolicy(sizePolicy);
        regesterationClass->setMinimumSize(QSize(2000, 1100));
        centralWidget = new QWidget(regesterationClass);
        centralWidget->setObjectName("centralWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(192);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(1920, 1080));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(420, 120, 650, 700));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        font.setBold(true);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: rgba(255, 255, 255, 160);  /* semi-transparent white */\n"
"    border: 1px solid rgba(0, 0, 0, 80);\n"
"    border-radius: 10px;\n"
"    margin-top: 20px; /* space for the title */\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    padding: 0 5px;\n"
"    background-color: transparent;\n"
"    color: #333;\n"
"}\n"
""));
        frame = new QFrame(groupBox);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 200, 561, 151));
        frame->setSizeIncrement(QSize(5, 0));
        QFont font1;
        font1.setPointSize(9);
        frame->setFont(font1);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        username = new QLineEdit(frame);
        username->setObjectName("username");
        username->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(12);
        font2.setBold(true);
        username->setFont(font2);
        username->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 160);  /* semi-transparent white */\n"
"color:black;\n"
"    border: 1px solid rgba(0, 0, 0, 80);\n"
"    border-radius: 10px;\n"
"    /* space for the title */"));

        verticalLayout->addWidget(username);

        password = new QLineEdit(frame);
        password->setObjectName("password");
        password->setMinimumSize(QSize(0, 50));
        password->setFont(font2);
        password->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 160);  /* semi-transparent white */\n"
"color:black;\n"
"    border: 1px solid rgba(0, 0, 0, 80);\n"
"    border-radius: 10px;\n"
"    /* space for the title */"));

        verticalLayout->addWidget(password);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 80, 421, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(22);
        font3.setBold(true);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color:black;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3->setWordWrap(false);
        backtologib = new QPushButton(groupBox);
        backtologib->setObjectName("backtologib");
        backtologib->setGeometry(QRect(170, 370, 311, 61));
        backtologib->setMinimumSize(QSize(30, 30));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(16);
        font4.setBold(true);
        backtologib->setFont(font4);
        backtologib->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #261FB3  ;   \n"
"    color: white;                /* White text */\n"
"    border-radius: 20px;          /* Rounded corners */\n"
"    padding: 5px 10px;           /* Padding */\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #161179;   /* Darker blue on hover */\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #0C0950;   /* Even darker when clicked */\n"
"}"));
        backToLogin = new QPushButton(centralWidget);
        backToLogin->setObjectName("backToLogin");
        backToLogin->setGeometry(QRect(10, 10, 150, 70));
        backToLogin->setMinimumSize(QSize(50, 50));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(18);
        font5.setBold(true);
        backToLogin->setFont(font5);
        backToLogin->setStyleSheet(QString::fromUtf8("\n"
"						QPushButton {\n"
"						background-color: #261FB3  ;\n"
"						color: white;                /* White text */\n"
"						border-radius: 20px;          /* Rounded corners */\n"
"						padding: 5px 10px;           /* Padding */\n"
"						}\n"
"						QPushButton:hover {\n"
"						background-color: #161179;   /* Darker blue on hover */\n"
"						}\n"
"						QPushButton:pressed {\n"
"						background-color: #0C0950;   /* Even darker when clicked */\n"
"						}\n"
"					"));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(0, 0, 2000, 1100));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(2000, 1080));
        label->setMaximumSize(QSize(1920, 1920));
        label->setPixmap(QPixmap(QString::fromUtf8("backgeound.jpg")));
        label->setScaledContents(true);
        label->setWordWrap(true);
        regesterationClass->setCentralWidget(centralWidget);
        label->raise();
        groupBox->raise();
        backToLogin->raise();

        retranslateUi(regesterationClass);

        QMetaObject::connectSlotsByName(regesterationClass);
    } // setupUi

    void retranslateUi(QMainWindow *regesterationClass)
    {
        regesterationClass->setWindowTitle(QCoreApplication::translate("regesterationClass", "Wasalny", nullptr));
        groupBox->setTitle(QString());
        username->setText(QString());
        username->setPlaceholderText(QCoreApplication::translate("regesterationClass", "User Name", nullptr));
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("regesterationClass", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("regesterationClass", "Register", nullptr));
        backtologib->setText(QCoreApplication::translate("regesterationClass", "Save", nullptr));
        backToLogin->setText(QCoreApplication::translate("regesterationClass", "Back", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class regesterationClass: public Ui_regesterationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGESTERATION_H
