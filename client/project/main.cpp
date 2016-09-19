#include "loginwindow.h"
#include <QApplication>

#include "network_manager/networkagent.h"

int main(int argc, char *argv[])
{
    NetworkAgent::GetInstance();

    QApplication a(argc, argv);
    LoginWindow w;
    w.show();

    return a.exec();
}
