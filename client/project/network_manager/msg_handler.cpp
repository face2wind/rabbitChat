#include "msg_handler.h"
#include <QtCore>


void MessageHandler::OnRecv(const char *data, int length)
{
    qDebug()<<"receive : ["<<data<<"] size("<<length<<")";
}
