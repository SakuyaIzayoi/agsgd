// dynamic_array_test.cpp
#include <dynamic_array.h>
#include "test.h"
#include <stdexcept>

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

TEST(DynamicArrayGetterTests, AtThrowsTest)
{
    using namespace StevensDev;

    sgdc::DynamicArray<int> *array = new sgdc::DynamicArray<int>( 8 );

    ASSERT_THROW(array->at( 12345 );, std::out_of_range);
}

TEST(DynamicArrayGetterTests, AtTest)
{
    using namespace StevensDev;

    sgdc::DynamicArray<int> *array = new sgdc::DynamicArray<int>( 8 );

    array->push( 42 );
    array->push( 17 );

    ASSERT_TRUE( array->at( 1 ) == 42);
    ASSERT_TRUE( array->at( 2 ) == 17);
}

TEST(DynamicArrayPushTests, OverflowReallocTest)
{
    using namespace StevensDev;

    sgdc::DynamicArray<int> *array = new sgdc::DynamicArray<int>( 2 );

    ASSERT_TRUE( array->getMaxSize() == 2 );

    array->push( 42 );
    array->push( 17 );
    array->push( 128 ); // Overflow possible space

    ASSERT_TRUE( array->getMaxSize() > 2 );
}

TEST(DynamicArrayPopTests, PopFrontTest)
{
    using namespace StevensDev;

    sgdc::DynamicArray<int> *array = new sgdc::DynamicArray<int>( 4 );
    int ret = 0;

    array->push( 42 );
    array->push( 17 );
    array->push( 128 );

    ret = array->popFront();

    ASSERT_TRUE( array->getLength() == 2 );
    ASSERT_TRUE( ret == 42 );
}

TEST(DynamicArrayPushTests, PushFrontTest)
{
    using namespace StevensDev;

    sgdc::DynamicArray<int> *array = new sgdc::DynamicArray<int>( 4 );

    array->push( 42 );
    array->push( 17 );
    array->push( 128 );

    array->pushFront( 2 );
    ASSERT_TRUE( array->at( 1 ) == 2);

    array->pushFront( 256 );
    ASSERT_TRUE( array->at( 1 ) == 256 );

    array->pushFront( 1024 );
    ASSERT_TRUE( array->at( 1 ) == 1024 );
}
