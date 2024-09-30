#include "Fixed.hpp"
#include "Point.hpp"
#include <math.h>

/*
    float xa, ya, xb, yb, xc, yc, x, y;
    xa = 0.0f;
    ya = 0.0f;
    xb = 0.0f;
    yb = 1.0f;
    xc = 1.0f;
    yc = 0.0f;
    x = 0.5f;
    y = 0.5f;
    if (((x-xa)*(yb-ya)-(y-ya)*(xb-xa)>=0) && ((x-xb)*(yc-yb)-(y-yb)*(xc-xb)>=0) && ((x-xc)*(ya-yc)-(y-yc)*(xa-xc)>=0))
        std::cout<<"\nТочка лежит внутри треугольника";
    else std::cout<<"\nТочка не лежит внутри треугольника";

https://cpp.mazurok.com/triangle/

https://www.cs.cmu.edu/~quake/robust.html

Точка находится внутри треугольника, когда три теста ориентации возвращают один и тот же знак. 
Она находится на контуре, когда один тест возвращает 0, а два других - внутреннее условие. 
Она находится на вершине, когда два теста возвращают 0.

https://www.baeldung.com/cs/check-if-point-is-in-2d-triangle
AB <- Vector(B.x - A.x, B.y - A.y)
    AC <- Vector(C.x - A.x, C.y - A.y)
    cross_product <- AB.x * AC.y - AB.y * AC.x

    if cross_product > 0:
        return 1
    else:
        return -1

*/

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed const x = point.getX();
    Fixed const y = point.getY();
    Fixed const xa = a.getX();
    Fixed const ya = a.getY();
    Fixed const xb = b.getX();
    Fixed const yb = b.getY();
    Fixed const xc = c.getX();
    Fixed const yc = c.getY();
    
    Fixed const a1 = (x - xa) * (yb - ya) - (xb - xa) * (y - ya);
    Fixed const a2 = (x - xb) * (yc - yb) - (xc - xb) * (y - yb);
    Fixed const a3 = (x - xc) * (ya - yc) - (xa - xc) * (y - yc);
    //std::cout << "a1: " << a1 << std::endl;
    //std::cout << "a2: " << a2 << std::endl;
    //std::cout << "a3: " << a3 << std::endl;

    if ((a1 > 0 && a2 > 0 && a3 > 0) || (a1 < 0 && a2 < 0 && a3 < 0)) //<=0 - точка на границе треугольника
        return true;
    else
        return false;
 
}


int main( void )
{
    Point a(0.0f, 0.0f);
    Point b(0.0f, 1.0f);
    Point c(1.0f, 0.0f);
    Point point(0.3f, 0.3f);
    Point point1(0.0f, 0.0f);
    Point point2(2.0f, 0.0f);
    Point point3(0.0f, 0.5f);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << point << std::endl;
    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;
    std::cout << point1 << std::endl;
    if (bsp(a, b, c, point1))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;
    std::cout << point2 << std::endl;
    if (bsp(a, b, c, point2))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;
    std::cout << point3 << std::endl;
    if (bsp(a, b, c, point3))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    return 0;
}