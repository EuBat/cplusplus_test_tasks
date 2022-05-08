#pragma once

#include <string>
#include <vector>
#include "point.h"

class BodyInterface
{
public:
    virtual ~BodyInterface() = default;

    virtual double CalculateArea() const = 0;
    virtual std::string Serialization() const = 0;
    virtual std::vector<Point> getVerteces() const = 0;
};
