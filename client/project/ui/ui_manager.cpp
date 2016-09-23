#include "ui_manager.hpp"

#include "loginwindow.h"

UIManager::UIManager()
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
}

void UIManager::ShowRegister()
{

}

void UIManager::ShowMainView()
{

}
