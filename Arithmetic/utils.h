//
// Created by jeune on 28/02/2023.
//
//EVA01_UTILS_H

#pragma once

#include <random>
#include <chrono>
#include <algorithm>

namespace Utils {
    template<typename T>
    T rand(T min, T max) {
        static std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<T> distribution(min, max);
        return distribution(rng);
    }

    template<typename T>
    void removeDuplicates(std::vector<T> vector) {
        std::sort(vector.begin(), vector.end());
        vector.erase(std::unique(vector.begin(), vector.end()), vector.end());
    }
}


