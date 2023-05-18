// Created by Shalev Ben David.
#include "Cowboy.hpp"
using namespace std;
using namespace ariel;

/**
 * @return - if cowboy has bullets
 */
bool Cowboy :: hasboolets () const {
    return (_bullets > 0);
}

/**
 * in case of valid victim, the victim looses 1 point
 * @param enemy - the victim the cowboy shoots
 */
void Cowboy :: shoot (Character* enemy) {
    // Check if the enemy is null.
    if (enemy == nullptr) {
        throw invalid_argument("Enemy can't be null!\n");
    }
    // Check if this cowboy is dead.
    if (!isAlive()) {
        throw runtime_error("Dead cowboy can't shoot!\n");
    }
    // Check if this cowboy is trying to shoot himself.
    if (this == enemy) {
        throw runtime_error("Cowboy can't shoot himself!\n");
    }
    // Only if this cowboy has bullets.
    if (_bullets > 0) {
        // Decrease enemy hp by 10.
        enemy -> hit(COWBOY_DAMAGE);
        // Decrease number of bullets by 1.
        _bullets -= 1;
    }
}

/**
 * Make the cowboy's # of bullets 6.
 */
void Cowboy :: reload () {
    // If he is dead, throw error.
    if (!isAlive()) {
        throw runtime_error("A dead cowboy can't reload!\n");
    }
    _bullets = BULLETS_SIZE;
}

/**
 * @return - string representing the cowboy
 */
string Cowboy :: print () const {
    string info;
    info = "<<<<<<<<<<<<<<<<<<<<<<<<<< Character name: (C) [" + getName() + "] >>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    // If the character is alive, print hit points.
    if (isAlive()) {
        info += "[Hit Points: " + to_string(getHitPoints()) + "]\n";
    }
    info += "[Location: " + getLocation().toString() + "]\n";
    return info;
}

// Get methods.
int Cowboy :: getBullets () const { return _bullets; }