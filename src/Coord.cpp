#include "Coord.hpp"

using namespace std;

Coord::Coord(double x_, double y_, double z_)
    : x(x_), y(y_), z(z_)
{
}

Coord::~Coord()
{
}

std::ostream &operator<<(std::ostream &stream, Coord const &c)
{
    return stream << "("
                  << c.x << ", "
                  << c.y << ", "
                  << c.z << ")\n";
}

double Coord::norm() const
{
    return sqrt(x * x + y * y + z * z);
}

void Coord::normalize()
{
    *this /= norm();
}

Coord Coord::operator-() const
{
    return Coord(-x, -y, -z);
}

Coord &Coord::operator+=(Coord const &c)
{
    x += c.x;
    y += c.y;
    z += c.z;
    return *this;
}

Coord &Coord::operator-=(Coord const &c)
{
    return *this += -c;
}

Coord &Coord::operator*=(Coord const &c)
{
    double x_ = y * c.z - z * c.y;
    double y_ = z * c.x - x * c.z;
    z = x * c.y - y * c.x;
    x = x_;
    y = y_;
    return *this;
}

Coord &Coord::operator*=(double d)
{
    x *= d;
    y *= d;
    z *= d;
    return *this;
}

Coord &Coord::operator/=(double d)
{
    return *this *= (1 / d);
}

Coord operator+(Coord const &c1, Coord const &c2)
{
    return Coord(c1) += c2;
}

Coord operator-(Coord const &c1, Coord const &c2)
{
    return Coord(c1) -= c2;
}

Coord operator*(Coord const &c1, Coord const &c2)
{
    return Coord(c1) *= c2;
}

Coord operator*(Coord const &c, double d)
{
    return Coord(c) *= d;
}

Coord operator*(double d, Coord const &c)
{
    return c * d;
}

Coord operator/(Coord const &c, double d)
{
    return Coord(c) /= d;
}

double dot(Coord const &c1, Coord const &c2)
{
    return c1.x * c2.x + c1.y * c2.y + c1.z * c2.z;
}