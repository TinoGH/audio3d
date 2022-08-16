
#include <iostream>
#include <algorithm>
#include "Buffer.hpp"

using namespace std;

class Test_fill
{
private:
    double m_counter;

public:
    Test_fill() : m_counter(0.0) {}
    double operator()()
    {
        m_counter += 1.0;
        return m_counter;
    }
};

int main()
{
    Buffer buffer(16);
    vector<double> input(10, 0.0);
    vector<double> output(7, 0.0);
    Test_fill test_fill;

    for (int i = 0; i < 20; i++)
    {
        cout << "FRAME " << i + 1 << endl;
        generate(input.begin(), input.end(), test_fill);
        cout << "input" << endl;
        copy(input.begin(), input.end(), ostream_iterator<double>(cout, " "));
        cout << endl;
        buffer.write(input);
        cout << "after write" << endl << buffer << endl;
        buffer.read(output);
        cout << "output" << endl;
        copy(output.begin(), output.end(), ostream_iterator<double>(cout, " "));
        cout << endl;
        cout << "after read" << endl<< buffer << endl;
        cout << endl;
    }

    return 0;
}