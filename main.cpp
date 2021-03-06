#include <iostream>
#include "point.h"
#include "line.h"
#include "body2d.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Line a;
    a.begin.x = 1;
    a.begin.y = 1;

    a.end.x = 10;
    a.end.y = 10;

    Line b;
    b.begin.x = 1;
    b.begin.y = 9;

    b.end.x = 10;
    b.end.y = 0;

    std::cout << HasInterection(a,b) << std::endl;

    std::string StringTri{"2 0 0 2 0 0 4"};
    Triangle tri(StringTri);
    std::cout << "area tri  = " << tri.CalculateArea() << std::endl;

    Point p1,p2;
    p1.x = 1;
    p1.y = 1;
    p2.x = 5;
    p2.y = 5;

    Square square(p1,p2);
    std::cout << "area square = " << square.CalculateArea() << std::endl;

    Circle circle(p1, 1);
    std::cout << "area circle  = " << circle.CalculateArea() << std::endl;

    Circle circle2(p1,3);
    std::cout << "area circle2  = " << circle2.CalculateArea() << std::endl;

    std::vector<Body2D*> vec{3};
    vec[0] = &tri;
    vec[1] = &square;
    vec[2] = &circle;
    std::cout << "Result:" << circle2.IsThisAreaGreaterThen(vec) << std::endl;
    std::cout << circle.Serialization() << std::endl;

    return 0;

}
