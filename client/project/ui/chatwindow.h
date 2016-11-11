#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <deque>

namespace Ui {
class ChatWindow;
}

struct ChatMessageItem
{
    unsigned int sender_id;
    unsigned int receiver_id;
    std::string message;
};

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);
    ~ChatWindow();

    void SetUserID(unsigned int user_id);
    void AddMessage(unsigned int sender_id, unsigned int receiver_id, const std::string &message);

protected:
    bool eventFilter(QObject *obj, QEvent *e);

private:
    void DoSendText();
    void RefreshMessage();

private slots:
    void on_send_btn_clicked();

private:
    Ui::ChatWindow *ui;
    unsigned int target_user_id_;
    std::deque<ChatMessageItem> message_list_;
};

#endif // CHATWINDOW_H
