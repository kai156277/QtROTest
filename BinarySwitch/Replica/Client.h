#pragma once

#include <QObject>
#include <QSharedPointer>

#include "rep_SimpleSwitch_replica.h"

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QSharedPointer<SimpleSwitchReplica> ptr);
    ~Client();
    void initConnections();

Q_SIGNALS:
    // this signal is connected with server_slot() on the source object and
    // echoes back switch state received from source
    void echoSwitchState(bool switchState);

public Q_SLOTS:
    void recSwitchState_slot();

private:
    bool clientSwitchState;

    QSharedPointer<SimpleSwitchReplica> reptr;
};
