#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "basket.h"
#include "action.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    //инициализация корзин
    basket1({ Ball(Color::Red), Ball(Color::Red), Ball(Color::Red), Ball(Color::Blue), Ball(Color::Red) }),
    basket2({ Ball(Color::Blue), Ball(Color::Blue), Ball(Color::Red), Ball(Color::Blue), Ball(Color::Red), Ball(Color::Red), Ball(Color::Blue) })


{
    ui->setupUi(this);     
    setValuesWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setValuesWindow()
{
    //корзина 1:
    ui->label_TotalBalls1->setText(QString::number(basket1.getTotalBalls()));
    ui->label_countBlue1->setText(QString::number(basket1.countBallsByColor(Color::Blue)));
    ui->label_countRed1->setText(QString::number(basket1.countBallsByColor(Color::Red)));
    ui->label_probabilityBlue1->setText(QString::number(Action::probabilityOneBasked(basket1, Color::Blue),'f', 2));
    ui->label_probabilityRed1->setText(QString::number(Action::probabilityOneBasked(basket1, Color::Red),'f', 2));
    //корзина 2:
    ui->label_TotalBalls2->setText(QString::number(basket2.getTotalBalls()));
    ui->label_countBlue2->setText(QString::number(basket2.countBallsByColor(Color::Blue)));
    ui->label_countRed2->setText(QString::number(basket2.countBallsByColor(Color::Red)));
    ui->label_probabilityBlue2->setText(QString::number(Action::probabilityOneBasked(basket2, Color::Blue),'f', 2));
    ui->label_probabilityRed2->setText(QString::number(Action::probabilityOneBasked(basket2, Color::Red),'f', 2));
    //вероятности комбинаций:
    ui->label_probabilityTwoBlue2->setText(QString::number(Action::probabilityTwoBalls(basket1,basket2, Color::Blue),'f', 3));
    ui->label_probabilityTwoRed2->setText(QString::number(Action::probabilityTwoBalls(basket1,basket2, Color::Red),'f', 3));
    ui->label_probabilityBlueRed2->setText(QString::number(Action::probabilityTwoBalls(basket1,basket2),'f', 2));

    ui->label_probabilityTwoBlue1_1->setText(QString::number(Action::probabilityOneBasked(basket1,Color::Blue, 2, 2),'f', 3));
    ui->label_probabilityTwoRed1_1->setText(QString::number(Action::probabilityOneBasked(basket1,Color::Red, 2, 2),'f', 3));
    ui->label_probabilityBlueRed1_1->setText(QString::number(Action::probabilityOneBasked(basket1,Color::Blue, 2, 1),'f', 3));

    ui->label_probabilityTwoBlue1_2->setText(QString::number(Action::probabilityOneBasked(basket2,Color::Blue, 2, 2),'f', 3));
    ui->label_probabilityTwoRed1_2->setText(QString::number(Action::probabilityOneBasked(basket2,Color::Red, 2, 2),'f', 3));
    ui->label_probabilityBlueRed1_2->setText(QString::number(Action::probabilityOneBasked(basket2,Color::Blue, 2, 1),'f', 3));

}

// Обновляет лейбл.
// int actionCode - параметр обвновления лейбла последнего действия.
void MainWindow::updateLabel(int actionCode) {
    QString actionText;
    switch (actionCode) {
    case 1:
        actionText = "Переложили шар из корзины 1 в корзину 2";
        break;
    case 2:
        actionText = "Переложили шар из корзины 2 в корзину 1";
        break;
    case 3:
        actionText = "Вынули 2 шара";
        break;
    default:
        actionText = "Неизвестное действие";
        break;
    }
    ui->label_actionText->setText(actionText);
}

//преложить 1 шар из 1 крозины в корзину 2
void MainWindow::on_pushButton_clicked()
{
    Action::moveRandomBall(basket1,basket2);
    setValuesWindow();
    updateLabel(1);
}

//преложить 1 шар из 2 крозины в корзину 1
void MainWindow::on_pushButton_2_clicked()
{
    Action::moveRandomBall(basket2,basket1);
    setValuesWindow();
    updateLabel(2);
}

//извлечь 2 шара из случайной корзины или двух корзин
void MainWindow::on_pushButton_3_clicked()
{
    Action::removeTwoRandomBalls(basket1,basket2);
    setValuesWindow();
    updateLabel(3);
}

