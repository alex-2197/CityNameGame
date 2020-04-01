#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Start_clicked()
{
    hide();
    gameWindow = new Game(this);
    isGameStarted = true;
    ui->pushButton_Continue->setEnabled(true);
    gameWindow->show();
}

void MainWindow::on_pushButton_Exit_clicked()
{
    close();
}

void MainWindow::on_pushButton_Continue_clicked()
{
    hide();
    gameWindow->show();
}
