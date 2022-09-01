#include "Quaternion.hpp"

using namespace std;

Quaternion::Quaternion(double s_, double x_, double y_, double z_)
    : s(s_), v(x_, y_, z_)
{
}

Quaternion::Quaternion(double s_, Coord v_)
    : s(s_), v(v_)
{
}

Quaternion::~Quaternion()
{
}

std::ostream &operator<<(std::ostream &stream, Quaternion const &q)
{
    return stream << q.s << " + "
                  << q.v.x << ".i + "
                  << q.v.y << ".j + "
                  << q.v.z << ".k\n";
}

Quaternion Quaternion::conjugate() const
{
    return Quaternion(s, -v);
}

Axes Quaternion::matrix() const
{
    return Axes(
        Coord(
            1 - 2 * (v.y * v.y + v.z * v.z),
            2 * (v.x * v.y + v.z * s),
            2 * (v.x * v.z - v.y * s)),
        Coord(
            2 * (v.x * v.y - v.z * s),
            1 - 2 * (v.x * v.x + v.z * v.z),
            2 * (v.y * v.z + v.x * s)),
        Coord(
            2 * (v.x * v.z + v.y * s),
            2 * (v.y * v.z - v.x * s),
            1 - 2 * (v.x * v.x + v.y * v.y)));
}

Eulers Quaternion::eulers() const
{
    Eulers angles;
    double rad_to_deg = 180.0 / PI;
    double test = 2 * (s * v.y + v.x * v.y);
    if (abs(test) < 1)
    {
        angles.yaw = atan2(2 * (s * v.z + v.x * v.y),
                           1 - 2 * (v.y * v.y + v.z * v.z)) *
                     rad_to_deg;
        angles.pitch = asin(test) * rad_to_deg;
        angles.roll = atan2(2 * (s * v.x + v.y * v.z),
                            1 - 2 * (v.x * v.x + v.y * v.y)) *
                      rad_to_deg;
    }
    else
    {
        angles.yaw = copysign(2 * atan2(v.x, s), test) * rad_to_deg;
        angles.pitch = asin(test) * rad_to_deg;
        angles.roll = 0.0;
    }
    return angles;
}

double Quaternion::norm() const
{
    return sqrt(s * s + v.x * v.x + v.y * v.y + v.z * v.z);
}

void Quaternion::normalize()
{
    double n = norm();
    s /= n;
    v /= n;
}

Quaternion &Quaternion::operator*=(Quaternion const &q)
{
    double s_ = s * q.s - dot(v, q.v);
    v = s * q.v + q.s * v + v * q.v;
    s = s_;
    return *this;
}

Quaternion operator*(Quaternion const &q1, Quaternion const &q2)
{
    return Quaternion(q1) *= q2;
}