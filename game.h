#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QVector>
#include <QMap>
#include "QFile"
#include "QTime"


namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private slots:
    void on_pushButton_Exit_clicked();

    void on_pushButton_CityInput_clicked();

private:
    Ui::Game *ui;

    QVector<QString> cityNames;
    QVector<QString> cityNamesUsed;

    QString currentWord;
    QMap<QString,int> words;

    void takeNamesFromFile();
    int searchName(QString);
    void chooseName();
    void chooseFirstName();
    void moveNames(bool,int);
    void chooseCurrentWord(QString);

};

#endif // GAME_H
