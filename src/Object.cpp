#include "Object.hpp"
#include "constants.hpp"
#include <cmath>

using namespace std;

Object::Object(Coord const &position,
               Quaternion const &orientation,
               std::string const &name)
    : m_position(position),
      m_orientation(orientation),
      m_name(name)
{
}

Object::~Object()
{
}

Coord Object::position() const
{
    return m_position;
}

Quaternion Object::orientation() const
{
    return m_orientation;
}

std::string Object::name() const
{
    return m_name;
}

void Object::set_position(Coord const &position)
{
    m_position = position;
}

void Object::translate(Coord const &vec)
{
    m_position += vec;
}

void Object::set_orientation(Quaternion const &orientation)
{
    m_orientation = orientation;
}

void Object::reset_orientation()
{
    m_orientation = Quaternion();
}

void Object::rotate(Quaternion const &orientation)
{
    m_orientation *= orientation;
}

void Object::set_name(std::string const &name)
{
    m_name = name;
}

double Object::distance(Object const &target) const
{
    return (target.position() - m_position).norm();
}

Coord Object::rel_position(Object const &target) const
{
    return m_orientation.rotation_inv(target.position() - m_position);
}

Coord Object::rel_direction(Object const &target) const
{
    Coord direction = rel_position(target);
    direction.normalize();
    return direction;
}

double Object::rel_angle(Object const &target) const
{
    return acos(rel_direction(target).x);
}

Sphericals Object::rel_sphericals(Object const &target) const
{
    return Sphericals(rel_position(target));
}