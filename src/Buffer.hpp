#ifndef BUFFER
#define BUFFER

#include <vector>
#include <ostream>
#include <iterator>

class Buffer
{
private:
    std::vector<double> m_array;
    int m_size;
    int m_cursor;
    
public:
    Buffer(int size);
    ~Buffer();
    void write(std::vector<double> const &input, int delay = 0);
    void read(std::vector<double> &output);
    void display(std::ostream &stream) const;
};

std::ostream &operator<<(
    std::ostream &stream, Buffer const &buffer);

#endif