// Created by Shalev Ben David.

#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace ariel;
using namespace std;

/**
 * @param other - other point
 * @return - the distance between this and other
 */
double Point :: distance (Point other) const {
    return sqrt(pow(_px - other._px, 2) + pow(_py - other._py, 2));
}

/**
 * @param source - source point
 * @param dest - destination point
 * @param dist - distance
 * @return - the closest point to dest such that the distance between it and source < dist
 */
Point Point :: moveTowards (Point source, Point dest, double dist) {
    if (dist < 0) {
        throw invalid_argument ("Distance can't be negative!");
    }
    // If "dest" is already at distance "dist" or less, return it.
    if (source.distance(dest) <= dist) {
        return dest;
    }
    // Else, the closest point is somewhere on the vector connecting source and dest.
    // Find the relative portion of dist from the whole vector.
    double portion = dist / source.distance(dest);
    // Return the point at the end of the portion (vector wise).
    // Source: https://math.stackexchange.com/questions/175896/finding-a-point-along-a-line-a-certain-distance-away-from-another-point
    return Point ((1 - portion) * source._px + portion * dest._px,
                  (1 - portion) * source._py + portion * dest._py);
}

/**
 * print point in the form (x,y)
 */
void Point :: print () const {
    cout << "(" << _px << ", " << _py << ")";
}

/**
 * @return - string representing the point
 */
string Point :: toString () const {
    string info;
    info = "(" +  to_string(_px) + ", " +  to_string(_py) + ")";
    return info;
}