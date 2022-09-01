#include "Filter.hpp"

using namespace std;

Filter::Filter(int buffer_size)
    : m_buffer(buffer_size)
{
}

Filter::~Filter()
{
}

Signal &Filter::process(Signal &signal)
{
    m_buffer.write(signal);
    m_buffer.read(signal);
    return signal;
}