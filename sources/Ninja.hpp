#pragma once

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character // public?
    {
    private:
        int _speed;

    protected:
        void setSpeed(int speed);

    public:
        Ninja(const std::string &name, const Point &location);
        ~Ninja() override = default;
        Ninja(const Ninja &other) = default;
        Ninja &operator=(const Ninja &other) = default;
        Ninja(Ninja &&other) = default;
        Ninja &operator=(Ninja &&other) = default;

        int getSpeed() const;

        void move(Character *enemy);
        void slash(Character *enemy) const;
        std::string print() const override;
    };

}