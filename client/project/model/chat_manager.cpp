#include "chat_manager.hpp"

ChatManager & ChatManager::GetInstance()
{
    static ChatManager instance;
    return instance;
}

const Protocol::UserItem *ChatManager::GetUserInfo(unsigned int user_id)
{
    for (auto user_it = user_list_.begin(); user_it != user_list_.end(); ++ user_it)
    {
        if (user_it->id == user_id)
        {
            return &(*user_it);
        }
    }

    return nullptr;
}
