// Created by Shalev Ben David.

#ifndef SP2_EX4A_SMARTTEAM_H
#define SP2_EX4A_SMARTTEAM_H
#include "Team.hpp"

namespace ariel {
    class SmartTeam : public Team {

    public:
        SmartTeam (Character* leader) : Team(leader) {}

        // Methods.
        void attack (Team* enemy_team) override;

        // Print method.
        void print() const override;
    };
}

#endif //SP2_EX4A_SMARTTEAM_H