#ifndef BUFFER
#define BUFFER

#include "Signal.hpp"
#include <ostream>

class Buffer
{
private:
    Signal m_samples;
    int m_size;
    int m_cursor;

public:
    Buffer(int size);
    ~Buffer();
    void write_sample(double sample, int delay = 0);
    double read_sample();
    void reset();
    void write(Signal const &input, int delay = 0);
    void read(Signal &output);
    void display(std::ostream &stream) const;
};

std::ostream &operator<<(
    std::ostream &stream, Buffer const &buffer);

#endif