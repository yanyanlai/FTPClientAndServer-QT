// servermainwindow.cpp

#include "servermainwindow.h"
#include <QDir>


ServerMainWindow::ServerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    tcpServer(new QTcpServer(this))
{
    connect(tcpServer, &QTcpServer::newConnection, this, &ServerMainWindow::newConnection);

    if (!tcpServer->listen(QHostAddress::Any, 1234)) {
        qWarning() << "Unable to start the server:" << tcpServer->errorString();
        close();
    } else {
        qDebug() << "Server started!";
    }
}

ServerMainWindow::~ServerMainWindow()
{
    // 在析构函数中关闭服务器
    tcpServer->close();
    delete tcpServer;
}

void ServerMainWindow::newConnection()
{
    while (tcpServer->hasPendingConnections()) {
        QTcpSocket *client = tcpServer->nextPendingConnection();
        clients.append(client);
        connect(client, &QIODevice::readyRead, this, &ServerMainWindow::processData);
    }
}

void ServerMainWindow::processData()
{
    for (QTcpSocket *client : qAsConst(clients)) {
        if (client->bytesAvailable() > 0) {
            QByteArray data = client->readAll();
            qDebug() << "Received data from client:" << data;

            // 解析 FTP 命令
            QString command = QString(data).trimmed().toUpper();  // 转为大写并去除首尾空格

            if (command == "LIST") {
                // 如果收到 LIST 命令，发送文件列表
                QDir currentDir(".");
                QStringList fileList = currentDir.entryList(QDir::Files);

                QString response = "File List:\n" + fileList.join("\n");

                client->write(response.toUtf8());
            } else if (command == "PWD") {
                // 如果收到 PWD 命令，发送当前工作目录
                QString currentDir = QDir::currentPath();
                client->write(currentDir.toUtf8());
            } else if (command.startsWith("CWD")) {
                // 如果收到 CWD 命令，切换当前工作目录
                QString path = command.mid(3).trimmed();  // 获取 CWD 命令后面的路径
                QDir currentDir(".");

                if (currentDir.cd(path)) {
                    client->write("Directory changed to: " + currentDir.path().toUtf8());
                } else {
                    client->write("Failed to change directory.");
                }
            } else if (command.startsWith("RETR")) {
                // 如果收到 RETR 命令，发送文件内容
                QString fileName = command.mid(4).trimmed();  // 获取 RETR 命令后面的文件名
                QFile file(fileName);

                if (file.open(QIODevice::ReadOnly)) {
                    QByteArray fileData = file.readAll();
                    client->write(fileData);
                    file.close();
                } else {
                    client->write("Failed to retrieve file.");
                }
            } else {
                // 处理其他 FTP 命令，可以根据需要进行扩展
                client->write("Unknown command: " + command.toUtf8());
            }
        }
    }
}


