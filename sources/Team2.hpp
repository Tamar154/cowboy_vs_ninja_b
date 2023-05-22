#pragma once

#include "Team.hpp"
#include "Character.hpp"

namespace ariel
{
    class Team2 : public Team
    {

    public:

        Team2(Character *leader);
        
        void attack(Team *enemy) override;
        void print();
    };
}