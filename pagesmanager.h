#pragma once
#include <QMainWindow>
#include "HomePage.h"
#include "loginPage.h"
#include<QStackedWidget>
#include <QVBoxLayout> 
#include <QObject>
#include <QCloseEvent>
#include <QFile>
#include <QTextStream>
#include"regesteration.h"
class pagesmanager : public QWidget {
    Q_OBJECT

public:
    pagesmanager(QWidget* parent = nullptr);
protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onLoginSuccess();
    void onRegister();
    void onSave();
    void onLogOut();
    void onBack();
    void onExit();
    void keyPressEvent(QKeyEvent* event);
private:
    QStackedWidget* stackedWidget;
    loginPage* login;
    HomePage* home;
    regesteration* registeration;
};