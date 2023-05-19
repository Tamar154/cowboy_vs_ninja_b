#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(const string &name, const Point &location)
        : Character(location, 110, name), _numOfBullets(6) {}

    int Cowboy::getNumOfBullets() const { return _numOfBullets; }

    void Cowboy::setNumOfBullets(int numOfBullets) { _numOfBullets = numOfBullets; }

    void Cowboy::shoot(Character *enemy)
    {
    }

    bool Cowboy::hasboolets()
    {
        return false;
    }

    void Cowboy::reload()
    {
    }
}