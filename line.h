#pragma once
#include "point.h"

struct Line
{
    Point begin;
    Point end;
};

template<class T>
const T& min(const T& a, const T& b)
{
    return (b < a) ? b : a;
}

template<class T>
const T& max(const T& a, const T& b)
{
    return (a < b) ? b : a;
}

double Direction(const Point& p0,const Point& p1, const Point& p2)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

bool OnSegmet(const Point& p0, const Point& p1, const Point& p2)
{
    if(p2.x >= min(p0.x, p1.x) &&
       p2.y >= min(p0.y, p1.y) &&
       p2.x <= max(p0.x, p1.x) &&
       p2.y <= max(p0.y,p0.y))
    {
        return true;
    } else
    {
        return false;
    }
}

bool HasInterection(const  Line& Line1, const Line& Line2)
{
    double d1,d2,d3,d4;

    d1 = Direction(Line2.begin, Line2.end, Line1.begin);
    d2 = Direction(Line2.begin, Line2.end, Line1.end);
    d3 = Direction(Line1.begin, Line1.end, Line2.begin);
    d4 = Direction(Line1.begin, Line1.end, Line2.end);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
        ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
    {
    return true;
    } else if(d1 == 0 && OnSegmet(Line2.begin, Line2.end, Line1.begin))
    {
     return true;
    } else if(d2 == 0 && OnSegmet(Line2.begin, Line2.end, Line1.end))
    {
     return true;
    } else if(d3 == 0 && OnSegmet(Line1.begin, Line1.end, Line2.begin))
    {
     return true;
    } else if(d4 == 0 && OnSegmet(Line1.begin, Line1.end, Line2.end))
    {
     return true;
    } else
    {
     return false;
    }
}
