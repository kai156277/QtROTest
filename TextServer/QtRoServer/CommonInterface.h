#pragma once

#include "rep_commoninterface_source.h"

class CommonInterface : public CommonInterfaceSource
{
    Q_OBJECT
public:
    explicit CommonInterface(QObject *parent = nullptr);
    virtual void onMessage(QString msg);
    void         sendMsg(const QString &msg);
signals:
    void sigReceiveMsg(const QString &msg);
};
