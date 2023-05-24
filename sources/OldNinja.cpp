
#include "OldNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{

    OldNinja::OldNinja(std::string name, Point location)
        : Ninja(name, location)
    {
        setHp(150);
        setSpeed(8);
    }

}