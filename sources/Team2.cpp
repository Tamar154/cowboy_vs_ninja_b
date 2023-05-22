#include "Team2.hpp"

namespace ariel
{

    Team2::Team2(Character *leader) : Team(leader) {}

    void Team2::attack(Team *enemy)
    {
        if (enemy == nullptr)
            throw invalid_argument("null team given");
        if (this->stillAlive() == 0)
            throw runtime_error("The attacking team is dead");
        if (enemy->stillAlive() == 0)
            throw runtime_error("The enemy team is dead");

        // // Make sure the attacking team has a leader
        checkLeader();

        // Choose the closes enemy to attack
        Character *closestTarget = chooseAliveTarget(enemy);

        for (Character *c : this->getTeam())
        {
            if (c->isAlive() && enemy->stillAlive())
            {
                if (!closestTarget->isAlive())
                    closestTarget = chooseAliveTarget(enemy);

                Cowboy *cowboy = dynamic_cast<Cowboy *>(c);
                if (cowboy != nullptr)
                {
                    cowboyAttack(cowboy, closestTarget);
                }
                else
                {
                    Ninja *ninja = dynamic_cast<Ninja *>(c);
                    ninjaAttack(ninja, closestTarget);
                }
            }
        }
    }

    void Team2::print()
    {
    }
}