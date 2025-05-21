/********************************************************************************
** Form generated from reading UI file 'loginPage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginPageClass
{
public:
    QWidget *centralWidget;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *exitButton;
    QFrame *frame_2;
    QGroupBox *groupBox;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *userNameField;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *passwordField;
    QLabel *label_3;
    QPushButton *loginbtn;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *regbtn;

    void setupUi(QMainWindow *loginPageClass)
    {
        if (loginPageClass->objectName().isEmpty())
            loginPageClass->setObjectName("loginPageClass");
        loginPageClass->resize(2000, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginPageClass->sizePolicy().hasHeightForWidth());
        loginPageClass->setSizePolicy(sizePolicy);
        loginPageClass->setMinimumSize(QSize(2000, 1080));
        loginPageClass->setMaximumSize(QSize(1920, 1080));
        centralWidget = new QWidget(loginPageClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-image: url(pg1.jpg);  /* use your correct path */\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-origin: content;\n"
"    background-size: cover;  /* optional: stretch image to fill */\n"
"}\n"
""));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 2000, 1100));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(2000, 1100));
        label_2->setMaximumSize(QSize(1000, 1000));
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("border-radius: 20px;"));
        label_2->setPixmap(QPixmap(QString::fromUtf8("backgeound.jpg")));
        label_2->setScaledContents(true);
        label_2->setWordWrap(true);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(10, 10, 150, 70));
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);
        exitButton->setMinimumSize(QSize(50, 50));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(18);
        font.setBold(true);
        exitButton->setFont(font);
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(350, 120, 750, 700));
        frame_2->setStyleSheet(QString::fromUtf8("\n"
"         border-radius: 10px;\n"
"    "));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(70, 0, 650, 700));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        groupBox->setFont(font1);
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
        groupBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame = new QFrame(groupBox);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 200, 561, 151));
        frame->setSizeIncrement(QSize(5, 0));
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        userNameField = new QLineEdit(frame);
        userNameField->setObjectName("userNameField");
        userNameField->setMinimumSize(QSize(0, 50));
        userNameField->setFont(font1);
        userNameField->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 160);  /* semi-transparent white */\n"
"color:black;\n"
"    border: 1px solid rgba(0, 0, 0, 80);\n"
"    border-radius: 10px;\n"
"    /* space for the title */"));

        horizontalLayout_2->addWidget(userNameField);


        horizontalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        passwordField = new QLineEdit(frame);
        passwordField->setObjectName("passwordField");
        passwordField->setMinimumSize(QSize(0, 50));
        passwordField->setFont(font1);
        passwordField->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 160);  /* semi-transparent white */\n"
"color:black;\n"
"    border: 1px solid rgba(0, 0, 0, 80);\n"
"    border-radius: 10px;\n"
"    /* space for the title */"));

        horizontalLayout_7->addWidget(passwordField);


        horizontalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(horizontalLayout_6);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 80, 401, 61));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(22);
        font2.setBold(true);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color:black;"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3->setWordWrap(false);
        loginbtn = new QPushButton(groupBox);
        loginbtn->setObjectName("loginbtn");
        loginbtn->setGeometry(QRect(170, 370, 311, 61));
        loginbtn->setMinimumSize(QSize(0, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial Rounded MT")});
        font3.setPointSize(16);
        font3.setBold(true);
        loginbtn->setFont(font3);
        loginbtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(140, 450, 371, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(10);
        font4.setBold(false);
        label->setFont(font4);
        label->setStyleSheet(QString::fromUtf8("color: black;"));

        horizontalLayout->addWidget(label);

        regbtn = new QPushButton(horizontalLayoutWidget);
        regbtn->setObjectName("regbtn");
        regbtn->setMinimumSize(QSize(50, 30));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setUnderline(false);
        regbtn->setFont(font5);
        regbtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    color: black; /* normal text color */\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: grey; /* darker on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    color: #333333; /* darker on press */\n"
"}"));

        horizontalLayout->addWidget(regbtn);

        loginPageClass->setCentralWidget(centralWidget);
        layoutWidget->raise();
        label_2->raise();
        exitButton->raise();
        frame_2->raise();

        retranslateUi(loginPageClass);

        QMetaObject::connectSlotsByName(loginPageClass);
    } // setupUi

    void retranslateUi(QMainWindow *loginPageClass)
    {
        loginPageClass->setWindowTitle(QCoreApplication::translate("loginPageClass", "loginPage", nullptr));
        label_2->setText(QString());
        exitButton->setText(QCoreApplication::translate("loginPageClass", "EXIT", nullptr));
        groupBox->setTitle(QString());
        userNameField->setPlaceholderText(QCoreApplication::translate("loginPageClass", "User Name", nullptr));
        passwordField->setPlaceholderText(QCoreApplication::translate("loginPageClass", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("loginPageClass", "Login", nullptr));
        loginbtn->setText(QCoreApplication::translate("loginPageClass", "Sign In", nullptr));
        label->setText(QCoreApplication::translate("loginPageClass", "Don't have an account?     ", nullptr));
        regbtn->setText(QCoreApplication::translate("loginPageClass", "Register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginPageClass: public Ui_loginPageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
