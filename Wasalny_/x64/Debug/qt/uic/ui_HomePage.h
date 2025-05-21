/********************************************************************************
** Form generated from reading UI file 'HomePage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePageClass
{
public:
    QWidget *centralWidget;
    QLabel *background;
    QLineEdit *nodename;
    QGraphicsView *graph;
    QLabel *label_3;
    QLineEdit *distance;
    QLineEdit *firstcity;
    QLineEdit *secondcity;
    QPushButton *dfs;
    QPushButton *dijkstra;
    QPushButton *pushButton;
    QPushButton *deleteEdge;
    QPushButton *addnode;
    QPushButton *deleteNode;
    QPushButton *floyd_warshall;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *logOut;
    QLabel *shortestPath;
    QPushButton *bfs;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HomePageClass)
    {
        if (HomePageClass->objectName().isEmpty())
            HomePageClass->setObjectName("HomePageClass");
        HomePageClass->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HomePageClass->sizePolicy().hasHeightForWidth());
        HomePageClass->setSizePolicy(sizePolicy);
        HomePageClass->setMinimumSize(QSize(1920, 1080));
        HomePageClass->setMaximumSize(QSize(1920, 1080));
        centralWidget = new QWidget(HomePageClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8("background-color: #dddddd;"));
        background = new QLabel(centralWidget);
        background->setObjectName("background");
        background->setGeometry(QRect(-10, -50, 1921, 1121));
        background->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        background->setPixmap(QPixmap(QString::fromUtf8("backgeound.jpg")));
        background->setScaledContents(true);
        background->setAlignment(Qt::AlignmentFlag::AlignCenter);
        nodename = new QLineEdit(centralWidget);
        nodename->setObjectName("nodename");
        nodename->setGeometry(QRect(20, 360, 521, 51));
        nodename->setMinimumSize(QSize(0, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(11);
        font.setBold(true);
        font.setKerning(true);
        nodename->setFont(font);
        nodename->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 160);  /* semi-transparent white */\n"
"color:black;\n"
"    border: 1px solid rgba(0, 0, 0, 80);\n"
"    border-radius: 10px;\n"
"    /* space for the title */"));
        nodename->setAlignment(Qt::AlignmentFlag::AlignCenter);
        graph = new QGraphicsView(centralWidget);
        graph->setObjectName("graph");
        graph->setGeometry(QRect(570, 50, 901, 541));
        graph->setStyleSheet(QString::fromUtf8("\n"
"   background-color: rgba(255, 255, 255, 160);    /* Light gray background */\n"
"    border: 1px solid #cccccc;      /* Soft border */\n"
"    border-radius: 10px;  border: 2px solid black;           /* Rounded corners */\n"
"    padding: 10px;                  /* Inner spacing */\n"
"\n"
""));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 60, 541, 301));
        QFont font1;
        font1.setPointSize(5);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color:transparent ;      /* Light gray background */\n"
"        /* Rounded corners */\n"
"    padding: 10px;     \n"
" border-radius: 30px; \n"
"             /* Inner spacing */\n"
"}"));
        label_3->setPixmap(QPixmap(QString::fromUtf8("Screenshot_2025-05-09_221300.png")));
        label_3->setScaledContents(true);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3->setWordWrap(true);
        label_3->setIndent(0);
        distance = new QLineEdit(centralWidget);
        distance->setObjectName("distance");
        distance->setGeometry(QRect(20, 540, 250, 50));
        distance->setMinimumSize(QSize(0, 30));
        QFont font2;
        font2.setBold(true);
        distance->setFont(font2);
        distance->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 160);  /* semi-transparent white */\n"
"color:black;\n"
"    border: 1px solid rgba(0, 0, 0, 80);\n"
"    border-radius: 10px;\n"
"    /* space for the title */"));
        distance->setAlignment(Qt::AlignmentFlag::AlignCenter);
        firstcity = new QLineEdit(centralWidget);
        firstcity->setObjectName("firstcity");
        firstcity->setGeometry(QRect(20, 480, 250, 50));
        firstcity->setMinimumSize(QSize(0, 30));
        firstcity->setFont(font2);
        firstcity->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 160);  /* semi-transparent white */\n"
"color:black;\n"
"    border: 1px solid rgba(0, 0, 0, 80);\n"
"    border-radius: 10px;\n"
"    /* space for the title */"));
        firstcity->setAlignment(Qt::AlignmentFlag::AlignCenter);
        secondcity = new QLineEdit(centralWidget);
        secondcity->setObjectName("secondcity");
        secondcity->setGeometry(QRect(290, 480, 250, 50));
        secondcity->setMinimumSize(QSize(0, 50));
        secondcity->setFont(font2);
        secondcity->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 160);  /* semi-transparent white */\n"
