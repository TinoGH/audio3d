#include "Delay.hpp"

Delay::Delay(int max_delay)
    : Filter(max_delay)
{
}

Delay::~Delay()
{
}

Signal &Delay::process(Signal &signal, int delay)
{
    m_buffer.write(signal, delay);
    m_buffer.read(signal);
    return signal;
}