// test.cpp
#include "test.h"
#include <gtest/gtest.h>

TEST(EntityConstructorTest, DefaultConstructor)
{
	StevensDev::Entity e = StevensDev::Entity();
	ASSERT_TRUE(e.id() == 0);
	ASSERT_TRUE(e.name().compare("") == 0);
}

TEST(EntityConstructorTest, IDNameConstructor)
{
	StevensDev::Entity e = StevensDev::Entity(42, "Runcible Spoon");
	ASSERT_TRUE(e.id() == 42);
	ASSERT_TRUE(e.name().compare("Runcible Spoon") == 0);
}
