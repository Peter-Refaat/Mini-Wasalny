#include "loginPage.h"

loginPage::loginPage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

loginPage::~loginPage()
{}

QPushButton* loginPage::getLoginButton() {
	return ui.loginbtn;
}

QPushButton* loginPage::getRegisterButton()
{
	return ui.regbtn;
}

QLineEdit* loginPage::getUserName()
{
	return ui.userNameField;
}

QLineEdit* loginPage::getPassword()
{
	return ui.passwordField;
}

QPushButton* loginPage::getExitButton()
{
	return ui.exitButton;
}