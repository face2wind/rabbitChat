#include "message_handler.hpp"
#include "net_msg/login_msg.hpp"
#include "player/player_manager.hpp"

using namespace protocol;

MessageHandler::MessageHandler()
{
  handler_func_map_[10000] = &MessageHandler::OnRegisterRequest;
  handler_func_map_[10001] = &MessageHandler::OnLoginRequest;
}

MessageHandler::~MessageHandler()
{

}

void MessageHandler::OnRecv(face2wind::NetworkID net_id, const char *data, int length)
{
  MsgHead *head = (MsgHead*)data;
  auto func_it_ = handler_func_map_.find(head->msg_code);
  if (func_it_ != handler_func_map_.end())
    (this->*(func_it_->second))(net_id, data, length);
  else
    std::cout<<"unknow msg code : "<<head->msg_code<<std::endl;
}

void MessageHandler::OnRegisterRequest(face2wind::NetworkID net_id, const char *data, int length)
{
  CSRegisterAccount *reg_msg = (CSRegisterAccount*)data;
  reg_msg->name[sizeof(reg_msg->name) - 1] = '\0';
  reg_msg->passwd[sizeof(reg_msg->passwd) - 1] = '\0';
  std::cout<<"receive register req : name("<<reg_msg->name<<") password ("<<reg_msg->passwd<<")"<<std::endl;
  PlayerManager::GetInstance().OnRegisterPlayer(net_id, reg_msg->name, reg_msg->passwd);
}

void MessageHandler::OnLoginRequest(face2wind::NetworkID net_id, const char *data, int length)
{
  CSLogin *login_req = (CSLogin*)data;
  login_req->name[sizeof(login_req->name) - 1] = '\0';
  login_req->passwd[sizeof(login_req->passwd) - 1] = '\0';
  std::cout<<"receive login req : name("<<login_req->name<<") password ("<<login_req->passwd<<")"<<std::endl;
  PlayerManager::GetInstance().OnPlayerLogin(net_id, login_req->name, login_req->passwd);
}


