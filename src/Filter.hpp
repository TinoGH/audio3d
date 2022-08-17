#ifndef FILTER
#define FILTER

#include "Buffer.hpp"

class Filter
{
protected:
    Buffer m_buffer;

public:
    Filter(int buffer_size);
    virtual ~Filter();
    virtual Signal &process(Signal &signal);
};

#endif