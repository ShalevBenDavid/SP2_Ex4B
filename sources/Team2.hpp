// Created by Shalev Ben David.

#ifndef SP2_EX4A_TEAM2_H
#define SP2_EX4A_TEAM2_H
#include "Team.hpp"

namespace ariel {
    class Team2 : public Team {

    public:
        Team2 (Character* leader) : Team(leader) {}

        // Methods.
        void attack (Team* enemy_team) override;

        // Print method.
        void print() const override;
    };
}

#endif //SP2_EX4A_TEAM2_H