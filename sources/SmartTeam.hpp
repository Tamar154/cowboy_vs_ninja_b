#pragma once

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : private Team
    {

    public:
        SmartTeam(Character *leader);

        void print();
    };
}