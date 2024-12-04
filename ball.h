#ifndef BALL_H
#define BALL_H

enum class Color {
    Red,
    Blue
};

// Реализация класса шара
class Ball {
public:
    // Конструктор для создания шара с заданным цветом
    Ball(Color color): color(color){} //аналог this.color = color;

    // Геттер для получения цвета шара
    Color getColor() const {
        return color;
    }
private:
    Color color;  // Цвет шара red or blue
};

#endif // BALL_H
