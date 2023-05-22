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
        std::string Print() const;

        /**
         * @param originPoint
         * @param destinationPoint
         * @param distance
         *
         * @return The closest point to destinationPoint that is located at most the given distance from originPoint
         */
        static Point moveTowards(const Point &originPoint, const Point &destinationPoint, const double distance);

        // bool operator==(const Point &other) const;
    };
}