// itickable.h
#ifndef INCLUDED_ITICKABLE
#define INCLUDED_ITICKABLE

namespace StevensDev
{

namespace sgds
{

class ITickable
{
  private:

  public:
  // MEMBER FUNCTIONS
  virtual void preTick() = 0;
  virtual void tick( float dtS ) = 0;
  virtual void postTick() = 0;
};

}

}
#endif
