// Created by Shalev Ben David.

#ifndef SP2_EX4A_YOUNGNINJA_H
#define SP2_EX4A_YOUNGNINJA_H
#include "Ninja.hpp"

const int YOUNG_NINJA_SPEED = 14;
const int YOUNG_NINJA_HP = 100;

namespace ariel {
    class YoungNinja : public Ninja {

    public:
        // Constructors.
        YoungNinja (const std :: string& name, Point location) :
                Ninja(name, location, YOUNG_NINJA_HP, YOUNG_NINJA_SPEED) {}
    };
}

#endif //SP2_EX4A_YOUNGNINJA_H