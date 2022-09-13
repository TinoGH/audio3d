#ifndef PATTERN
#define PATTERN

#include "Signal.hpp"
#include "Coord.hpp"

class Pattern
{
protected:
public:
    Pattern();
    virtual ~Pattern();
    virtual Signal get_directivity(Coord const &direction = Coord(1.0));
};

#endif