#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "controller/login_controller.hpp"
#include "ui/ui_manager.hpp"
#include <QStringListModel>
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->UpdateFriendList();
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

void MainWindow::on_friend_list_view_doubleClicked(const QModelIndex &index)
{
    //qDebug()<<index.model()->;
}
