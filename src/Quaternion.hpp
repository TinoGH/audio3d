#ifndef QUATERNION
#define QUATERNION

#include <ostream>
#include "Coord.hpp"
#include "Axes.hpp"
#include "Eulers.hpp"

struct Quaternion
{
    double s;
    Coord v;

    Quaternion(double s_ = 1.0, double x_ = 0.0, double y_ = 0.0, double z_ = 0.0);
    Quaternion(double s_, Coord v_);
    ~Quaternion();
    Quaternion conjugate() const;
    Axes matrix() const;
    Eulers eulers() const;
    double norm() const;
    void normalize();
    Quaternion &operator*=(Quaternion const &q);
};

std::ostream &operator<<(std::ostream &stream, Quaternion const &q);
Quaternion operator*(Quaternion const &q1, Quaternion const &q2);

#endif