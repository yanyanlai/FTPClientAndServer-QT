// mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "servermainwindow.h"
#include "clientmainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startServerButton_clicked()
{
    ServerMainWindow *serverWindow = new ServerMainWindow(this);
    //serverWindow->show();
}

void MainWindow::on_startClientButton_clicked()
{
    ClientMainWindow *clientWindow = new ClientMainWindow(this);
    clientWindow->show();
}
