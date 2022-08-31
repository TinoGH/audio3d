#include "Coord.hpp"

Coord::Coord(double x_, double y_, double z_)
        : x(x_), y(y_), z(z_)
{
}

Coord::~Coord()
{
}

double Coord::norm() const
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void Coord::normalize()
{
    double n = norm();
    x /= n;
    y /= n;
    z /= n;
}

Coord Coord::operator-() const
{
    return Coord(-x, -y, -z);
}

Coord &Coord::operator+=(Coord const &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Coord &Coord::operator-=(Coord const &other)
{
    return *this += -other;
}

std::ostream &operator<<(std::ostream &stream, Coord const &coord)
{
    stream << "("
           << coord.x << ", "
           << coord.y << ", "
           << coord.z << ")\n";
    return stream;
}

Coord operator+(Coord const &coord_1, Coord const &coord_2)
{
    return Coord(coord_1) += coord_2;
}

Coord operator-(Coord const &coord_1, Coord const &coord_2)
{
    return Coord(coord_1) -= coord_2;
}