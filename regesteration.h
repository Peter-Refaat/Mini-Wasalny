#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_regesteration.h"

class regesteration : public QMainWindow
{
    Q_OBJECT

public:
    regesteration(QWidget *parent = nullptr);
    ~regesteration();
    QPushButton* getSaveButton();
    QLineEdit* getUserName();
    QLineEdit* getPassword();
	QPushButton* getBackToLoginButton();
private:
    Ui::regesterationClass ui;
};
