#include "pagesmanager.h"
#include <UserManager.h>

pagesmanager::pagesmanager(QWidget* parent) : QWidget(parent) {

    UserManager u = UserManager();

    stackedWidget = new QStackedWidget(this);

    login = new loginPage();
    registeration = new regesteration();
    stackedWidget->addWidget(login);
    stackedWidget->addWidget(registeration);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);
    setLayout(layout);
    showFullScreen();

    stackedWidget->setCurrentWidget(login);
    connect(login->getRegisterButton(), &QPushButton::clicked, this, &pagesmanager::onRegister);
    connect(login->getLoginButton(), &QPushButton::clicked, this, &pagesmanager::onLoginSuccess);
    connect(registeration->getSaveButton(), &QPushButton::clicked, this, &pagesmanager::onSave);
    connect(registeration->getBackToLoginButton(), &QPushButton::clicked, this, &pagesmanager::onBack);
    connect(login->getExitButton(), &QPushButton::clicked, this, &pagesmanager::onExit);
}

void pagesmanager::onRegister()
{
    HomePage::resetLineEdit(registeration->getUserName(), "Username");
    HomePage::resetLineEdit(registeration->getPassword(), "Password");

    HomePage::resetLineEdit(login->getUserName(), "User Name");
    HomePage::resetLineEdit(login->getPassword(), "Password");
    stackedWidget->setCurrentWidget(registeration);
}

void pagesmanager::onSave()
{
    QString username = registeration->getUserName()->text();
    QString password = registeration->getPassword()->text();
    string s = username.toStdString();

    if (!username.isEmpty()) {
        if (UserManager::AvailableUserName(s)) {
            HomePage::setLineEditError(registeration->getUserName(), "User Name Already Exists!!");
            return;
        }
    }
    else {
        HomePage::setLineEditError(registeration->getUserName(), "Field Can't Be Empty");
        return;
    }

    if (password.isEmpty()) {
        HomePage::setLineEditError(registeration->getPassword(), "Field Can't Be Empty");
        return;
    }

    UserManager::MakeUser(username.toStdString(), password.toStdString());
    stackedWidget->setCurrentWidget(login);
}

void pagesmanager::onLoginSuccess() {
    QString username = login->getUserName()->text();
    QString password = login->getPassword()->text();

    bool userExist = UserManager::CheckCredentials(username.toStdString(), password.toStdString());

    if (!userExist) {
        HomePage::setLineEditError(login->getUserName(), "Username Is Invalid");
        HomePage::setLineEditError(login->getPassword(), "Password Is Invalid");
    }
    else
    {
        home = new HomePage();
        stackedWidget->addWidget(home);
        stackedWidget->setCurrentWidget(home);
        connect(home->getLogOut(), &QPushButton::clicked, this, &pagesmanager::onLogOut);
    }
}

void pagesmanager::closeEvent(QCloseEvent* event)
{
    UserManager::SaveStateToFile("userdata.json");
    event->accept();
}

void pagesmanager::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape && isFullScreen()) {
        showNormal();
        resize(1280, 720); // Restore to a reasonable size
    }
    QWidget::keyPressEvent(event);
}

void pagesmanager::onLogOut()
{
    HomePage::resetLineEdit(login->getUserName(), "User Name");
    HomePage::resetLineEdit(login->getPassword(), "Password");
    stackedWidget->setCurrentWidget(login);
}

void pagesmanager::onBack()
{
    HomePage::resetLineEdit(login->getUserName(), "User Name");
    HomePage::resetLineEdit(login->getPassword(), "Password");
    stackedWidget->setCurrentWidget(login);
}

void pagesmanager::onExit()
{
    UserManager::SaveStateToFile("userdata.json");
    close();
}