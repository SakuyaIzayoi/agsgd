// input.h
#ifndef INCLUDED_INPUT
#define INCLUDED_INPUT

#include <itickable.h>

namespace StevensDev
{

namespace sgdi
{

enum class InputType { UP, DOWN, LEFT, RIGHT };

class Input : public sgds::ITickable
{
  private:

  public:
    static Input& inst();
    bool isDown( InputType type );
    bool isUp( InputType type );
    bool wasPressed( InputType type );
    void preTick();
};

} // End sgdi namespace.

}

#endif
