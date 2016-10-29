#include "msg_handler.h"
#include "protocol_def.hpp"
#include "ui/ui_manager.hpp"
#include <QtCore>

using namespace Protocol;

MessageHandler::MessageHandler()
{
    handler_func_map_["10002"] = &MessageHandler::OnLoginResult;
}

MessageHandler::~MessageHandler()
{
}

void MessageHandler::OnRecv(const face2wind::SerializeBase *data)
{
    auto func_it_ = handler_func_map_.find(data->GetTypeName());
    if (func_it_ == handler_func_map_.end())
        qDebug()<<"unknow msg type : "<<data->GetTypeName().c_str();
    else
        (this->*(func_it_->second))(data);
}

void MessageHandler::OnLoginResult(const face2wind::SerializeBase *data)
{
    SCLoginResult *msg = (SCLoginResult*)data;
    qDebug()<<"login result : "<<msg->result;
    UIManager::GetInstance().OnLoginResult(msg->result);
}
