#ifndef MSG_HANDLER_HPP
#define MSG_HANDLER_HPP

#include <map>

class MessageHandler;
typedef void (MessageHandler::*MessageHandlerFunc)(const char *data, int length);

class MessageHandler
{
public:
    MessageHandler();
    ~MessageHandler();

    void OnRecv(const char *data, int length);

protected:
    void OnLoginResult(const char *data, int length);

private:
    std::map<int, MessageHandlerFunc> handler_func_map_;
};

#endif // NETWORKAGENT_H
