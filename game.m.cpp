#include "src/entity.h"
#include <iostream>

int main()
{
	StevensDev::Entity e = StevensDev::Entity(42, "Runcible Spoon");

	std::cout << "entity: " << e << std::endl;

	return 0;
}
