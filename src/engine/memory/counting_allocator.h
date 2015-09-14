// counting_allocator.h
#ifndef INCLUDED_COUNTINGALLOCATOR
#define INCLUDED_COUNTINGALLOCATOR

#include "default_allocator.h"
#include <iostream>

namespace StevensDev
{

namespace sgdm
{

template <class T>
class CountingAllocator : public DefaultAllocator<T>
{
  private:
    static int d_totalAllocationCount;
    static int d_totalReleaseCount;
    static int d_totalOutstandingCount;
    int d_allocationCount;
    int d_releaseCount;
    int d_outstandingCount;
  public:
    // CONSTRUCTORS
    CountingAllocator();
    CountingAllocator( const CountingAllocator<T> &a );
    CountingAllocator& operator=( const CountingAllocator<T> &a );
    // DESTRUCTORS
    ~CountingAllocator();
    // ACCESSORS
    int getAllocationCount() const;
    int getReleaseCount() const;
    int getOutstandingCount() const;

    int getTotalAllocationCount();
    int getTotalReleaseCount();
    int getTotalOutstandingCount();
    // MEMBER FUNCTIONS
};

// CONSTRUCTORS
template <class T>
inline
CountingAllocator<T>::CountingAllocator() : d_allocationCount( 0 ),
    d_releaseCount( 0 ), d_outstandingCount( 0 )
{
}

template <class T>
inline
CountingAllocator<T>::CountingAllocator( const CountingAllocator<T> &a ) :
    d_allocationCount( a.getAllocationCount() ),
    d_releaseCount( a.getReleaseCount() ),
    d_outstandingCount( a.getOutstandingCount )
{
}

// FREE OPERATORS
template <class T>
inline
std::ostream& operator<<( std::ostream& stream,
    const CountingAllocator<T>& allocator )
{
  return stream << "{ allocationCount: " << allocator.getTotalAllocationCount()
    << ", releaseCount: " << allocator.getTotalReleaseCount()
    << ", outstandingCount: " << allocator.getTotalOutstandingCount() << " }";
}

// ACCESSORS
template <class T>
inline
int CountingAllocator<T>::getAllocationCount() const
{
  return d_allocationCount;
}

template <class T>
inline
int CountingAllocator<T>::getReleaseCount() const
{
  return d_releaseCount;
}

template <class T>
inline
int CountingAllocator<T>::getOutstandingCount() const
{
  return d_outstandingCount;
}

template <class T>
inline
int CountingAllocator<T>::getTotalAllocationCount()
{
  return d_totalAllocationCount;
}

template <class T>
inline
int CountingAllocator<T>::getTotalReleaseCount()
{
  return d_totalReleaseCount;
}

template <class T>
inline
int CountingAllocator<T>::getTotalOutstandingCount()
{
  return d_totalAllocationCount;
}

} // End sgdm namespace.

} // End StevensDev namespace.

#endif
