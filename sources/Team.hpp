#pragma once

#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

#include <vector>

const int TEAM_SIZE = 10;

namespace ariel
{
    class Team
    {
    private:
        std::vector<Character *> _team;
        Character *_leader;

    public:
        Team(Character *leader);

        ~Team();

        Team(const Team &other) = delete;            // To make tidy happy
        Team &operator=(const Team &other) = delete; // To make tidy happy
        Team(Team &&other) = delete;                 // To make tidy happy
        Team &operator=(Team &&other) = delete;      // To make tidy happy

        std::vector<Character *> getTeam() const;
        Character *getLeader() const;

        // void setLeader(Character* leader);

        void add(Character *player);

        virtual void attack(Team *enemy);

        int stillAlive() const;

        void print() const;

        // Helper functions
        void checkLeader();
        Character *chooseAliveTarget(Team *team) const;
        void cowboyAttack(Cowboy *cowboy, Character *enemy);
        void ninjaAttack(Ninja *ninja, Character *enemy);
    };
}