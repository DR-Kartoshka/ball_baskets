#include "action.h"
#include "factorial.h"
#include <cstdint>


//переложить 1 шар из одиной корзины в другую
void Action::moveRandomBall(Basket& fromBasket, Basket& toBasket) {
    if (fromBasket.getTotalBalls() > 0) {
        Ball ball = fromBasket.removeRandomBall();
        toBasket.addBall(ball);
    }
}

//достать 2 рандомных шара из двух случайных корзин или из одной
std::vector<Ball> Action::removeTwoRandomBalls(Basket& basket1, Basket& basket2) {
    std::vector<Ball> removedBalls;
    int choice = rand() % 2; // 0: оба из одной корзины, 1: по одному из каждой

    if (choice == 0) {
        if (basket1.getTotalBalls() > 1 || basket2.getTotalBalls() > 1) {
            Basket& targetBasket = basket1.getTotalBalls() > 1 ? basket1 : basket2;
            for(int i = 1; i <= 2; ++i){
                removedBalls.push_back(targetBasket.removeRandomBall());
            }
        }
       return removedBalls;
    }

    else {
        if (basket1.getTotalBalls() > 0) {
            removedBalls.push_back(basket1.removeRandomBall());
        }
        if (basket2.getTotalBalls() > 0) {
            removedBalls.push_back(basket2.removeRandomBall());
        }
        return removedBalls;
    }

}

// Сочетания из n по k
double Action::combination(int k, int n) {

    uint64_t numerator = factorialRange(n, n - k); // Вычисляем только часть факториала n!
    uint64_t denominator = factorialRange(k);      // Вычисляем k!

    return numerator / denominator;
}

// Вычисление вероятности достать комбинацию шаров из одной корзины
// extractionColor - сколько вынуто шаров заданного цвета
// extractionTotal - сколько всего вынуто шаров
// (extractionTotal - extractionColor) - сколько вынуто шаров друого цвета
double Action::probabilityOneBasked(Basket& basket, Color color, int extractionTotal, int extractionColor) {
    double p = 0.0;
    double colorCount1 = basket.countBallsByColor(color);
    double total = basket.getTotalBalls();
    double colorCount2 = total - colorCount1;

    p = (combination(extractionColor, colorCount1) * combination(extractionTotal  - extractionColor, colorCount2)) / combination(extractionTotal, total);
    return p;
}
//перегрузка метода для вероятности достать 1 шарик
double Action::probabilityOneBasked(Basket& basket, Color color) {
    double p = 0.0;
    double colorCount = basket.countBallsByColor(color);
    double total = basket.getTotalBalls();
    p = (colorCount / total);
    return p;
}

// выичсляет вероятность достать по одному шару разного цвета
// из каждой корзины и суммирует вероятности (разные шары)
double Action::probabilityTwoBalls(Basket& basket1, Basket& basket2) {
    double p = 0.0;
    // Получаем количество красных и синих шаров в корзине
    double red1 = basket1.countBallsByColor(Color::Red);
    double blue1 = basket1.countBallsByColor(Color::Blue);
    double total1 = basket1.getTotalBalls();

    double red2 = basket2.countBallsByColor(Color::Red);
    double blue2 = basket2.countBallsByColor(Color::Blue);
    double total2 = basket2.getTotalBalls();

    if (total1 > 0 && total2 > 0) {
        p = ((red1 * blue2) + (red2 * blue1)) / (total1 * total2);
    }

    return p;
}
// выичсляет вероятность достать по одному шару одного цвета
// из каждой корзины и суммирует вероятности (одинаковые шары)
 double Action::probabilityTwoBalls(Basket& basket1, Basket& basket2, Color color) {
    double p = 0.0;
    // Получаем количество одноцветных шаров в корзине 1
    double colorCount1 = basket1.countBallsByColor(color);
    double total1 = basket1.getTotalBalls();
    // Получаем количество одноцветных шаров в корзине 2
    double colorCount2 = basket2.countBallsByColor(color);
    double total2 = basket2.getTotalBalls();

    if (total1 > 0 && total2 > 0) {
        p = (colorCount1 / total1) * ((colorCount2) / (total2));
    }

    return p;
}
