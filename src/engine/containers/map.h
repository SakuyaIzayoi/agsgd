// map.h

#ifndef INCLUDED_MAP
#define INCLUDED_MAP

#include <dynamic_array.h>
#include <iallocator.h>
#include <string>

namespace StevensDev
{

namespace sgdc
{

template <class T>
class Map
{
  private:
    sgdm::IAllocator<T>* d_alloc;
    DynamicArray<T> d_data;
  public:
    // CONSTRUCTORS
    Map();
    Map( const Map &map );
    Map& operator=( const Map &map );
    Map( sgdm::IAllocator<T>* alloc );

    // DESTRUCTORS
    ~Map();

    // MEMBER FUNCTIONS
    Map &operator[] ( const std::string& key );
    Map &operator[] ( const std::string& key ) const;
    bool has( const std::string& key );
    T remove( const std::string& key );
    DynamicArray<std::string> keys() const;
    DynamicArray<T> values() const;
};

// CONSTRUCTORS

template <class T>
inline
Map<T>::Map() : d_alloc( new sgdm::CountingAllocator<T> ),
    d_data( new DynamicArray<T>( 1024 ) )
{
}

template <class T>
inline
Map<T>::Map( sgdm::IAllocator<T>* alloc ) :
    d_data( new DynamicArray<T>( 1024 ) )
{
    d_alloc = alloc;
}

template <class T>
inline
Map<T>::Map( const Map &map ) : d_data( map.d_data ), d_alloc( map.d_alloc )
{
}

} // End sgdc namespace.

} // End StevensDev namespace.

#endif
