#pragma once

#include "Point.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point _location;
        int _hp;
        string _name;

    public:
        Character(const Point &location, int hitPoints, string name);

        Point getLocation() const;
        int getHp() const;
        string getName() const;

        void setLocation(Point location);
        void setHp(int hitPoints);
        void setName(string name);

        // bool operator==(const Character &other) const; // ?

        bool isAlive();
        double distance(const Character *other);
        void hit(int amount);
        string print();
    };
}