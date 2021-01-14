#include "SimpleSwitch.h"

SimpleSwitch::SimpleSwitch(QObject *parent)
    : SimpleSwitchSimpleSource(parent)
{
    stateChangeTimer = new QTimer(this);
    QObject::connect(stateChangeTimer, SIGNAL(timeout()), this, SLOT(timeout_slot()));
    stateChangeTimer->start(2000);
    qDebug() << "Source Node Started";
}

SimpleSwitch::~SimpleSwitch()
{
    stateChangeTimer->stop();
    delete stateChangeTimer;
}

void SimpleSwitch::server_slot(bool clientState)
{
    qDebug() << "Replica state is" << clientState;
}

void SimpleSwitch::timeout_slot()
{
    if (currState())
        setCurrState(false);
    else
        setCurrState(true);

    qDebug() << "Source State is" << currState();
}
