// Created by Shalev Ben David.

#ifndef SP2_EX4A_OLDNINJA_H
#define SP2_EX4A_OLDNINJA_H
#include "Ninja.hpp"
#include "Character.hpp"

const int OLD_NINJA_SPEED = 8;
const int OLD_NINJA_HP = 150;

namespace ariel {
    class OldNinja : public Ninja {

    public:
        // Constructors.
        OldNinja (const std :: string& name, Point location) :
            Ninja(name, location, OLD_NINJA_HP, OLD_NINJA_SPEED) {}
    };
}

#endif //SP2_EX4A_OLDNINJA_H