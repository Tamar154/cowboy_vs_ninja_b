#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(const string &name, const Point &location)
        : Character(location, 110, name), _numOfBullets(6) {}

    int Cowboy::getNumOfBullets() const { return _numOfBullets; }

    void Cowboy::setNumOfBullets(int numOfBullets) { _numOfBullets = numOfBullets; }

    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == this)
            throw runtime_error("Cannot attack itself");
        if (!enemy->isAlive())
            throw runtime_error("Cannot attack a dead enemy");
        if (!this->isAlive())
            throw runtime_error("A dead character cannot attack");

        if (this->isAlive() && _numOfBullets > 0)
        {
            enemy->hit(10);
            _numOfBullets -= 1;
        }
    }

    bool Cowboy::hasboolets() const
    {
        return _numOfBullets > 0;
    }

    void Cowboy::reload()
    {
        if (!isAlive())
            throw runtime_error("A dead cowboy cannot reload");

        _numOfBullets = 6;
    }

    string Cowboy::print() const
    {
        return "C, " + Character::print();
    }
}