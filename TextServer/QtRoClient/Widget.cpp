#include "Widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("This is Client");
    init();
    ui->textEdit->setReadOnly(true);
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::lineEditReturnPressed);
}

Widget::~Widget()
{
    delete ui;
}

// receive msg
void Widget::onReciveMsg(QString msg)
{
    ui->textEdit->append(QString("Server:") + msg);
}

void Widget::pushButtonClicked()
{
    QString msg = ui->lineEdit->text();
    if (!msg.isEmpty())
    {
        mInterface->onMessage(msg);
    }
    ui->textEdit->append(QString("Client:") + msg);
    ui->lineEdit->clear();
}

void Widget::lineEditReturnPressed()
{
    pushButtonClicked();
}

void Widget::init()
{
    mRemoteNode = new QRemoteObjectNode(this);
    mRemoteNode->connectToNode(QUrl("tcp://192.168.1.3:812"));
    mInterface = mRemoteNode->acquire<CommonInterfaceReplica>();

    connect(mInterface, &CommonInterfaceReplica::sigMessage, this, &Widget::onReciveMsg);
}
