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
        ~Cowboy() override = default;
        Cowboy(const Cowboy &other) = default;           
        Cowboy &operator=(const Cowboy &other) = default; 
        Cowboy(Cowboy &&other) = default;                 
        Cowboy &operator=(Cowboy &&other) = default;

        int getNumOfBullets() const;

        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
        std::string print() const override;
    };

}