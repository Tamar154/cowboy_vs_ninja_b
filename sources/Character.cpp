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

    bool Character::isAlive()
    {
        return false;
    }

    double Character::distance(const Character *other)
    {
        return 0.0;
    }

    void Character::hit(int amount)
    {
    }

    string Character::print()
    {
        return "";
    }

    // bool Character::operator==(const Character &other) const
    // {
    //     return false;
    // }

}