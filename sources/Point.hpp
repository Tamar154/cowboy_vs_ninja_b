#pragma once

#include <iostream>

const double EPSILON = 0.001;

namespace ariel
{

    class Point
    {
    private:
        double _x;
        double _y;

        void setX(double xVal); /* public? */
        void setY(double yVal); /* public? */

    public:
        Point(double xVal, double yVal);

        double getX() const;
        double getY() const;

        double distance(const Point &other) const;
        void Print();
        static Point moveTowards(Point &originPoint, Point &destinationPoint, double distance);
        // bool operator==(const Point &other) const;
    };
}