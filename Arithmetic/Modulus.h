//
// Created by jeune on 20/02/2023.
//

//EVA01_MODULUS_H
#pragma once

namespace Mod {

    template<typename T>
    T pgcd(const T a, T b) {
        if (a == 0)
            return b;
        return pgcd(b%a, a);
    }


    /**
     * @brief Theoreme du PGCD étendu avec ax + by = pgcd(a,b)
     * @return std::tuple tel que get(0) = mod ; get(1) = x ; get(2) = y
     */
    template<typename T>
    std::tuple<T,T,T> pgcdEtendu(T a, T b) {
        if (a == 0)
            return std::tuple<T,T,T> {b,0,1};
        std::tuple<T,T,T> temp = pgcdEtendu(b%a, a);
        std::tuple<T,T,T> res {pgcd(a,b), std::get<2>(temp) - (b/a) * std::get<1>(temp), std::get<1>(temp)};
        return res;
    }

    template<typename T>
    std::tuple<T,T,T> xPgcd(T a, T b) {
        std::tuple<T,T> xs {1,0};
        std::tuple<T,T> ys {0,1};
        T temp,q,xx,yy ;
        int sign = 1;
        while (b != 0) {
            temp = a % b;
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
    T qMod(T dividende, T diviseur, T mod) {
        T pgcd, x, y;
        std::tie(pgcd, x, y) = xPgcd(dividende,mod);
        if (diviseur % pgcd != 0)
            return -1;
        else {
            x = x * (diviseur / pgcd) % (mod / pgcd);
            x < 0 ? x += mod/pgcd : x ;
            return x;
        }
    }

    template<typename T>
    //Besoin de récuperer le X du
    T fractionMod(T b, T n) {
        std::tuple<T,T,T> res = pgcdEtendu(b,n);
        if (std::get<0>(res) == 1)
            return std::get<1>(res);
        return -1;
    }

}