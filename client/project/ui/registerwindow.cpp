#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "controller/login_controller.hpp"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_login_btn_clicked()
{
    LoginController::GetInstance().LoginRequest(ui->account_input->text(), ui->password_input->text());
}
