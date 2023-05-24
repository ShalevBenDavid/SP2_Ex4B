// Created by Shalev Ben David.

#ifndef SP2_EX4A_NINJA_H
#define SP2_EX4A_NINJA_H
#include "Character.hpp"

const int NINJA_DAMAGE = 40;

namespace ariel {
    class Ninja : public Character {
    private:
        int _speed;

    protected:
        // Constructors.
        Ninja (const std :: string& name, Point location, const int hit_points, int speed) :
            Character(name, location, hit_points), _speed(speed) {}

    public:
        // Methods.
        void slash (Character *) const;
        void move (Character *);

        // Print method.
        std :: string print () const override;

        // Get methods.
        int getSpeed () const;
    };
}

#endif //SP2_EX4A_NINJA_H