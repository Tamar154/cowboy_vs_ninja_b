#include "Ninja.hpp"

namespace ariel
{

    Ninja::Ninja(const string &name, const Point &location)
        : Character(location, 0, name), _speed(0) {}

    /**
     * Getters and Setters
     */
    int Ninja::getSpeed() const { return this->_speed; }

    void Ninja::setSpeed(int speed) { this->_speed = speed; }

    void Ninja::move(Character *enemy)
    {
        if (this->isAlive())
        {
            Point from = this->getLocation();
            Point to = enemy->getLocation();
            double distance = this->getSpeed();
            Point move = Point::moveTowards(from, to, distance);
            this->setLocation(move);
        }
    }

    void Ninja::slash(Character *enemy) const
    {
        if (enemy == this)
            throw runtime_error("Cannot attack itself");
        if (!enemy->isAlive())
            throw runtime_error("Cannot attack a dead enemy");
        if (!this->isAlive())
            throw runtime_error("A dead character cannot attack");

        double distance = this->getLocation().distance(enemy->getLocation());
        if (this->isAlive() && distance < 1)
        {
            enemy->hit(40);
        }
    }

    string Ninja::print() const
    {
        return "N, " + Character::print();
    }

}