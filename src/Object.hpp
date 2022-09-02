#ifndef OBJECT
#define OBJECT

#include "Coord.hpp"
#include "Quaternion.hpp"
#include <string>

class Object
{
protected:
    Coord m_position;
    Quaternion m_orientation;
    std::string m_name;

public:
    Object(Coord const &position = Coord(),
           Quaternion const &orientation = Quaternion(),
           std::string const &name = "object");
    ~Object();
    Coord position() const;
    Quaternion orientation() const;
    std::string name() const;
    void set_position(Coord const &position);
    void translate(Coord const &vec);
    void set_orientation(Quaternion const &orientation);
    void reset_orientation();
    void rotate(Quaternion const &orientation);
    void set_name(std::string const &name);
    double distance(Object const &target) const;
    Coord rel_position(Object const &target) const;
    Coord rel_direction(Object const &target) const;
    double rel_angle(Object const &target) const;
    Sphericals rel_sphericals(Object const &target) const;
};

#endif