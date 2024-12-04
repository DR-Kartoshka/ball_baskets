#ifndef ACTION_H
#define ACTION_H
#include "ball.h"
#include "basket.h"

class Action {
public:


    //переложить 1 шар из одиной корзины в другую
    static void moveRandomBall(Basket& fromBasket, Basket& toBasket);

    //достать 2 рандомных шара из двух случайных корзин
    static std::vector<Ball> removeTwoRandomBalls(Basket& basket1, Basket& basket2);

    // Сочетания из n по k
    static double combination(int k, int n);

     // Вычисление вероятности достать комбинацию шаров из одной корзины
     // kred - сколько вынуто красных шаров
     // extraction - сколько всего вынуто шаров
     // (extraction - kred) - сколько вынуто синих шаров
    static double probabilityOneBasked(Basket& basket, Color color, int extractionTotal, int extractionColor);

    //перегрузка метода для вероятности достать 1 шарик
    static double probabilityOneBasked(Basket& basket, Color color);

    // выичсляет вероятность достать по одному шару разного цвета
    // из каждой корзины и суммирует вероятности (разные шары)
    static double probabilityTwoBalls(Basket& basket1, Basket& basket2);

    // выичсляет вероятность достать по одному шару одного цвета
    // из каждой корзины и суммирует вероятности (одинаковые шары)
    static double probabilityTwoBalls(Basket& basket1, Basket& basket2, Color color);

};

#endif // ACTION_H
