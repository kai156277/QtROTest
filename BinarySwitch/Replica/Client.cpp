#include "Client.h"

Client::Client(QSharedPointer<SimpleSwitchReplica> ptr)
    : QObject(nullptr)
    , reptr(ptr)
{
    initConnections();
}

Client::~Client()
{
}

void Client::initConnections()
{
    connect(reptr.data(), SIGNAL(currStateChanged(bool)), this, SLOT(recSwitchState_slot()));
    connect(this, SIGNAL(echoSwitchState(bool)), reptr.data(), SLOT(server_slot(bool)));
}

void Client::recSwitchState_slot()
{
    qDebug() << "Received source state" << reptr.data()->currState();
    clientSwitchState = reptr.data()->currState();
    Q_EMIT echoSwitchState(clientSwitchState);
}
