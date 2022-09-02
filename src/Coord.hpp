#ifndef COORD
#define COORD

#include <ostream>
#include <cmath>

struct Sphericals;
struct Coord
{
    double x, y, z;

    Coord(double x_ = 0.0, double y_ = 0.0, double z_ = 0.0);
    Coord(Sphericals const &s);
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

std::ostream &operator<<(std::ostream &stream, Coord const &c);
Coord operator+(Coord const &c1, Coord const &c2);
Coord operator-(Coord const &c1, Coord const &c2);
Coord operator*(Coord const &c1, Coord const &c2);
Coord operator*(Coord const &c, double d);
Coord operator*(double d, Coord const &c);
Coord operator/(Coord const &c, double d);
double dot(Coord const &c1, Coord const &c2);

struct Sphericals
{
    double azimuth, elevation, radius;

    Sphericals(double azimuth_ = 0.0, double elevation_ = 0.0, double radius_ = 1.0);
    Sphericals(Coord const &c);
};

std::ostream &operator<<(std::ostream &stream, Sphericals const &s);

#endif