#include "Sound.hpp"

Sound::Sound(Coord const &position,
             Quaternion const &orientation,
             std::string const &name,
             Pattern *pattern)
    : Object(position, orientation, name),
      m_pattern(pattern)
{
}

Sound::~Sound()
{
    delete m_pattern;
}

void Sound::set_pattern(Pattern *pattern)
{
    m_pattern = pattern;
}