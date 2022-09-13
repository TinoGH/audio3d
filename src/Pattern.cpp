#include "Pattern.hpp"

Pattern::Pattern()
{
}

Pattern::~Pattern()
{
}

Signal Pattern::get_directivity(Coord const &direction)
{
    return Signal(1, 1.0);
}