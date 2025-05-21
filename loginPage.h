#pragma once
#include<QPushButton>
#include <QMainWindow>
#include "ui_loginPage.h"
#include <QLineEdit>

class loginPage : public QMainWindow
{
	Q_OBJECT

public:
	loginPage(QWidget *parent = nullptr);
	~loginPage();

	QPushButton* getLoginButton();
	QLineEdit* getUserName();
	QLineEdit* getPassword();
	QPushButton* getRegisterButton();
	QPushButton* getExitButton();
private:
	Ui::loginPageClass ui;
};
