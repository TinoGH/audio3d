#include "Signal.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include "Buffer.hpp"
#include "Delay.hpp"

using namespace std;

double test_fill()
{
    static double n(0);
    return ++n;
}

void test_buffer()
{
    Buffer buffer(16);
    Signal input(10, 0.0);
    Signal output(7, 0.0);

    for (int i = 0; i < 20; i++)
    {
        cout << "FRAME " << i + 1 << endl;
        generate(input.begin(), input.end(), test_fill);
        cout << "input" << endl
             << input << endl;
        buffer.write(input, i % 7);
        cout << "after write" << endl
             << buffer;
        buffer.read(output);
        cout << "output" << endl
             << output << endl
             << endl;
        cout << "after read" << endl
             << buffer;
        cout << endl;
    }
}

void test_delay()
{
    Delay delay_1(16);
    Delay delay_2(16);
    Signal signal(5, 0.0);

    for (int i = 0; i < 5; i++)
    {
        cout << "FRAME " << i + 1 << endl;
        generate(signal.begin(), signal.end(), test_fill);
        cout << "input" << endl
             << signal << endl;
        delay_1.process(delay_2.process(signal, 3), 7);
        cout << "output" << endl
             << signal << endl
             << endl;
    }
}

int main()
{
    test_delay();

    return 0;
}