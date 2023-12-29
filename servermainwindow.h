// servermainwindow.h

#ifndef SERVERMAINWINDOW_H
#define SERVERMAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class ServerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerMainWindow(QWidget *parent = nullptr);
    ~ServerMainWindow();

private slots:
    void newConnection();
    void processData();

private:
    QTcpServer *tcpServer;
    QList<QTcpSocket*> clients;
};

#endif // SERVERMAINWINDOW_H
