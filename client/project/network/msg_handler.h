#ifndef MSG_HANDLER_HPP
#define MSG_HANDLER_HPP

#include <map>
#include <memory/serialize/serialize_base.hpp>

class MessageHandler;
typedef void (MessageHandler::*MessageHandlerFunc)(const face2wind::SerializeBase *data);

struct HandlerItem
{
    HandlerItem() : func(0), data_size(0) {}
    HandlerItem(MessageHandlerFunc f, int s) : func(f), data_size(s) {}

    MessageHandlerFunc func;
    int data_size;
};

class MessageHandler
{
public:
    MessageHandler();
    ~MessageHandler();

    void OnRecv(const face2wind::SerializeBase *data);

protected:
    void OnLoginResult(const face2wind::SerializeBase *data);

private:
    std::map<std::string, MessageHandlerFunc> handler_func_map_;
};

#endif // NETWORKAGENT_H
