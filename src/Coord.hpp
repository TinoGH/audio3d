#ifndef COORD
#define COORD

#include <ostream>
#include <cmath>

struct Coord
{
    double x, y, z;

    Coord(double x_ = 0.0, double y_ = 0.0, double z_ = 0.0);
    ~Coord();
    double norm() const;
    void normalize();
    Coord operator-() const;
    Coord &operator+=(Coord const &other);
    Coord &operator-=(Coord const &other);
};

std::ostream &operator<<(std::ostream &stream, Coord const &coord);
Coord operator+(Coord const &coord_1, Coord const &coord_2);
Coord operator-(Coord const &coord_1, Coord const &coord_2);
Coord operator*(Coord const &coord_1, Coord const &coord_2);

#endif