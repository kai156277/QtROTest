#include <QCoreApplication>
#include <QSharedPointer>

#include "Client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSharedPointer<SimpleSwitchReplica> ptr;

    QRemoteObjectNode repNode;
    repNode.connectToNode(QUrl(QStringLiteral("local:switch")));
    ptr.reset(repNode.acquire<SimpleSwitchReplica>());

    Client rswitch(ptr);

    return a.exec();
}
