// default_allocator.h
#ifndef INCLUDED_DEFAULT_ALLOCATOR
#define INCLUDED_DEFAULT_ALLOCATOR

#include "iallocator.h"
#include <iostream>

namespace StevensDev
{

namespace sgdm
{

template <class T>
class DefaultAllocator : public IAllocator<T>
{
  private:

  public:
    // CONSTRUCTORS
    DefaultAllocator();
    DefaultAllocator( DefaultAllocator& a );
    DefaultAllocator& operator=( const DefaultAllocator &a );
    // DESTRUCTORS
    ~DefaultAllocator();
    // MEMBER FUNCTIONS
    T* get( int count );
    void release( T* ptr, int count );
};

template <class T>
inline
DefaultAllocator<T>::DefaultAllocator()
{
}

template <class T>
inline
DefaultAllocator<T>::DefaultAllocator( DefaultAllocator& a )
{
}

template <class T>
DefaultAllocator<T>& DefaultAllocator<T>::operator=( const DefaultAllocator& a )
{
  if (this == &a)
  {
    return *this;
  }
  return *this;
}

template <class T>
inline
std::ostream& operator<<( std::ostream& stream, const DefaultAllocator<T>& allocator )
{
    return stream << "{ defaultAllocator: " << "PUT SOMETHING HERE" << " }";
}

template <class T>
inline
T* DefaultAllocator<T>::get( int count )
{
  return new T[count];
}

template <class T>
inline
void DefaultAllocator<T>::release( T* ptr, int count )
{
  delete[] (ptr);
}

} // End sgdm namespace.

} // End StevensDev namespace.

#endif
