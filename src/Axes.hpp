#ifndef AXES
#define AXES

#include "Coord.hpp"
#include <ostream>

struct Axes
{
    Coord ux, uy, uz;

    Axes(Coord const &ux_ = Coord(1.0, 0.0, 0.0),
         Coord const &uy_ = Coord(0.0, 1.0, 0.0),
         Coord const &uz_ = Coord(0.0, 0.0, 1.0))
        : ux(ux_), uy(uy_), uz(uz_) {}
    ~Axes() {}
};

inline std::ostream &operator<<(std::ostream &stream, Axes const &a)
{
    return stream << a.ux << a.uy << a.uz;
}

#endif