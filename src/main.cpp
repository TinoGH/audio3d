#include <iostream>
#include <algorithm>
#include "Signal.hpp"
#include "Buffer.hpp"
#include "Delay.hpp"
#include "Coord.hpp"
#include "Quaternion.hpp"
#include "Object.hpp"

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
    Eulers a3(q3);

    cout << q1 << q2 << q3 << q3.matrix() << q3.norm() << endl;
    cout << a3 << endl;
    cout << endl;

    Quaternion q4(a3);
    Eulers a4(q4);

    cout << q4 << q4.norm() << endl;
    cout << a4 << endl;
    cout << endl;

    Quaternion q(0.8446232, 0.1913417, 0.4619398, 0.1913417);
    Eulers a(q);

    cout << q << q.matrix() << q.norm() << endl;
    cout << a << endl;
    cout << endl;

    Quaternion qt(Eulers(0.0, 45.0, 0.0));
    Eulers at(qt);

    cout << qt << qt.matrix() << qt.norm() << endl;
    cout << at << endl;
    cout << endl;
}

void test_object()
{
    Object spk(Coord(1.0, 1.0, 1.0)), mic;

    cout << mic.rel_sphericals(spk) << endl;
}

int main()
{
    test_object();

    return 0;
}