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

        void setX(double xVal);
        void setY(double yVal);

    public:
        Point(double xVal, double yVal);

        double getX() const;
        double getY() const;

        double distance(const Point &other) const;
        std::string Print() const;

        static Point moveTowards(const Point &originPoint, const Point &destinationPoint, double distance);
    };
}