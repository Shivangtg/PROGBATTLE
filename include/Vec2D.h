#pragma once
#include <iostream>

struct Vec2D {
    int x = 0, y = 0;

    bool operator==(const Vec2D& other) const {
        return x == other.x && y == other.y;
    }

    Vec2D operator+(const Vec2D& other) const {
        return {x + other.x, y + other.y};
    }
};