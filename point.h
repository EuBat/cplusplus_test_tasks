#pragma once
#include <cmath>

struct Point
{
    float x {0};
    float y {0};
};

double CalcDistanse(const Point& p1, const Point& p2)
{
    return std::sqrt(std::pow(p2.x - p1.x,2) + std::pow(p2.y - p1.y,2));
}


