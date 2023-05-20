// Created by Shalev Ben David.
#include "Ninja.hpp"
using namespace std;
using namespace ariel;

/**
 * in case of valid victim, the victim looses 13 point
 * @param enemy - the victim the ninja slashes
 */
void Ninja :: slash (Character* enemy) const {
    // Check if the enemy is null.
    if (enemy == nullptr) {
        throw invalid_argument("Enemy can't be null!\n");
    }
    // Check if this ninja is dead.
    if (!isAlive()) {
        throw runtime_error("Dead ninja can't slash!\n");
    }
    // Check if enemy is already dead.
    if (!enemy -> isAlive()) {
        throw runtime_error("You can't slash a dead character!\n");
    }
    // Check if this ninja is trying to slash himself.
    if (this == enemy) {
        throw runtime_error("Ninja can't slash himself!\n");
    }
    // Only if enemy is at most 1 meter away from this ninja.
    if (getLocation().distance(enemy -> getLocation()) <= 1) {
        // Decrease enemy hp by 40.
        enemy -> hit (NINJA_DAMAGE);
    }
}

/**
 * Moves this ninja closer to enemy based on his speed.
 * @param enemy - the enemy we move this ninja towards
 */
void Ninja :: move (Character* enemy) {
    // Check that this enemy isn't null.
    if (enemy == nullptr) {
        throw invalid_argument("Enemy can't be null!\n");
    }
    // Move this ninja location towards enemy.
    setLocation(Point :: moveTowards(getLocation(), enemy -> getLocation(), _speed));
}

/**
 * @return - string representing the ninja
 */
string Ninja :: print() const {
    string info;
    info = "[Character name: (N) " + getName() + " | ";
    // If the character is alive, print hit points.
    if (isAlive()) {
        info += "Hit Points: " + to_string(getHitPoints()) + " | ";
    }
    info += "Location: " + getLocation().toString() + "]\n";
    return info;
}

// Get methods.
int Ninja :: getSpeed () const { return _speed; }