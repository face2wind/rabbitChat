#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void UpdateFriendList();
    void FreshAllUserList();

private slots:
    void on_friend_list_view_doubleClicked(const QModelIndex &index);
    void RequestUserList();

private:
    Ui::MainWindow *ui;
    std::vector<unsigned int> user_id_list_;
    QTimer *request_user_list_timer_;
};

#endif // MAINWINDOW_H
