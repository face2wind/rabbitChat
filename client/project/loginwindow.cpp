#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "network_manager/networkagent.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    NetworkAgent::GetInstance();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_login_btn_clicked()
{
    NetworkAgent::GetInstance().SendToServer("Yea!", 5);
}
