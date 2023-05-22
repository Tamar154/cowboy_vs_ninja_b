#include "Team.hpp"
#include <limits>

namespace ariel
{
    Team::Team(Character *leader) : _leader(leader)
    {
        if (leader->isAssigned())
            throw runtime_error("leader is already assigned to a team");

        _team.push_back(_leader);
        _leader->setAssigned();
    }

    Team::~Team()
    {
        for (Character *c : _team)
        {
            delete c;
        }
    }

    std::vector<Character *> Team::getTeam() const
    {
        return _team;
    }

    Character *Team::getLeader() const
    {
        return _leader;
    }

    void Team::add(Character *player)
    {
        if (player->isAssigned())
        {
            throw runtime_error("the player is already assigned to a team");
        }

        if (_team.size() < TEAM_SIZE)
        {
            _team.push_back(player);
            player->setAssigned();
        }
        else
        {
            throw runtime_error("Team can have at most 10 characters");
        }
    }

    void Team::attack(Team *enemy)
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

        for (Character *c : this->_team)
        {
            if (c->isAlive() && enemy->stillAlive())
            {
                if (!closestTarget->isAlive())
                    closestTarget = chooseAliveTarget(enemy);

                Cowboy *cowboy = dynamic_cast<Cowboy *>(c);
                if (cowboy != nullptr)
                    cowboyAttack(cowboy, closestTarget);
            }
        }

        for (Character *c : this->_team)
        {
            if (c->isAlive() && enemy->stillAlive())
            {
                if (!closestTarget->isAlive())
                    closestTarget = chooseAliveTarget(enemy);

                Ninja *ninja = dynamic_cast<Ninja *>(c);
                if (ninja != nullptr)
                    ninjaAttack(ninja, closestTarget);
            }
        }
    }

    int Team::stillAlive() const
    {
        int counter = 0;
        for (Character *c : _team)
        {
            if (c->isAlive())
                ++counter;
        }

        return counter;
    }

    void Team::print() const
    {
    }

    void Team::checkLeader()
    {
        if (!this->_leader->isAlive())
        {
            Character *newLeader = nullptr;
            double minDist = numeric_limits<double>::max();

            for (Character *c : this->_team)
            {
                if (c != _leader && c->isAlive() && c->distance(_leader) < minDist)
                {
                    newLeader = c;
                    minDist = c->distance(_leader);
                }
            }
            _leader = newLeader;
        }
    }

    Character *Team::chooseAliveTarget(Team *team) const
    {
        Character *target = nullptr;
        double minDist = numeric_limits<double>::max();

        for (Character *c : team->_team)
        {
            if (c->isAlive() && c->distance(_leader) < minDist)
            {
                target = c;
                minDist = c->distance(_leader);
            }
        }
        return target;
    }

    void Team::cowboyAttack(Cowboy *cowboy, Character *enemy)
    {
        if (cowboy->hasboolets())
            cowboy->shoot(enemy);
        else
            cowboy->reload();
    }

    void Team::ninjaAttack(Ninja *ninja, Character *enemy)
    {
        if (ninja->distance(enemy) < 1)
            ninja->slash(enemy);
        else
            ninja->move(enemy);
    }
}