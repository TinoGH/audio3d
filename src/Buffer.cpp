#include "Buffer.hpp"
#include <algorithm>

using namespace std;

Buffer::Buffer(int size)
    : m_size(size),
      m_cursor(0)
{
    m_array = vector<double>(m_size, 0.0);
}

Buffer::~Buffer()
{
}

void Buffer::write(vector<double> const &input, int delay)
{
    int id(0);
    for (int i = 0; i < input.size(); i++)
    {
        id = (m_cursor + i + delay) % m_size;
        m_array[id] += input[i];
    }
}

void Buffer::read(vector<double> &output)
{
    int n_samples = output.size();
    int id(0);
    for (int i = 0; i < n_samples; i++)
    {
        id = (m_cursor + i) % m_size;
        output[i] = m_array[id];
        m_array[id] = 0;
    }
    m_cursor = (m_cursor + n_samples) % m_size;
}

void Buffer::display(ostream &stream) const
{
    copy(m_array.begin(), m_array.end(), ostream_iterator<double>(stream, " "));
}

ostream &operator<<(ostream &stream, Buffer const &buffer)
{
    buffer.display(stream);
    return stream;
}