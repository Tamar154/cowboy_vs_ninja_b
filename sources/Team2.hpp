#pragma once

#include "Team.hpp"
#include "Character.hpp"

namespace ariel
{
    class Team2 : public Team
    {

    public:

        Team2(Character *leader);

        // ~Team2() override;

        /**
         * Overrides the print function of Team
         */
        void print();

        
    };
}