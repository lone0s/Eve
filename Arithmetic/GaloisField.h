//
// Created by jeune on 02/02/2023.
//
#pragma once
#include <cmath>

/**
 * Galois Field Operations
 */

namespace GFO {

    //4 operations : Addition ; Soustraction ; Multiplication ; Division
    template <typename T>
    T add(T a, T b, T modulus) {
        return (a + b) % modulus;
    };
    template <typename T>
    T soustraction(T a, T b, T modulus) {
        return ((a - b) + modulus) % modulus;
    };
    template <typename T>
    T multiplication(T a, T b, T modulus) {
        return ((int) (((long long) a * b) % modulus));
    };
    template <typename T>
    T division(T a, T b, T modulus) {
        int res = (int) pow(b, modulus - 2);
        return multiplication(a, res);
    }
}


// EVA01_GALOISFLD_H