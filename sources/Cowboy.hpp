// Created by Shalev Ben David.

#ifndef SP2_EX4A_COWBOY_H
#define SP2_EX4A_COWBOY_H
#include "Character.hpp"

const int BULLETS_SIZE = 6;
const int COWBOY_HP = 110;
const int COWBOY_DAMAGE = 10;

namespace ariel {
    class Cowboy : public Character {
    private:
        int _bullets;

    public:
        // Constructors.
        Cowboy (const std :: string& name, Point location) :
            Character(name, location, COWBOY_HP), _bullets (BULLETS_SIZE) {}

        // Methods.
        bool hasboolets () const;
        void shoot (Character*);
        void reload ();

        // Print method.
        std :: string print () const override;

        // Get methods.
        int getBullets () const;
    };
}

#endif //SP2_EX4A_COWBOY_H