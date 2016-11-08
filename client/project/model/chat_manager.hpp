#ifndef CHAT_MANAGER_HPP
#define CHAT_MANAGER_HPP

#include <vector>
#include "protocol_def.hpp"

class ChatManager
{
public:
    static ChatManager & GetInstance();
    const std::vector<Protocol::UserItem> &GetAllUserList() { return user_list_; }
    void UpdateAllUserList(const std::vector<Protocol::UserItem> &user_list) { user_list_ = user_list; }
    const Protocol::UserItem *GetUserInfo(unsigned int user_id);

protected:
    std::vector<Protocol::UserItem> user_list_;
};

#endif // CHAT_MANAGER_HPP