"color:black;\n"
"    border: 1px solid rgba(0, 0, 0, 80);\n"
"    border-radius: 10px;\n"
"    /* space for the title */"));
        secondcity->setAlignment(Qt::AlignmentFlag::AlignCenter);
        dfs = new QPushButton(centralWidget);
        dfs->setObjectName("dfs");
        dfs->setGeometry(QRect(290, 720, 250, 50));
        dfs->setMinimumSize(QSize(0, 40));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        dfs->setFont(font3);
        dfs->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        dijkstra = new QPushButton(centralWidget);
        dijkstra->setObjectName("dijkstra");
        dijkstra->setGeometry(QRect(20, 600, 250, 50));
        dijkstra->setMinimumSize(QSize(0, 40));
        dijkstra->setFont(font3);
        dijkstra->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 540, 250, 51));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        deleteEdge = new QPushButton(centralWidget);
        deleteEdge->setObjectName("deleteEdge");
        deleteEdge->setGeometry(QRect(290, 600, 250, 51));
        deleteEdge->setMinimumSize(QSize(0, 40));
        deleteEdge->setFont(font3);
        deleteEdge->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        addnode = new QPushButton(centralWidget);
        addnode->setObjectName("addnode");
        addnode->setGeometry(QRect(20, 420, 250, 51));
        addnode->setMinimumSize(QSize(0, 40));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        addnode->setFont(font4);
        addnode->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        addnode->setText(QString::fromUtf8("Add city"));
        addnode->setIconSize(QSize(16, 16));
        deleteNode = new QPushButton(centralWidget);
        deleteNode->setObjectName("deleteNode");
        deleteNode->setGeometry(QRect(290, 420, 250, 50));
        deleteNode->setMinimumSize(QSize(10, 40));
        deleteNode->setMaximumSize(QSize(16777214, 16777215));
        deleteNode->setFont(font4);
        deleteNode->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        floyd_warshall = new QPushButton(centralWidget);
        floyd_warshall->setObjectName("floyd_warshall");
        floyd_warshall->setGeometry(QRect(20, 780, 520, 50));
        floyd_warshall->setMinimumSize(QSize(0, 40));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(12);
        font5.setBold(true);
        floyd_warshall->setFont(font5);
        floyd_warshall->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(570, 600, 901, 231));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(10);
        font6.setBold(true);
        scrollArea->setFont(font6);
        scrollArea->setStyleSheet(QString::fromUtf8("\n"
"   background-color: rgba(255, 255, 255, 160);    /* Light gray background */\n"
"    border: 1px solid #cccccc;      /* Soft border */\n"
"    border-radius: 10px;  border: 2px solid black;           /* Rounded corners */\n"
"    padding: 10px;                  /* Inner spacing */\n"
"\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 877, 207));
        QFont font7;
        font7.setPointSize(10);
        scrollAreaWidgetContents->setFont(font7);
        scrollArea->setWidget(scrollAreaWidgetContents);
        logOut = new QPushButton(centralWidget);
        logOut->setObjectName("logOut");
        logOut->setGeometry(QRect(10, 10, 150, 51));
        logOut->setMinimumSize(QSize(0, 40));
        QFont font8;
        font8.setPointSize(18);
        font8.setBold(true);
        logOut->setFont(font8);
        logOut->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        logOut->setText(QString::fromUtf8("Log Out"));
        logOut->setIconSize(QSize(16, 16));
        shortestPath = new QLabel(centralWidget);
        shortestPath->setObjectName("shortestPath");
        shortestPath->setGeometry(QRect(20, 660, 521, 51));
        shortestPath->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #dddddd;\n"
"    color: black;                   /* Same text color */\n"
"    border: 1px solid #444;        /* Same border */\n"
"    border-radius: 10px;           /* Same rounding */\n"
"    padding: 6px 10px;             /* Same padding */\n"
"    font-size: 14px;               /* Same font size */\n"
"}"));
        bfs = new QPushButton(centralWidget);
        bfs->setObjectName("bfs");
        bfs->setGeometry(QRect(20, 720, 250, 50));
        bfs->setMinimumSize(QSize(0, 40));
        bfs->setFont(font3);
        bfs->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        HomePageClass->setCentralWidget(centralWidget);
        background->raise();
        dfs->raise();
        dijkstra->raise();
        pushButton->raise();
        deleteEdge->raise();
        nodename->raise();
        graph->raise();
        label_3->raise();
        distance->raise();
        firstcity->raise();
        secondcity->raise();
        deleteNode->raise();
        addnode->raise();
        floyd_warshall->raise();
        scrollArea->raise();
        logOut->raise();
        shortestPath->raise();
        bfs->raise();
        statusBar = new QStatusBar(HomePageClass);
        statusBar->setObjectName("statusBar");
        HomePageClass->setStatusBar(statusBar);

        retranslateUi(HomePageClass);

        QMetaObject::connectSlotsByName(HomePageClass);
    } // setupUi

    void retranslateUi(QMainWindow *HomePageClass)
    {
        HomePageClass->setWindowTitle(QCoreApplication::translate("HomePageClass", "HomePage", nullptr));
        background->setText(QString());
        nodename->setPlaceholderText(QCoreApplication::translate("HomePageClass", "Enter city name", nullptr));
        label_3->setText(QString());
        distance->setPlaceholderText(QCoreApplication::translate("HomePageClass", "Distance", nullptr));
        firstcity->setPlaceholderText(QCoreApplication::translate("HomePageClass", "1st city", nullptr));
        secondcity->setPlaceholderText(QCoreApplication::translate("HomePageClass", "2nd city", nullptr));
        dfs->setText(QCoreApplication::translate("HomePageClass", "DFS", nullptr));
        dijkstra->setText(QCoreApplication::translate("HomePageClass", "Dijkstra", nullptr));
        pushButton->setText(QCoreApplication::translate("HomePageClass", "Add Edge", nullptr));
        deleteEdge->setText(QCoreApplication::translate("HomePageClass", "Delete Edge", nullptr));
        deleteNode->setText(QCoreApplication::translate("HomePageClass", "Delete city", nullptr));
        floyd_warshall->setText(QCoreApplication::translate("HomePageClass", "Floyd Warshall", nullptr));
        shortestPath->setText(QString());
        bfs->setText(QCoreApplication::translate("HomePageClass", "BFS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePageClass: public Ui_HomePageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
