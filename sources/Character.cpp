#include "Character.hpp"

namespace ariel
{

    Character::Character(const Point &location, int hitPoints, std::string name)
        : _location(location), _hp(hitPoints), _name(name) {}

    /**
     * Getters
     */
    Point Character::getLocation() const { return _location; }
    int Character::getHp() const { return _hp; }
    string Character::getName() const { return _name; }

    /**
     * Setters
     */
    void Character::setLocation(Point location) { _location = location; }
    void Character::setHp(int hitPoints) { _hp = hitPoints; }
    void Character::setName(string name) { _name = name; }

    bool Character::isAlive() const
    {
        return _hp > 0;
    }

    double Character::distance(const Character *other) const
    {
        return this->_location.distance(other->_location);
    }

    void Character::hit(int amount)
    {
        if (amount < 0)
            throw invalid_argument("hit amount cannot be negative");
        _hp -= amount;

        if (_hp < 0)
            _hp = 0;
    }

    string Character::print() const
    {
        if (this->isAlive())
            return _name + ", " + to_string(_hp) + ", " + _location.Print();
        else
            return "(" + _name + "), " + _location.Print();
    }

    bool Character::isAssigned() const
    {
        return _character_assigned;
    }
    void Character::setAssigned()
    {
        _character_assigned = true;
    }

}