#include <QApplication>

#include "ui/ui_manager.hpp"
#include "network_manager/networkagent.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    NetworkAgent::GetInstance();
    UIManager::GetInstance().ShowLogin();

    return a.exec();
}
