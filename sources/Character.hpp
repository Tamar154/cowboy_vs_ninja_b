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
        bool _character_assigned = false;

    protected:
        void setLocation(Point location);
        void setHp(int hitPoints);
        void setName(string name);

    public:
        Character(const Point &location, int hitPoints, string name);
        virtual ~Character() = default;
        Character(const Character &other) = default;            
        Character &operator=(const Character &other) = default; 
        Character(Character &&other) = default;                 
        Character &operator=(Character &&other) = default;

        Point getLocation() const;
        int getHp() const;
        string getName() const;

        bool isAlive() const;
        double distance(const Character *other) const;
        void hit(int amount);
        virtual string print() const;

        bool isAssigned() const;
        void setAssigned();
    };
}