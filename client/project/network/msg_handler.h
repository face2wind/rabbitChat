#ifndef MSG_HANDLER_HPP
#define MSG_HANDLER_HPP

#include <map>

class MessageHandler;
typedef void (MessageHandler::*MessageHandlerFunc)(const char *data);

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

    void OnRecv(const char *data, int length);

protected:
    void OnLoginResult(const char *data);

private:
    std::map<int, HandlerItem> handler_func_map_;
};

#endif // NETWORKAGENT_H
