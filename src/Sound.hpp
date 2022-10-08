#ifndef SOUND
#define SOUND

#include "Object.hpp"
#include "Pattern.hpp"

class Sound : public Object
{
protected:
    Pattern *m_pattern;
    
public:
    Sound(Coord const &position = Coord(),
          Quaternion const &orientation = Quaternion(),
          std::string const &name = "object",
          Pattern *pattern = new Pattern());
    virtual ~Sound();
    void set_pattern(Pattern *pattern);
};

class Source : Sound
{
private:
public:
    Source();
    ~Source();
};

Source::Source()
{
}

Source::~Source()
{
}


#endif