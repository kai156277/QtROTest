#include "CommonInterface.h"
#include <QDebug>

CommonInterface::CommonInterface(QObject *parent)
    : CommonInterfaceSource(parent)
{
}

// receive message
void CommonInterface::onMessage(QString msg)
{
    emit sigReceiveMsg(msg);
}

// send message
void CommonInterface::sendMsg(const QString &msg)
{
    emit sigMessage(msg);
}
