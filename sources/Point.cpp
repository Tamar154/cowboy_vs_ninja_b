#include "Point.hpp"

#include <cmath>
#include <iostream>
using namespace std;

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
        double x = pow(p._x - this->_x, 2);
        double y = pow(p._y - this->_y, 2);
        return sqrt(x + y);
    }

    string Point::Print() const
    {
        return "(" + to_string(_x) + ", " + to_string(_y) + ")";
    }

    Point Point::moveTowards(const Point &originPoint, const Point &destinationPoint, const double distance)
    {
        if (distance < 0)
            throw invalid_argument("Negative distance given");

        if (originPoint.distance(destinationPoint) < distance) // if the input distance is greater than the actual distance between originPoint and destinationPoint
            return destinationPoint;

        // vector of originPoint and destinationPoint
        double xVector = destinationPoint._x - originPoint._x;
        double yVector = destinationPoint._y - originPoint._y;

        // norm calculation
        double norm = sqrt(xVector * xVector + yVector * yVector);

        // normlized vector
        double xNormalized = xVector / norm;
        double yNormalized = yVector / norm;

        Point p(originPoint._x + distance * xNormalized, originPoint._y + distance * yNormalized);
        return p;
    }

    // bool Point::operator==(const Point &other) const
    // {
    //     return false;
    // }
}