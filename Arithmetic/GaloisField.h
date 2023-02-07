//
// Created by jeune on 02/02/2023.
//
#pragma once
#include <cmath>


namespace Arithmetic {
    class GaloisField {
            int modulus;

        public:
            GaloisField(int mod) : modulus(mod) {};
            //4 operations : Addition ; Soustraction ; Multiplication ; Division
            int addition(int a, int b) const {
                return (a+b)%modulus;
            };
            int soustraction(int a, int b) const {
                return ((a-b) + modulus)%modulus;
            };
            int multiplication(int a, int b) const {
                return ((int)(((long long)a*b) % modulus));
            };
            int division (int a, int b) const {
                int res = (int)pow(b, modulus - 2);
                return multiplication(a,res);
            }
    };
}


// EVA01_GALOISFLD_H