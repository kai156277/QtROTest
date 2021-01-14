﻿#include "SimpleSwitch.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SimpleSwitch srcSwitch;

    QRemoteObjectHost srcNode(QUrl(QStringLiteral("local:switch")));
    srcNode.enableRemoting(&srcSwitch);

    return a.exec();
}
