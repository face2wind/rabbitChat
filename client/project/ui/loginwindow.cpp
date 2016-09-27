#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "controller/login_controller.hpp"
#include "ui/ui_manager.hpp"
#include "network/networkagent.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::OnNoThisAccount()
{
    ui->error_msg_text->setText("帐号不存在，请重新登录");
}

void LoginWindow::OnPasswdWrong()
{
    ui->error_msg_text->setText("密码错误，请重新登录");
}

void LoginWindow::on_register_btn_clicked()
{
    UIManager::GetInstance().ShowRegister();
}

void LoginWindow::on_login_btn_clicked()
{
    if (!NetworkAgent::GetInstance().HasConnected())
    {
        ui->error_msg_text->setText("未连上服务器，请稍后再试");
        NetworkAgent::GetInstance().ConnectToServer();
        return;
    }

    LoginController::GetInstance().LoginRequest(ui->account_input->text(), ui->password_input->text());
}
