// dynamic_array.h
#ifndef INCLUDED_DYNAMICARRAY
#define INCLUDED_DYNAMICARRAY

#include <counting_allocator.h>
#include <stdexcept>

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
    T operator []( int i );
    T removeAt( unsigned int index );
    void insertAt( unsigned int index , const T& element);
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
} // Initial allocator Constructor

// DESTRUCTOR
template <class T>
inline
DynamicArray<T>::~DynamicArray<T>()
{
    delete[] d_data;
}

// FREE OPERATORS
template <class T>
inline
std::ostream& operator<<( std::ostream& stream, const DynamicArray<T>& array )
{
    return stream << "{ d_length: " << array.getLength() << ", d_maxSize: "
        << array.getMaxSize() << " }";
}
// MEMBER FUNCTIONS
template <class T>
inline
unsigned int const DynamicArray<T>::getLength()
{
    return d_length;
}
// Returns current length of array.

template <class T>
inline
unsigned int const DynamicArray<T>::getMaxSize()
{
    return d_maxSize;
}
// Returns maximum allocated size of array.

template <class T>
void DynamicArray<T>::push( const T& element )
{
    if ( d_length >= d_maxSize )
    {
        // Reallocate array and grow.
        d_maxSize += 32;
        T *newArray = new T[d_maxSize];

        memcpy( newArray, d_data, sizeof(T) * d_maxSize );

        d_data = newArray;
    }
    d_data[d_length++] = element; // Push element to back.
}
// Pushes item to end of list.

template <class T>
void DynamicArray<T>::pushFront( T element )
{
    if ( d_length >= d_maxSize )
    {
        // Reallocate array and grow.
        d_maxSize += 32;
        T *newArray = new T[d_maxSize];

        memcpy( newArray, d_data, sizeof(T) * d_maxSize );

        d_data = newArray;
    }
        // Push element to front; shift others over.
        for ( int i = d_length - 1; i >= 0; i-- )
        {
            d_data[i+1] = d_data[i];
        }
        d_data[0] = element;
}
// Push to front of array and grow array if necessary.

template <class T>
T DynamicArray<T>::pop()
{
    T ret = d_data[--d_length];
    return ret;
}
// Pop last element from array and return it.

template <class T>
T DynamicArray<T>::popFront()
{
    T ret = d_data[0];

    for (int i = 0; i < d_length; i++)
    {
        d_data[i] = d_data[i + 1];
    }

    d_length--;
    return ret;
}
// Pop first element in array and return it.

template <class T>
const T DynamicArray<T>::at( unsigned int index )
{
    if ( index > d_length )
    {
        throw(std::out_of_range("Array out of bounds"));
    }
    return d_data[index];
}
// Return element at position. Throws out of bounds exception if trying to
// access beyond array bounds.

template <class T>
inline
T DynamicArray<T>::operator[]( int i )
{
    return d_data[i];
}
// Square bracket operator.

template <class T>
T DynamicArray<T>::removeAt( unsigned int index )
{
    T ret = d_data[index];
    for ( int i = index; i <= d_length; i++ )
    {
        d_data[i] = d_data[i+1];
    }
    d_length--;
    return ret;
}
// Remove element from specified index.

template <class T>
void DynamicArray<T>::insertAt( unsigned int index, const T& element )
{
    if ( d_length >= d_maxSize )
    {
        // Reallocate array and grow.
        d_maxSize += 32;
        T *newArray = new T[d_maxSize];

        memcpy( newArray, d_data, sizeof(T) * d_maxSize );

        d_data = newArray;
    }

    for ( int i = d_length - 1; i >= 0; i-- )
    {
        d_data[i+1] = d_data[i];
    }
    d_data[index] = element;
    d_length++;
}
// Insert element at specified array index.

} // End sgdc namespace.

} // End StevensDev namespace.

#endif
