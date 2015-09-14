// dynamic_array_test.cpp
#include <dynamic_array.h>
#include "test.h"

TEST(DynamicArrayConstructorTests, DefaultConstructor)
{
    using namespace StevensDev;

    sgdc::DynamicArray<int> *array;
    array = new sgdc::DynamicArray<int>;

    ASSERT_TRUE( array != 0 );
    ASSERT_TRUE( array->getLength() == 0 );
    ASSERT_TRUE( array->getMaxSize() == 16 );
}

TEST(DynamicArrayConstructorTests, InitialSizeConstructor)
{
    using namespace StevensDev;

    sgdc::DynamicArray<int> *array;
    array = new sgdc::DynamicArray<int>( 64 );

    ASSERT_TRUE( array != 0 );
    ASSERT_TRUE( array->getLength() == 0 );
    ASSERT_TRUE( array->getMaxSize() == 64 );
}

TEST(DynamicArrayPushTests, PushTest)
{
    using namespace StevensDev;

    sgdc::DynamicArray<int> *array = new sgdc::DynamicArray<int>( 8 );

    array->push( 42 );
    array->push( 128 );
    array->push( 21 );

    ASSERT_TRUE( array != 0 );
    ASSERT_TRUE( array->getLength() == 3 );
    ASSERT_TRUE( array->getMaxSize() == 8 );
}
