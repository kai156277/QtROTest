#pragma once

#include "CommonInterface.h"
#include <QRemoteObjectHost>
#include <QWidget>

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
    void pushButtonClicked();
    void onReceiveMsg(const QString &msg);
    void lineEditReturnPressed();

private:
    void               init();
    Ui::Widget *       ui;
    CommonInterface *  mInterface = nullptr;
    QRemoteObjectHost *mHost      = nullptr;
};
