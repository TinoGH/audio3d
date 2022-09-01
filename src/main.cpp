#include <iostream>
#include <algorithm>
#include "Signal.hpp"
#include "Buffer.hpp"
#include "Delay.hpp"
#include "Coord.hpp"
#include "Quaternion.hpp"
#include "Eulers.hpp"

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
             << buffer
             << endl;
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

void test_coord()
{
    Coord a(1.0, 2.0, 3.0), b(6.0, 5.0, 4.0), c;

    cout << a << b << c << b - a << a * b << b / 2.0 << dot(a, b) << endl;
    a.normalize();
    cout << a << a.norm() << endl;
}

void test_quaternion()
{
    Quaternion q1(8.0, 7.0, 6.0, 5.0), q2(1.0, 2.0, 3.0, 4.0);
    q1.normalize();
    q2.normalize();
    Quaternion q3 = q1 * q2;
    Eulers a3 = q3.eulers();

    cout << q1 << q2 << q3 << q3.matrix() << q3.norm() << endl;
    cout << a3.yaw << ", " << a3.pitch << ", " << a3.roll << endl;
}

int main()
{
    test_quaternion();

    return 0;
}