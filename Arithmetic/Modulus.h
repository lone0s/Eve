//
// Created by jeune on 20/02/2023.
//

//EVA01_MODULUS_H
#pragma once

#include <tuple>

namespace Mod {

    /**
     * @brief Theoreme du PGCD étendu avec ax + by = pgcd(a,b)
     * @return std::tuple tel que get(0) = mod ; get(1) = x ; get(2) = y
     */

    template<typename T>
    std::tuple<T,T,T> xPgcd(T a, T b) {
        std::tuple<T,T> xs {1,0};
        std::tuple<T,T> ys {0,1};
        T temp,q,xx,yy ;
        int sign = 1;
        while (b != 0) {
            temp = fmod(a,b);
            q = a/b;
            a = b;
            b = temp;
            xx = std::get<1>(xs);
            yy = std::get<1>(ys);
            std::get<1>(xs) = q*xx + std::get<0>(xs);
            std::get<1>(ys) = q*yy + std::get<0>(ys);
            std::get<0>(xs) = xx;
            std::get<0>(ys) = yy;
            sign = -1 * sign;
        }
        return std::tuple<T,T,T> {a, sign * std::get<0>(xs), -1 * sign * std::get<0>(ys)};
    }

    template <typename T>
    T qMod(T num, T denom, T mod) {
        T pgcd, x, y;
        std::tie(pgcd, x, y) = xPgcd(denom, mod);
        if (fmod(num, pgcd) != 0)
            return T(-1);
        else {
            x = x * fmod((num / pgcd), (mod / pgcd));
            while(x < 0)
                x += mod;
            return x;
        }
    }

    /**
     * @brief evaluates Legendre symbol value given a value and a prime
     * @tparam T
     * @param a
     * @param p
     * @return
     */

    template<typename T>
    T legendre(T a, T p) {
        return qMod(a, (p-1)/2, p);
    }

}

