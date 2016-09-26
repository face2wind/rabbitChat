#include "msg_handler.h"
#include "net_msg/login_msg.hpp"
#include "ui/ui_manager.hpp"
#include <QtCore>

using namespace protocol;

MessageHandler::MessageHandler()
{
    handler_func_map_[10002] = HandlerItem(&MessageHandler::OnLoginResult, sizeof(SCLoginResult));
}

MessageHandler::~MessageHandler()
{
}

void MessageHandler::OnRecv(const char *data, int length)
{
    MsgHead *head = (MsgHead*)data;
    auto func_it_ = handler_func_map_.find(head->msg_code);
    if (func_it_ == handler_func_map_.end())
        qDebug()<<"unknow msg code : "<<head->msg_code;
    else if (length < func_it_->second.data_size)
        qDebug()<<"msg("<<head->msg_code<<") size("<<length<<") < "<<func_it_->second.data_size;
    else
        (this->*(func_it_->second.func))(data);
}

void MessageHandler::OnLoginResult(const char *data)
{
    SCLoginResult *msg = (SCLoginResult*)data;
    qDebug()<<"login result : "<<msg->result;
    UIManager::GetInstance().OnLoginResult(msg->result);
}
