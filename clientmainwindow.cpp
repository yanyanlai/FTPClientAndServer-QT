// clientmainwindow.cpp
#include <QTableWidget>

#include "clientmainwindow.h"
#include "ui_clientmainwindow.h"

ClientMainWindow::ClientMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientMainWindow),
    tcpSocket(new QTcpSocket(this))
{
    ui->setupUi(this);

    connect(tcpSocket, &QTcpSocket::readyRead, this, &ClientMainWindow::readData);
    // 在ClientMainWindow的构造函数中添加如下代码
    ui->portSpinBox->setMaximum(65535);  // 设置端口号的最大值为65535

}

ClientMainWindow::~ClientMainWindow()
{
    delete ui;
}

void ClientMainWindow::on_connectButton_clicked()
{
    QString serverAddress = ui->serverAddressEdit->text();
    qint16 serverPort = ui->portSpinBox->value();

    tcpSocket->connectToHost(serverAddress, serverPort);

    if (tcpSocket->waitForConnected()) {
        qDebug() << "Connected to server!";
    } else {
        qWarning() << "Unable to connect to server:" << tcpSocket->errorString();
    }
}

void ClientMainWindow::on_sendButton_clicked()
{
    QString command = ui->commandEdit->text();
    tcpSocket->write(command.toUtf8());
}

void ClientMainWindow::on_disconnectButton_clicked()
{
    tcpSocket->disconnectFromHost();
}

void ClientMainWindow::readData()
{
    QByteArray data = tcpSocket->readAll();
    // Process FTP server response
    ui->responseTextEdit->append("Received data from server: " + QString(data));
    qDebug() << "Received data from server:" << data;
}
