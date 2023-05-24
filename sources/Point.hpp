// Created by Shalev Ben David.

#ifndef SP2_EX4A_POINT_H
#define SP2_EX4A_POINT_H
#include <string>

namespace ariel {
    class Point {
    private:
        double _px;
        double _py;

    public:
        // Constructors.
        Point (double p_x = 0, double p_y = 0) : _px(p_x), _py(p_y) {}

        // Methods.
        double distance (Point other) const;
        static Point moveTowards (Point source, Point dest, double dist);

        // Print method.
        void print () const;

        // toString method.
        std :: string toString () const;

        // Get && Set methods.
        double getX () const { return _px; }
        double getY () const { return _py; }
        void setX (double new_x) { _px = new_x; }
        void setY (double new_y ) { _py = new_y; }

        // Operator == and !=
        bool operator == (const Point& other) const {
            return (_px == other._px) && (_py == other._py);
        }
        bool operator != (const Point& other) const {
            return !(*this == other);
        }
    };
}

#endif //SP2_EX4A_POINT_H