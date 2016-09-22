#include "player_manager.hpp"


PlayerManager::PlayerManager()
{

}

PlayerManager::~PlayerManager()
{

}

PlayerManager & PlayerManager::GetInstance()
{
  static PlayerManager instance;
  return instance;
}
