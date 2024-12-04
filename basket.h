#ifndef BASKET_H
#define BASKET_H
#include "ball.h"
#include <iostream>
#include <vector>

// Реализация класса корзины
class Basket {
public:
    // Конструктор, инициализирующий корзину списком шаров
    Basket(std::vector<Ball> balls) : balls(std::move(balls)) {}

    //добавить шар в корзину
    void addBall(const Ball& ball);

    // достать случайный шар из корзины
    Ball removeRandomBall();

    // получить общее количество шаров
    int getTotalBalls();

    // Метод для получения всех шаров в корзине
    const std::vector<Ball>& getBalls() const;

    // количество шаров определенного цвета
    int countBallsByColor(Color color) const;

private:
    std::vector<Ball> balls; //контейнер хранения шаров

};

#endif // BASKET_H
