#include "message_handler.hpp"
#include <net_msg/login_msg.hpp>

void MessageHandler::OnRecv(face2wind::NetworkID net_id, const char *data, int length)
{
  std::cout<<"receive some one : netid("<<net_id<<") data ["<<data<<"]"<<std::endl;

}
