#include "chatwindow.h"
#include "model/chat_manager.hpp"
#include "ui_chatwindow.h"
#include "network/networkagent.h"
#include <QKeyEvent>

ChatWindow::ChatWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatWindow), target_user_id_(0)
{
    ui->setupUi(this);
    ui->input_text->installEventFilter(this);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::SetUserID(unsigned int user_id)
{
    const Protocol::UserItem *user = ChatManager::GetInstance().GetUserInfo(user_id);
    if (nullptr == user)
        return;

    target_user_id_ = user_id;
    ui->user_name_label->setText(user->name.c_str());
}

void ChatWindow::AddMessage(unsigned int sender_id, unsigned int receiver_id, const std::string &message)
{
    ChatMessageItem item;
    item.sender_id = sender_id;
    item.receiver_id = receiver_id;
    item.message = message;
    message_list_.push_back(item);

    if (message_list_.size() >= 50)
    {
        message_list_.pop_front();
    }

    this->RefreshMessage();
}

bool ChatWindow::eventFilter(QObject *obj, QEvent *e)
{
    Q_ASSERT(obj == ui->input_text);
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent *event = static_cast<QKeyEvent*>(e);
        if (event->key() == Qt::Key_Return)// && (event->modifiers() & Qt::ControlModifier))
        {
            //sendMsg(); //发送消息的槽
            this->DoSendText();
            return true;
        }
    }
    return false;
}

void ChatWindow::DoSendText()
{
    static Protocol::CSChatToUser msg;
    msg.chat_message = ui->input_text->toPlainText().toStdString();
    msg.user_id = target_user_id_;
    NetworkAgent::GetInstance().SendToServer(msg);

    ui->input_text->setText("");
}

void ChatWindow::RefreshMessage()
{
    QString total_str;
    for (auto item : message_list_)
    {
        if (item.sender_id == target_user_id_)
        {
            total_str += ("<b><font color='#ff00ff'>对方：</font></b><br>");
            total_str += ("&nbsp;&nbsp;<font color='#ff70ff'>"+QString(item.message.c_str()) + "</font><br/>");
        }
        else
        {
            total_str += ("<b><font color='#008040'>我：</font></b><br>");
            total_str += ("&nbsp;&nbsp;<font color='#404244'>"+QString(item.message.c_str()) + "</font><br/>");
        }
    }
    ui->history_text->setHtml(total_str);

    QTextCursor cursor = ui->history_text->textCursor();

    QTextBlockFormat format = cursor.blockFormat();
    format.setLineHeight(10, QTextBlockFormat::LineDistanceHeight);
    cursor.setBlockFormat(format);

    cursor.movePosition(QTextCursor::End);
    ui->history_text->setTextCursor(cursor);
}

void ChatWindow::on_send_btn_clicked()
{
    this->DoSendText();
}
