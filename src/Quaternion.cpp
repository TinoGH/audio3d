#include "Quaternion.hpp"
#include <cmath>

using namespace std;

Axes::Axes(Coord const &ux_, Coord const &uy_, Coord const &uz_)
    : ux(ux_), uy(uy_), uz(uz_)
{
}

std::ostream &operator<<(std::ostream &stream, Axes const &a)
{
    return stream << a.ux.x << ", " << a.uy.x << ", " << a.uz.x << endl
                  << a.ux.y << ", " << a.uy.y << ", " << a.uz.y << endl
                  << a.ux.z << ", " << a.uy.z << ", " << a.uz.z << endl;
}

Quaternion::Quaternion(double s_, Coord const &v_)
    : s(s_), v(v_)
{
}

Quaternion::Quaternion(double w_, double x_, double y_, double z_)
    : s(w_), v(x_, y_, z_)
{
}

Quaternion::Quaternion(Coord const &axe, double angle)
{
    double sin_a2 = sin(angle / 2);
    s = cos(angle / 2);
    v = axe * sin_a2;
}

Quaternion::Quaternion(Eulers const &eulers)
{
    *this = Quaternion() *
            Quaternion(Coord(0.0, 0.0, 1.0), eulers.yaw) *
            Quaternion(Coord(0.0, 1.0, 0.0), eulers.pitch) *
            Quaternion(Coord(1.0, 0.0, 0.0), eulers.roll);
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

Coord Quaternion::rotation_inv(Coord const &vec) const
{
    return (conjugate() * Quaternion(0.0, vec) * *this).v;
}

Coord Quaternion::rotation(Coord const &vec) const
{
    return conjugate().rotation_inv(vec);
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

Eulers::Eulers(double yaw_, double pitch_, double roll_)
    : yaw(yaw_ * DEG2RAD), pitch(pitch_ * DEG2RAD), roll(roll_ * DEG2RAD)
{
}

Eulers::Eulers(Quaternion const &q)
{
    double test = 2 * (q.s * q.v.y - q.v.z * q.v.x);
    if (abs(test) < 1)
    {
        yaw = atan2(2 * (q.s * q.v.z + q.v.x * q.v.y),
                    1 - 2 * (q.v.y * q.v.y + q.v.z * q.v.z));
        pitch = asin(test);
        roll = atan2(2 * (q.s * q.v.x + q.v.y * q.v.z),
                     1 - 2 * (q.v.x * q.v.x + q.v.y * q.v.y));
    }
    else
    {
        yaw = copysign(2 * atan2(q.v.x, q.s), test);
        pitch = asin(test);
        roll = 0.0;
    }
}

std::ostream &operator<<(std::ostream &stream, Eulers const &e)
{
    return stream << "yaw: " << e.yaw * RAD2DEG << " degrees" << endl
                  << "pitch: " << e.pitch * RAD2DEG << " degrees" << endl
                  << "roll: " << e.roll * RAD2DEG << " degrees" << endl;
}