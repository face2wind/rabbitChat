#include "msg_handler.h"
#include "net_msg/login_msg.hpp"
#include <QtCore>

MessageHandler::MessageHandler()
{
    handler_func_map_[10002] = &MessageHandler::OnLoginResult;
}

MessageHandler::~MessageHandler()
{
}

void MessageHandler::OnRecv(const char *data, int length)
{
    protocol::MsgHead *head = (protocol::MsgHead*)data;
    auto func_it_ = handler_func_map_.find(head->msg_code);
    if (func_it_ != handler_func_map_.end())
        (this->*(func_it_->second))(data, length);
    else
        qDebug()<<"unknow msg code : "<<head->msg_code;
}

void MessageHandler::OnLoginResult(const char *data, int length)
{
    qDebug()<<"receive : ["<<data<<"] size("<<length<<")";

}
