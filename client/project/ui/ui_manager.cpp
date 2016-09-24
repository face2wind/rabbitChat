#include "ui_manager.hpp"

#include "loginwindow.h"
#include "registerwindow.h"

UIManager::UIManager() : login_win_(nullptr), register_win_(nullptr)
{
    login_win_ = new LoginWindow();
}

UIManager::~UIManager()
{

}

UIManager & UIManager::GetInstance()
{
    static UIManager instance;
    return instance;
}

void UIManager::ShowLogin()
{
    login_win_->show();

    if (nullptr != register_win_)
        register_win_->hide();
}

void UIManager::ShowRegister()
{
    login_win_->hide();

    if (nullptr == register_win_)
        register_win_ = new RegisterWindow();
    register_win_->show();
}

void UIManager::ShowMainView()
{

}
