#include "game.h"
#include "ui_game.h"


Game::Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    ui->label_Comand->setText("");
    ui->label_City->setText("");

    takeNamesFromFile();
    chooseFirstName();


}
Game::~Game()
{
    delete ui;
}

void Game::on_pushButton_Exit_clicked()
{
    parentWidget()->show();
    hide();
}



void Game::on_pushButton_CityInput_clicked()
{
   QString userCityName = ui->lineEdit_CityInput->text();
   userCityName[0] = userCityName[0].toUpper();
   userCityName.replace(" ","");
   int searchAnswer = searchName(userCityName);
    ui->lineEdit_CityInput->setText("");

    if (searchAnswer >= 0){
        moveNames(true, searchAnswer);
        chooseName();
    } else if (searchAnswer == -1){
        ui->label_Comand->setText("Город уже был!");

    }else if (searchAnswer == -2){
        ui->label_Comand->setText("Такого города нет!");

    }else if (searchAnswer == -3){
        ui->label_Comand->setText("Город должен начинаться на " + currentWord + "!");

    }else {
        ui->label_Comand->setText("Ошибка поиска названия!");
    }
}

void Game::takeNamesFromFile()
{

   QFile file(":/txt/CityName.txt");
   QString str;

    if (!file.open(QFile::ReadOnly | QFile::Text))
        {
        ui->label_Comand->setText("Ошибка открытия файла загрузки!");
    } else {

            while (!file.atEnd()) {

                str = file.readLine();
                str.replace("\n","");

             if(words.contains(QString(str[0]))){
                 cityNames.append(str);
                }else{
                 cityNames.append(str);
                 words.insert(QString(str[0]), words.count() + 1);
             }


            }
            file.close();
    }
}

int Game::searchName(QString name)
{
    if (name[0] == currentWord){
    for (int i = 0; i < cityNamesUsed.count(); i++) {
        if(cityNamesUsed[i] == name){
            return -1;
        }
    }

    for (int i = 0; i < cityNames.count(); i++) {
        if(cityNames[i] == name){
            return i;
        }
    }
    return -2;
  }else {
        return -3;
    }

}

void Game::chooseName()
{
    for (int i = 0; i < cityNames.count(); i++) {
        if(cityNames[i].startsWith(currentWord)){
            moveNames(false, i);
            break;
        }
    }
}

void Game::chooseFirstName()
{
    moveNames(false, qrand() % cityNames.length());
}

void Game::moveNames(bool isUser,int i)
{
    if (isUser == false){
    cityNamesUsed.append(cityNames[i]);
    chooseCurrentWord(cityNames[i]);
    ui->label_City->setText(cityNames[i]);
    ui->label_Comand->setText("Тебе на " + currentWord + "!");
    cityNames.remove(i);
    } else {
        cityNamesUsed.append(cityNames[i]);
       chooseCurrentWord(cityNames[i]);
        cityNames.remove(i);
    }
}

void Game::chooseCurrentWord(QString name)
{
    for (int i = name.length()-1; i > 0; i--) {
        if(words.contains(QString(name[i].toUpper()))){
            currentWord = QString(name[i].toUpper());
            break;
        }
    }
}
