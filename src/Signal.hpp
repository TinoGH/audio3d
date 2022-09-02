#ifndef SIGNAL
#define SIGNAL

#include <vector>
#include <ostream>
#include <algorithm>
#include <iterator>

typedef std::vector<double> Signal;

inline std::ostream &operator<<(std::ostream &stream, Signal const &signal)
{
    std::copy(signal.begin(), signal.end(),
              std::ostream_iterator<double>(stream, "\n"));

    return stream;
}

#endif