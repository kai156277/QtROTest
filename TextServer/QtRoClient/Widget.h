#pragma once

#include <QRemoteObjectNode>
#include <QWidget>

#include "rep_CommonInterface_replica.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onReciveMsg(QString msg);
    void pushButtonClicked();
    void lineEditReturnPressed();

private:
    void init();

private:
    Ui::Widget *            ui;
    QRemoteObjectNode *     mRemoteNode = nullptr;
    CommonInterfaceReplica *mInterface  = nullptr;
};
