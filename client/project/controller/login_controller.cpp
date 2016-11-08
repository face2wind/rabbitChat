#include "login_controller.hpp"

#include "network/networkagent.h"
#include "protocol_def.hpp"

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

    static Protocol::CSLogin login;

    QByteArray name_by = name.toLatin1();
    login.name = name_by.toStdString();
   // strncpy(login.name, name_by.data(), sizeof(login.name));

    QByteArray pass_by = passwd.toLatin1();
    login.passwd = pass_by.toStdString();
    //strncpy(login.passwd, pass_by.data(), sizeof(login.passwd));

    NetworkAgent::GetInstance().SendToServer(login);
}

void LoginController::RegisterRequest(const QString &name, const QString &passwd)
{
    static Protocol::CSRegisterAccount register_msg;

    QByteArray name_by = name.toLatin1();
    register_msg.name = name_by.toStdString();
    //strncpy(register_msg.name, name_by.data(), sizeof(register_msg.name));

    QByteArray pass_by = passwd.toLatin1();
    register_msg.passwd = pass_by.toStdString();
    //strncpy(register_msg.passwd, pass_by.data(), sizeof(register_msg.passwd));

    NetworkAgent::GetInstance().SendToServer(register_msg);
}
