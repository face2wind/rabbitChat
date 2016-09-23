#include "message_handler.hpp"
#include "net_msg/login_msg.hpp"
#include "player/player_manager.hpp"

using namespace protocol;

MessageHandler::MessageHandler()
{
  handler_func_map_[10001] = &MessageHandler::OnLoginRequest;
}

MessageHandler::~MessageHandler()
{

}

void MessageHandler::OnRecv(face2wind::NetworkID net_id, const char *data, int length)
{
  MsgHead *head = (MsgHead*)data;
  std::map<int, MessageHandlerFunc>::iterator func_it_ = handler_func_map_.find(head->msg_code);
  if (func_it_ != handler_func_map_.end())
    (this->*(func_it_->second))(net_id, data, length);
  else
    std::cout<<"unknow msg code : "<<head->msg_code<<std::endl;
}

void MessageHandler::OnLoginRequest(face2wind::NetworkID net_id, const char *data, int length)
{
  CSLogin *login_req = (CSLogin*)data;
  std::cout<<"receive login req : name("<<login_req->name<<") password ("<<login_req->passwd<<")"<<std::endl;
  PlayerManager::GetInstance().GetPlayerWithAccountName(net_id, login_req->name, login_req->passwd);
}

