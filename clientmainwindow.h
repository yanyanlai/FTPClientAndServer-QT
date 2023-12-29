// clientmainwindow.h

#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class ClientMainWindow;
}

class ClientMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientMainWindow(QWidget *parent = nullptr);
    ~ClientMainWindow();

private slots:
    void on_connectButton_clicked();
    void on_sendButton_clicked();
    void on_disconnectButton_clicked();

    void readData();

private:
    Ui::ClientMainWindow *ui;
    QTcpSocket *tcpSocket;
};

#endif // CLIENTMAINWINDOW_H
