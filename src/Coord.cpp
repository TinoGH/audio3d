#include "Coord.hpp"
#include "constants.hpp"

using namespace std;

Coord::Coord(double x_, double y_, double z_)
    : x(x_), y(y_), z(z_)
{
}

Coord::Coord(Sphericals const &s)
{
    double sin_azimuth = sin(s.azimuth);
    x = s.radius * cos(s.elevation) * sin_azimuth;
    y = s.radius * sin(s.elevation) * sin_azimuth;
    z = s.radius * cos(s.azimuth);
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

Sphericals::Sphericals(double azimuth_, double elevation_, double radius_)
    : azimuth(azimuth_), elevation(elevation_), radius(radius_)
{
}

Sphericals::Sphericals(Coord const &c)
    : azimuth(atan2(c.y, c.x)),
      elevation(atan2(c.z, sqrt(c.x * c.x + c.y * c.y))),
      radius(c.norm())
{
}

std::ostream &operator<<(std::ostream &stream, Sphericals const &s)
{
    return stream << "azimuth: " << s.azimuth * RAD2DEG << " degrees" << endl
                  << "elevation: " << s.elevation * RAD2DEG << " degrees" << endl
                  << "radius: " << s.radius << endl;
}