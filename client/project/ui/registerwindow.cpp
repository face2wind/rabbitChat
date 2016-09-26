#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "controller/login_controller.hpp"
#include "ui/ui_manager.hpp"

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

void RegisterWindow::OnRegisterSucc()
{
    ui->error_msg_text->setText("恭喜你，注册成功！请返回登录");
}

void RegisterWindow::OnHasAccount()
{
    ui->error_msg_text->setText("该帐号已存在，请换个帐号");
}

void RegisterWindow::on_login_btn_clicked()
{
    if (ui->password_input->text() != ui->password_input_2->text())
    {
        ui->error_msg_text->setText("重复密码不匹配");
        return;
    }

    LoginController::GetInstance().RegisterRequest(ui->account_input->text(), ui->password_input->text());
}

void RegisterWindow::on_return_login_clicked()
{
    UIManager::GetInstance().ShowLogin();
}
