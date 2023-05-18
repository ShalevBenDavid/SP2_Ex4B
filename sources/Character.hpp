// Created by Shalev Ben David.

#ifndef SP2_EX4A_CHARACTER_H
#define SP2_EX4A_CHARACTER_H
#include <string>
#include <iostream>
#include "Point.hpp"

namespace ariel {
    class Character {
    private:
        std :: string _name;
        Point _location;
        int _hit_points;
        bool _in_team;

    public:
        // Constructors.
        Character (const std :: string& name, Point location, int hit_points) :
            _name(name), _location(location), _hit_points(hit_points), _in_team(false) {}

        // Destructor.
        virtual ~Character() = default;

        // Methods.
        bool isAlive () const;
        double distance (Character*) const;
        void hit (int);

        // Print method.
        virtual std :: string print () const = 0;

        // For Tidy.
        Character (Character&); // Copy Constructor.
        Character(Character&& ) noexcept; // Move Constructor.
        Character& operator = (const Character&); // Copy assignment operator.
        Character& operator = (Character&&) noexcept; // Move assignment operator.

        // Get && Set methods.
        std :: string getName () const;
        Point getLocation () const;
        bool& getInTeam ();
        int getHitPoints () const;

    protected:
        void setLocation (Point);
        void setHitPoints (int);
    };
}

#endif //SP2_EX4A_CHARACTER_H