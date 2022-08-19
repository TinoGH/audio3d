#ifndef SIGNAL
#define SIGNAL

#include <vector>
#include <ostream>

typedef std::vector<double> Signal;

inline std::ostream &operator<<(std::ostream &stream, Signal const &signal)
{
    for (double const &sample : signal)
        stream << sample << "\n";
    return stream;
}

#endif