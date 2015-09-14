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
