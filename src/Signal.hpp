#ifndef SIGNAL
#define SIGNAL

#include <vector>
#include <ostream>

typedef std::vector<double> Signal;

inline std::ostream &operator<<(std::ostream &o, Signal const &v)
{
    for (auto const &i : v)
        o << i << " ";
    return o;
}

#endif