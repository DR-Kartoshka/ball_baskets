#include "factorial.h"
#include <cstdint>
#include <stdexcept>
#include <QMessageBox>

//Вычисляет факториал числа n (n! = 1 * 2 * ... * n)
uint64_t factorial(int n) {
    long fac = 1;

    for (auto i = 2; i <= n; ++i) {
        fac = fac * i;
    }

    return fac;
}

// Вычисляет произведение чисел в диапазоне от start до finish.
// Необходимо для частичного вычисления факториалов.
uint64_t factorialRange(int start, int finish /* =1 */) {
    uint64_t result = 1;
    for (int i = start; i > finish; --i) {
        result *= i;
        if (result < 0) {
            QMessageBox::critical(nullptr, "error", "Переполнение при вычислении факториала!");
            throw std::overflow_error("Переполнение при вычислении факториала!");
        }
    }
    return result;
}
