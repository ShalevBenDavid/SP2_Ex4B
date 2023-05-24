// Created by Shalev Ben David.

#ifndef SP2_EX4A_TEAM_H
#define SP2_EX4A_TEAM_H
#include <array>
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

const int MAX_NUM_OF_WARRIORS = 10;

namespace ariel {
    class Team {
    private:
        std :: array < Character*, MAX_NUM_OF_WARRIORS > _warriors;
        size_t _warriors_count;
        Character* _leader;

    public:
        // Constructors.
        Team (Character*);

        // Destructor.
        virtual ~Team () {
            for (size_t i = 0; i < _warriors_count; i++) { delete _warriors.at(i); }
        }

        // Methods.
        void add (Character*);
        virtual void attack (Team*);
        int stillAlive () const;
        static Character* getClosest (Team*, Character*);

        // Print method.
        virtual void print () const;

        // For Tidy.
        Team (Team&) = delete; // Copy Constructor.
        Team (Team&&) noexcept = delete; // Move Constructor.
        Team& operator = (const Team&) = delete; // Copy assignment operator.
        Team& operator = (Team&&) noexcept = delete; // Move assignment operator.

        // Get && Set methods.
        Character* getLeader () const;
        std :: array <Character*, MAX_NUM_OF_WARRIORS> getWarriors() const;
        size_t getWarriorsCount () const;

    protected:
        void setWarriorsCount (size_t);
        void setLeader (Character*);
    };
}

#endif //SP2_EX4A_TEAM_H