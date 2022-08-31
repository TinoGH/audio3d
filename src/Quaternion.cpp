#include "Quaternion.hpp"

Quaternion::Quaternion(double s_, double x_, double y_, double z_)
    : s(s_), x(x_), y(y_), z(z_)
{
}

Quaternion::~Quaternion()
{
}

std::ostream &operator<<(
    std::ostream &stream, Quaternion const &quaternion)
{
    stream << "("
           << quaternion.s
           << quaternion.x << ", "
           << quaternion.y << ", "
           << quaternion.z << ")\n";
    return stream;
}