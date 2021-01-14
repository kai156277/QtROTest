#pragma once
#include <QObject>
#include <QTimer>

#include "rep_SimpleSwitch_source.h"

class SimpleSwitch : public SimpleSwitchSimpleSource
{
    Q_OBJECT
public:
    SimpleSwitch(QObject *parent = nullptr);
    ~SimpleSwitch();

    // which is called automatically on the source whenever any replica calls
    // their version of the slot -- outputs the received value.
    virtual void server_slot(bool clientState);

    // defined in the base class. is emitted whenever currState toggles.
    // In this example, we ignore the signal on the source side, and handle it
    // later on the replica side.
    // void currStateChanged(bool)

public Q_SLOTS:
    // connected to stateChangeTimer`s timeout() signal.
    void timeout_slot();

private:
    // used to toggle the state of our SimpleSwitch
    QTimer *stateChangeTimer;
};
