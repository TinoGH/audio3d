#ifndef DELAY
#define DELAY

#include "Filter.hpp"

class Delay : public Filter
{
private:
public:
    Delay(int max_delay);
    ~Delay();
    virtual Signal &process(Signal &signal, int delay);
};

#endif