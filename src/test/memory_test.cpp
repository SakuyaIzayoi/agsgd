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

    delete a;
}

TEST(CountingAllocatorConstructorsTest, CopyConstructor)
{
    using namespace StevensDev;

    sgdm::CountingAllocator<int> *a;
    sgdm::CountingAllocator<int> *b;
    a = new sgdm::CountingAllocator<int>;
    b = a;

    ASSERT_TRUE(b == a);

    delete a;
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
    ASSERT_TRUE( sgdm::CountingAllocator<int>::getTotalOutstandingCount() == 1 );

    alloc->release( b, 1 );
    ASSERT_TRUE( alloc->getReleaseCount() == 2 );
    ASSERT_TRUE( sgdm::CountingAllocator<int>::getTotalReleaseCount() == 2 );
    ASSERT_TRUE( alloc->getOutstandingCount() == 0 );
    ASSERT_TRUE( sgdm::CountingAllocator<int>::getTotalOutstandingCount() == 0 );

    delete alloc;
}

TEST(DefaultAllocatorTest, Constructing)
{
    using namespace StevensDev;

    std::string *strings = new std::string[5];

    strings[0] = "Zero";
    strings[1] = "One";
    strings[2] = "Two";
    strings[3] = "Three";
    strings[4] = "Four";

    std::string *memory;

    sgdm::CountingAllocator<std::string> *alloc;
    alloc = new sgdm::CountingAllocator<std::string>;

    memory = alloc->get( 5 );
    for ( int i = 0; i < 5; i++ )
    {
        alloc->construct( &memory[i], strings[i] );
    }

    for ( int i = 0; i < 5; i++ )
    {
        ASSERT_TRUE(!memory[i].compare(strings[i]));
    }

    for ( int i = 0; i < 5; i++ )
    {
        alloc->destruct( &memory[i] );
    }

    alloc->release(memory, 5 );

    delete []strings;
    delete alloc;
}
