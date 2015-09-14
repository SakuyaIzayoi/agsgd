// iallocator.h
#ifndef INCLUDED_IALLOCATOR
#define INCLUDED_IALLOCATOR

namespace StevensDev
{

namespace sgdm
{

template <class T>
class IAllocator
{
  private:

  public:
    // MEMBER FUNCTIONS
    virtual T* get( int count ) = 0;
    virtual void release ( T*, int count ) = 0;
};

}

}

#endif
