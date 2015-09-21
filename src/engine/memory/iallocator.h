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
    virtual void release ( T* address, int count ) = 0;
    virtual void construct( T* pointer, const T& copy ) = 0;
    //virtual void construct( T* pointer, T&& copy ) = 0;
    virtual void destruct( T* pointer ) = 0;
};

}

}

#endif
