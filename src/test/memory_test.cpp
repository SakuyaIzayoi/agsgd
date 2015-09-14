// memory_test.cpp
#include <counting_allocator.h>
#include "test.h"

TEST(CountingAllocatorConstructorsTest, DefaultConstructor)
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> *a;
  a = new sgdm::CountingAllocator<int>;

  ASSERT_TRUE(a != 0);
  ASSERT_TRUE(a->getAllocationCount() == 0);
  ASSERT_TRUE(a->getReleaseCount() == 0);
  ASSERT_TRUE(a->getOutstandingCount() == 0);
}

TEST(CountingAllocatorConstructorsTest, CopyConstructor)
{
  using namespace StevensDev;

  sgdm::CountingAllocator<int> *a;
  sgdm::CountingAllocator<int> *b;
  a = new sgdm::CountingAllocator<int>;
  b = a;

  ASSERT_TRUE(b == a);
}

TEST(CountingAllocatorTrackingTest, AllocationCounting)
{
    using namespace StevensDev;

    int *a, *b;

    sgdm::CountingAllocator<int> *alloc;
    alloc = new sgdm::CountingAllocator<int>;

    a = alloc->get( 4 );
    b = alloc->get( 4 );

    ASSERT_TRUE( alloc->getAllocationCount() == 2 );
    ASSERT_TRUE( sgdm::CountingAllocator<int>::getTotalAllocationCount() == 2 );

    alloc->release( a, 1 );

    ASSERT_TRUE( alloc->getReleaseCount() == 1 );
    ASSERT_TRUE( sgdm::CountingAllocator<int>::getTotalReleaseCount() == 1 );
    ASSERT_TRUE( alloc->getOutstandingCount() == 1 );
    ASSERT_TRUE(
        sgdm::CountingAllocator<int>::getTotalOutstandingCount() == 1 );

    alloc->release( b, 1 );
    ASSERT_TRUE( alloc->getReleaseCount() == 2 );
    ASSERT_TRUE( sgdm::CountingAllocator<int>::getTotalReleaseCount() == 2 );
    ASSERT_TRUE( alloc->getOutstandingCount() == 0 );
    ASSERT_TRUE(
        sgdm::CountingAllocator<int>::getTotalOutstandingCount() == 0 );
}
