#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character // public?
    {
    private:
        int _numOfBullets;

    public:
        Cowboy(const std::string &name, const Point &location);

        int getNumOfBullets() const;

        void setNumOfBullets(int numOfBullets);

        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
    };

}