#pragma once

#include "Character.hpp"

namespace ariel
{

    class Cowboy : public Character // public?
    {
    private:
        int _numOfBullets;

        void setNumOfBullets(int numOfBullets);

    public:
        Cowboy(const std::string &name, const Point &location);

        int getNumOfBullets() const;

        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
        std::string print() const override;

    };

}