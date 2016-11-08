#include "ui_manager.hpp"

#include <QApplication>
#include <QDesktopWidget>

#include "loginwindow.h"
#include "registerwindow.h"
#include "mainwindow.h"
#include "chatwindow.h"

#include "message_code.hpp"
#include "network/networkagent.h"

#include "protocol_def.hpp"

using namespace Protocol;

UIManager::UIManager() : login_win_(nullptr), register_win_(nullptr), main_win_(nullptr)
{
    login_win_ = new LoginWindow();

    QDesktopWidget *desktop = QApplication::desktop();
    //desktop_width_= desktop->width();
    //desktop_height_= desktop->height();

    QRect screen_rect = desktop->availableGeometry(desktop->primaryScreen());
    desktop_width_= screen_rect.width();
    desktop_height_ = screen_rect.height();
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
    this->MoveCenter(login_win_);
    login_win_->show();

    if (nullptr != register_win_)
        register_win_->hide();
    if (nullptr != main_win_)
        main_win_->hide();
}

void UIManager::ShowRegister()
{
    login_win_->hide();
    if (nullptr != main_win_)
        main_win_->hide();

    if (nullptr == register_win_)
        register_win_ = new RegisterWindow();
    this->MoveCenter(register_win_);
    register_win_->show();
}

void UIManager::ShowMainView()
{
    if (nullptr != login_win_)
        login_win_->hide();
    if (nullptr != register_win_)
        register_win_->hide();

    if (nullptr == main_win_)
        main_win_ = new MainWindow();

    if (main_win_->isHidden())
    {
        this->MoveLeft(main_win_);
        main_win_->show();
    }
    main_win_->FreshAllUserList();
}

void UIManager::OnLoginResult(int result)
{
    switch (result)
    {
    case MessageCode_REGISTER_SUCC:
        register_win_->OnRegisterSucc();
        break;

    case MessageCode_ALEADY_HAS_ACCOUNT:
        register_win_->OnHasAccount();
        break;

    case MessageCode_LOGIN_SUCC:
        this->ShowMainView();
        this->RequestFriendList();
        break;

    case MessageCode_NO_THIS_ACCOUNT:
        login_win_->OnNoThisAccount();
        break;

    case MessageCode_PASSWD_WRONG:
        login_win_->OnPasswdWrong();
        break;

    default:
        break;
    }
}

void UIManager::ShowChatWindow(unsigned int user_id)
{
    auto chat_window_it = chat_window_map_.find(user_id);
    if (chat_window_it != chat_window_map_.end())
    {
        chat_window_it->second->show();
        chat_window_it->second->SetUserID(user_id);
    }
    else
    {
        ChatWindow *window = new ChatWindow();
        window->show();
        window->SetUserID(user_id);
        chat_window_map_[user_id] = window;
    }
}

void  UIManager::RequestFriendList()
{
    static Protocol::CSRequestAllUserList req;
    NetworkAgent::GetInstance().SendToServer(req);
}

void UIManager::MoveCenter(QMainWindow *window)
{
    if (nullptr != window)
        window->move((desktop_width_ - window->width())/2,(desktop_height_ - window->height())/2);
}

void UIManager::MoveLeft(QMainWindow *window)
{
    if (nullptr != window)
        window->move(100,(desktop_height_ - window->height())/2);
}
