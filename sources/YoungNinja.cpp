
#include "YoungNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{

    YoungNinja::YoungNinja(std::string name, Point location)
        : Ninja(name, location)
    {
        setHp(100);
        setSpeed(14);
    }

}