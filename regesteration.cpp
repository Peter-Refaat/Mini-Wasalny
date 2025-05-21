#include "regesteration.h"
#include<QPushButton>

regesteration::regesteration(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

regesteration::~regesteration()
 {}

QPushButton* regesteration::getSaveButton()
{
    return ui.backtologib;
}

QLineEdit* regesteration::getUserName()
{
    return ui.username;
}

QLineEdit* regesteration::getPassword()
{
    return ui.password;
}

QPushButton* regesteration::getBackToLoginButton()
{
	return ui.backToLogin;
}
