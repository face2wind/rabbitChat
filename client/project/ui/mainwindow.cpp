#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "controller/login_controller.hpp"
#include "ui/ui_manager.hpp"
#include "model/chat_manager.hpp"

#include <QStringListModel>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), request_user_list_timer_(nullptr)
{
    ui->setupUi(this);
    this->UpdateFriendList();

    request_user_list_timer_ = new QTimer(this);
    connect(request_user_list_timer_, SIGNAL(timeout()), this, SLOT(RequestUserList()));
    request_user_list_timer_->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateFriendList()
{
    QStringListModel *data = new QStringListModel(ui->friend_list_view);
    QStringList list;
    list<<"朋友1"<<"拉登本~~"<<"白熊咖啡厅";
    data->setStringList(list);
    ui->friend_list_view->setModel(data);
}

void MainWindow::FreshAllUserList()
{
    const std::vector<Protocol::UserItem> &u_list = ChatManager::GetInstance().GetAllUserList();
    QStringListModel *data = new QStringListModel(ui->friend_list_view);
    QStringList list;
    user_id_list_.clear();
    for (Protocol::UserItem item : u_list)
    {
        list<<item.name.c_str();
        user_id_list_.push_back(item.id);
    }
    data->setStringList(list);
    ui->friend_list_view->setModel(data);

    request_user_list_timer_->start(1000);
}

void MainWindow::on_friend_list_view_doubleClicked(const QModelIndex &index)
{
    if (index.row() > user_id_list_.size())
        return;

    qDebug()<<"user id = "<<user_id_list_[index.row()];
    UIManager::GetInstance().ShowChatWindow(user_id_list_[index.row()]);
}

void MainWindow::RequestUserList()
{
    UIManager::GetInstance().RequestFriendList();
}
