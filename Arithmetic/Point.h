//
// Created by jeune on 07/02/2023.
//

#pragma once

template<typename T>
class Point {
public:
        T x;
        T y;

    public:
        Point(const T& i, const T& j) : x(i), y(j) {};
        bool operator == (const Point& point) const {
            return (x == point.x && y == point.y);
        }
};



//EVA01_POINT_H
