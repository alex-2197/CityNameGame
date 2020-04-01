#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Start_clicked();

    void on_pushButton_Exit_clicked();

    void on_pushButton_Continue_clicked();

private:
    bool isGameStarted;


    Ui::MainWindow *ui;
    Game *gameWindow;
};
#endif // MAINWINDOW_H
