#ifndef COORD
#define COORD

#define PI 3.14159265358979323846

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
    Coord &operator+=(Coord const &c);
    Coord &operator-=(Coord const &c);
    Coord &operator*=(Coord const &c);
    Coord &operator*=(double d);
    Coord &operator/=(double d);
};

std::ostream &operator<<(std::ostream &stream, Coord const &coord);
Coord operator+(Coord const &c1, Coord const &c2);
Coord operator-(Coord const &c1, Coord const &c2);
Coord operator*(Coord const &c1, Coord const &c2);
Coord operator*(Coord const &c, double d);
Coord operator*(double d, Coord const &c);
Coord operator/(Coord const &c, double d);
double dot(Coord const &c1, Coord const &c2);

#endif