#include "Buffer.hpp"
#include <assert.h>

using namespace std;

Buffer::Buffer(int size)
    : m_size(size)
{
    reset();
}

Buffer::~Buffer()
{
}

void Buffer::reset()
{
    m_samples = Signal(m_size, 0.0);
    m_cursor = 0;
}

void Buffer::write_sample(double sample, int offset)
{
    assert(offset < m_size);
    m_samples[(m_cursor + offset) % m_size] += sample;
}

double Buffer::read_sample()
{
    double sample = m_samples[m_cursor];
    m_samples[m_cursor] = 0.0;
    ++m_cursor %= m_size;
    return sample;
}

void Buffer::write(Signal const &input, int offset)
{
    for (int i = 0; i < input.size(); i++)
    {
        write_sample(input[i], offset + i);
    }
}

void Buffer::read(Signal &output)
{
    for (double &sample : output)
    {
        sample = read_sample();
    }
    // generate(output.begin(), output.end(), read_sample);
    // doesnt work, why?
}

void Buffer::display(ostream &stream) const
{
    stream << m_samples << endl;
}

ostream &operator<<(ostream &stream, Buffer const &buffer)
{
    buffer.display(stream);
    return stream;
}