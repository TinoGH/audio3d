#ifndef COORD
#define COORD

#include <ostream>
#include <cmath>

struct Coord
{
    double x, y, z;

    Coord(double x_ = 0, double y_ = 0, double z_ = 0)
        : x(x_), y(y_), z(z_)
    {
    }

    double norm() const
    {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    void normalize()
    {
        double n = norm();
        x /= n;
        y /= n;
        z /= n;
    }

    Coord operator-() const
    {
        return Coord(-x, -y, -z);
    }

    Coord &operator+=(Coord const &other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Coord &operator-=(Coord const &other)
    {
        return *this += -other;
    }
};

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

#endif