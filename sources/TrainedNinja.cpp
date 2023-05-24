
#include "TrainedNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{

    TrainedNinja::TrainedNinja(std::string name, Point location)
        : Ninja(name, location)
    {
        setHp(120);
        setSpeed(12);
    }

}