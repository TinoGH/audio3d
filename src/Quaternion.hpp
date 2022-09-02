#ifndef QUATERNION
#define QUATERNION

#include <ostream>
#include "Coord.hpp"
#include "constants.hpp"

struct Axes
{
    Coord ux, uy, uz;

    Axes(Coord const &ux_ = Coord(1.0, 0.0, 0.0),
         Coord const &uy_ = Coord(0.0, 1.0, 0.0),
         Coord const &uz_ = Coord(0.0, 0.0, 1.0));
};

std::ostream &operator<<(std::ostream &stream, Axes const &a);

struct Eulers;
struct Quaternion
{
    double s;
    Coord v;

    Quaternion(double s_ = 1.0, Coord const &v_ = Coord());
    Quaternion(double w_, double x_, double y_, double z_);
    Quaternion(Coord const &axe, double angle);
    Quaternion(Eulers const &eulers);
    ~Quaternion();
    Quaternion conjugate() const;
    Axes matrix() const;
    double norm() const;
    void normalize();
    Coord rotation_inv(Coord const &vec) const;
    Coord rotation(Coord const &vec) const;
    Quaternion &operator*=(Quaternion const &q);
};

std::ostream &operator<<(std::ostream &stream, Quaternion const &q);
Quaternion operator*(Quaternion const &q1, Quaternion const &q2);

struct Eulers
{
    double yaw, pitch, roll;

    Eulers(double yaw_ = 0.0, double pitch_ = 0.0, double roll_ = 0.0);
    Eulers(Quaternion const &q);
};

std::ostream &operator<<(std::ostream &stream, Eulers const &e);

#endif