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

void ChatWindow::on_send_btn_clicked()
{
    this->DoSendText();
}
