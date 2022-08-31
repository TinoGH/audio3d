#ifndef QUATERNION
#define QUATERNION

#include <ostream>
#include <cmath>

struct Quaternion
{
    double s, x, y, z;

    Quaternion(
        double s_ = 1.0,
        double x_ = 0.0,
        double y_ = 0.0,
        double z_ = 0.0);

    ~Quaternion();
};

std::ostream &operator<<(
    std::ostream &stream, Quaternion const &quaternion);

#endif