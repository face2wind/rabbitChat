#ifndef MSG_HANDLER_HPP
#define MSG_HANDLER_HPP

class MessageHandler
{
public:
    void OnRecv(const char *data, int length);
};

#endif // NETWORKAGENT_H
