// Created by Shalev Ben David.
#include "Team.hpp"
#include <limits>
using namespace std;
using namespace ariel;

// Constructor.
Team :: Team (Character *leader) {
    // If leader is null, throw exception.
    if (leader == nullptr) {
        throw invalid_argument("Leader can't be null!\n");
    }
    // If the leader is dead, throw exception.
    if (!leader -> isAlive()) {
        throw invalid_argument("Leader of the team must be alive!\n");
    }
    // If leader is already in a team, throw exception.
    if (leader -> getInTeam()) {
        throw runtime_error("Leader is already in a team!\n");
    }
    // Else, add the leader and initialize values for team.
    _warriors_count = 0;
    _warriors.at(_warriors_count++) = leader;
    _leader = leader;
    // Update his "in team" status to true.
    leader -> getInTeam() = true;
}

/**
 * adding member (Ninja or Cowboy) to the team
 * @param member - the member who joins the team
 */
void Team :: add (Character* member) {
    // If member is null, throw exception.
    if (member == nullptr) {
        throw invalid_argument("Can't add null to the team!\n");
    }
    // If the team is full, throw error.
    if (_warriors_count == MAX_NUM_OF_WARRIORS) {
        throw runtime_error("The team is full!\n");
    }
    // If member is already in a team, throw exception.
    if (member -> getInTeam()) {
        throw runtime_error("Member is already in a team!\n");
    }
    // Add member to the team.
    _warriors.at(_warriors_count++) = member;
    // Update his "in team" status to true.
    member -> getInTeam() = true;
}

/**
 * Attacks enemy_team
 * @param enemy_team - the team we attack
 */
void Team :: attack (Team* enemy_team) {
    // Check if the enemy is null.
    if (enemy_team == nullptr) {
        throw invalid_argument("Enemy team can't be null!\n");
    }
    // Check if this team trying to attack itself.
    if (this == enemy_team) {
        throw runtime_error("Team can't attack itself!\n");
    }
    // If this team or the enemy team is dead, throw.
    if (stillAlive() == 0 || enemy_team -> stillAlive() == 0) {
        throw runtime_error("This team and the enemy team must be alive!\n");
    }
    // If the current leader is dead, assign a new leader.
    if (!_leader -> isAlive()) {
        _leader = getClosest(this, _leader);
    }
    Cowboy* current_cowboy;
    Ninja* current_ninja;
    Character* victim = getClosest(enemy_team, _leader);
    // Iterate first over the cowboys and shoot/reload at enemy team.
    for (size_t i = 0; i < _warriors_count && victim -> isAlive(); i++) {
        auto &temp_warrior = *_warriors.at(i);
        if (typeid(temp_warrior) == typeid(Cowboy)) {
            current_cowboy = dynamic_cast <Cowboy*> (_warriors.at(i));
            // Only if the cowboy is alive, shoot/reload.
            if (current_cowboy -> isAlive()) {
                // If the cowboy has bullets, shoot the victim.
                if (current_cowboy -> hasboolets()) {
                    current_cowboy -> shoot(victim);
                    // If the victim is dead, replace him.
                    if (!victim -> isAlive()) {
                        victim = getClosest(enemy_team, _leader);
                    }
                }
                // Else, reload the weapon.
                else {
                    current_cowboy -> reload();
                }
            }
        }
    }
    // Iterate now over the ninjas and slash/move at enemy team.
    for (size_t i = 0; i < _warriors_count && victim -> isAlive(); i++) {
        auto &temp_warrior = *_warriors.at(i);
        if (typeid(temp_warrior) != typeid(Cowboy)) {
            current_ninja = dynamic_cast <Ninja*> (_warriors.at(i));
            // Only if the ninja is alive, slash/move.
            if (current_ninja -> isAlive()) {
                // If the ninja is close, slash the victim.
                if (current_ninja -> getLocation().distance(victim -> getLocation()) <= 1) {
                    current_ninja -> slash(victim);
                    // If the victim is dead, replace him.
                    if (!victim -> isAlive()) {
                        victim = getClosest(enemy_team, _leader);
                    }
                }
                // Else, move ninja towards victim.
                else {
                    current_ninja -> move(victim);
                }
            }
        }
    }
}

/**
 * @return - the number of team members that are alive
 */
int Team :: stillAlive () const {
    int count = 0;
    // Count the number of warriors who are alive.
    for (size_t i = 0; i < _warriors_count; i++) {
        if (_warriors.at(i) -> isAlive()) { count++; }
    }
    return count;
}

/**
 * prints all characters in the team
 */
void Team :: print() const {
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<< Printing Team >>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    // Iterate first over the cowboys.
    for (size_t i = 0; i < _warriors_count; i++) {
        auto &temp_warrior = *_warriors.at(i);
        if (typeid (temp_warrior) == typeid (Cowboy)) {
            cout << _warriors.at(i) -> print() << endl;
        }
    }
    // Iterate now over the ninjas.
    for (size_t i = 0; i < _warriors_count; i++) {
        auto &temp_warrior = *_warriors.at(i);
        if (typeid (temp_warrior) != typeid (Cowboy)) {
            cout << _warriors.at(i) -> print() << endl;
        }
    }
}

/**
 *
 * @param team - the team we choose a warrior from
 * @param leader - the leader from which we find the closest warrior
 * @return  - the closest warrior to the leader which is alive
 */
Character* Team :: getClosest (Team* team, Character* leader) {
    // Create a pointer to the warrior we will return at the end.
    Character* warrior = team -> _warriors.at(0);
    // Save the minimum distance.
    double min_distance = numeric_limits <double> :: max();
    // Current distance for each of the warriors in team.
    double dist = 0;
    // Iterate over the team and return the closest warrior.
    for (size_t i = 0; i < team -> _warriors_count; i++) {
        dist = leader -> distance(team -> _warriors.at(i));
        if (team -> _warriors.at(i) -> isAlive() && dist < min_distance) {
            min_distance = dist;
            warrior = team -> _warriors.at(i);
        }
    }
    // Return the closest warrior found.
    return warrior;
}

// Get methods.
std :: array <Character*, MAX_NUM_OF_WARRIORS> Team :: getWarriors() const { return _warriors; }
size_t Team :: getWarriorsCount () const { return _warriors_count; }
Character* Team :: getLeader () const { return _leader; }

// Set methods.
void Team :: setWarriorsCount (size_t warriors_count) { _warriors_count = warriors_count; }
void Team :: setLeader (Character* leader) { _leader = leader; }