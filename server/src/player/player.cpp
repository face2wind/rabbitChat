#include "player.hpp"
#include "network/network_agent.hpp"

void Player::OnLogin()
{
  is_online_ = true;
}

void Player::OnLogout()
{
  is_online_ = false;
  if (net_id_ > 0) // disconnect old client
    NetworkAgent::GetInstance().Disconnect(net_id_);
}
