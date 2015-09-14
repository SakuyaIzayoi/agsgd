// dynamic_array.h
#ifndef INCLUDED_DYNAMICARRAY
#define INCLUDED_DYNAMICARRAY

#include <counting_allocator.h>

namespace StevensDev
{

namespace sgdc
{

template <class T>
class DynamicArray
{
  private:
    unsigned int d_length;
    unsigned int d_maxSize;
    sgdm::IAllocator<T>* d_alloc;
    T *d_data;
  public:
    // CONSTRUCTORS
    DynamicArray();
    DynamicArray( const int size );
    DynamicArray( const DynamicArray &a );
    DynamicArray &operator=( const DynamicArray &a );
    DynamicArray( sgdm::IAllocator<T>* alloc );

    // DESTRUCTORS
    ~DynamicArray();

    // MEMBER FUNCTIONS
    void push( const T& element );
    void pushFront( T element );
    T pop();
    T popFront();
    unsigned int const getLength();
    unsigned int const getMaxSize();
    const T at( unsigned int index );
    T removeAt( unsigned int index );
    T insertAt( unsigned int index );
};

// CONSTRUCTORS
template <class T>
inline
DynamicArray<T>::DynamicArray() : d_length( 0 ),
    d_alloc( new sgdm::CountingAllocator<T> ),
    d_data( d_alloc->get( 16 ) ),
    d_maxSize( 16 )
{
} // Default Constructor

template <class T>
inline
DynamicArray<T>::DynamicArray( const int size ) :
    d_length( 0 ),
    d_alloc( new sgdm::CountingAllocator<T> ),
    d_data( d_alloc->get(size) ),
    d_maxSize( size )
{
} // Initial Size Constructor

template <class T>
inline
DynamicArray<T>::DynamicArray( sgdm::IAllocator<T>* alloc )
{
  d_alloc = alloc;
} // Copy Constructor

// MEMBER FUNCTIONS
template <class T>
inline
unsigned int const DynamicArray<T>::getLength()
{
    return d_length;
}

template <class T>
inline
unsigned int const DynamicArray<T>::getMaxSize()
{
    return d_maxSize;
}

template <class T>
void DynamicArray<T>::push( const T& element )
{
    if ( d_length >= d_maxSize )
    {
      // Reallocate array and grow.
    } else {
        d_data[d_length++] = element;
    }
}

} // End sgdc namespace.

} // End StevensDev namespace.

#endif
