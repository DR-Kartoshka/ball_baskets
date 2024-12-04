#include "factorial.h"
#include <cstdint>
#include <stdexcept>

uint64_t factorial(int n) {
    long fac = 1;

    for (auto i = 2; i <= n; ++i) {
        fac = fac * i;
    }

    return fac;
}

uint64_t factorialRange(int start, int finish) {
    uint64_t result = 1;
    for (int i = start; i > finish; --i) {
        result *= i;
        if (result < 0) {
            throw std::overflow_error("Переполнение при вычислении факториала!");
        }
    }
    return result;
}
