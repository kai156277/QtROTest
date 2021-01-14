#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("This is Server");
    init();
    ui->plainTextEdit->setReadOnly(true);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::lineEditReturnPressed);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::pushButtonClicked()
{
    QString msg = ui->lineEdit->text();
    if (!msg.isEmpty())
    {
        mInterface->sendMsg(msg);
    }

    ui->plainTextEdit->appendPlainText(QString("Server:") + msg);
    ui->lineEdit->clear();
}

void Widget::onReceiveMsg(const QString &msg)
{
    ui->plainTextEdit->appendPlainText(QString("Client:") + msg);
}

void Widget::lineEditReturnPressed()
{
    pushButtonClicked();
}

void Widget::init()
{
    mHost = new QRemoteObjectHost(this);
    mHost->setHostUrl(QUrl("tcp://192.168.1.3:812"));
    mInterface = new CommonInterface(this);
    mHost->enableRemoting(mInterface);
    connect(mInterface, &CommonInterface::sigReceiveMsg, this, &Widget::onReceiveMsg);
}
