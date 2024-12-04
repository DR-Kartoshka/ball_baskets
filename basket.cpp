#include "basket.h"

// Добавить шар в корзину
// ball - шар
void Basket::addBall(const Ball& ball) {
    balls.push_back(ball);
}
// Достать случайный шар из корзины
Ball Basket::removeRandomBall() {

        if (balls.empty()) {
            throw std::runtime_error("Basket is empty!");
        }
        int index = rand() % balls.size(); // выбор случайного интекса

        //удаление элемента
        Ball removedBall = balls[index];
        balls.erase(balls.begin() + index); //(balls.begin() + index) — это итератор, указывающий на index-й элемент вектора / метод erase() удаляет элемент
        return removedBall;
}

// Получить общее количество шаров
int Basket::getTotalBalls() {
    return balls.size();
}
// Метод для получения всех шаров в корзине
const std::vector<Ball>& Basket::getBalls() const {
    return balls;
}
// Количество шаров определенного цвета
// color - цвет шара
int Basket::countBallsByColor(Color color) const {
    int count = 0;
    for (const auto& ball : balls) {
        if (ball.getColor() == color) {
            ++count;
        }
    }
    return count;
}
