#include "chat_manager.hpp"
#include "ui/ui_manager.hpp"

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

void ChatManager::UpdateAllUserList(const std::vector<Protocol::UserItem> &user_list)
{
    bool data_change = false;

    int size = user_list.size();
    if (user_list_.size() == size)
    {
        for (int index = 0; index < size; ++ index)
            if (user_list[index].id != user_list_[index].id)
                data_change = true;
    }
    else
    {
        data_change = true;
    }

    if (data_change)
    {
        user_list_ = user_list;
        UIManager::GetInstance().OnUserListChange();
    }
}

void ChatManager::OnReceiveChatMsg(int sender_id, int receiver_id, const std::string &message)
{
    UIManager::GetInstance().OnReceiveChat(sender_id, receiver_id, message);
}
