#include "Point.hpp"

namespace ariel
{

    // Point::Point() : _x(0), _y(0) {}

    Point::Point(double x, double y) : _x(x), _y(y) {}

    double Point::getX() const { return _x; }
    double Point::getY() const { return _y; }

    void Point::setX(double xVal) { _x = xVal; }
    void Point::setY(double yVal) { _y = yVal; }

    double Point::distance(const Point &p) const
    {
        return -1;
    }

    void Point::Print()
    {
    }

    Point Point::moveTowards(Point &originPoint, Point &destinationPoint, double distance)
    {
        return originPoint;
    }

    // bool Point::operator==(const Point &other) const
    // {
    //     return false;
    // }
}