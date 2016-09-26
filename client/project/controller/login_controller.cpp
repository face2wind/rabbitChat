#include "login_controller.hpp"

#include "network/networkagent.h"
#include "net_msg/login_msg.hpp"

LoginController::LoginController() : has_login_(false)
{

}

LoginController::~LoginController()
{

}

LoginController & LoginController::GetInstance()
{
    static LoginController instance;
    return instance;
}

void LoginController::LoginRequest(const QString &name, const QString &passwd)
{
    if (has_login_) return;

    static protocol::CSLogin login;

    QByteArray name_by = name.toLatin1();
    strncpy(login.name, name_by.data(), sizeof(login.name));

    QByteArray pass_by = passwd.toLatin1();
    strncpy(login.passwd, pass_by.data(), sizeof(login.passwd));

    NetworkAgent::GetInstance().SendToServer((char*)&login, sizeof(login));
}

void LoginController::RegisterRequest(const QString &name, const QString &passwd)
{
    static protocol::CSRegisterAccount register_msg;

    QByteArray name_by = name.toLatin1();
    strncpy(register_msg.name, name_by.data(), sizeof(register_msg.name));

    QByteArray pass_by = passwd.toLatin1();
    strncpy(register_msg.passwd, pass_by.data(), sizeof(register_msg.passwd));

    NetworkAgent::GetInstance().SendToServer((char*)&register_msg, sizeof(register_msg));
}
