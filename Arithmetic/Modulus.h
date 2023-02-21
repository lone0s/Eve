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
    //Besoin de récuperer le X du
    T fractionMod(T b, T n) {
        std::tuple<T,T,T> res = pgcdEtendu(b,n);
        if (std::get<0>(res) == 1)
            return std::get<1>(res);
        return -1;
    }


/*
    template <typename T>
    inline operator - ()*/
}