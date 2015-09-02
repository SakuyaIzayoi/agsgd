// entity.h
#ifndef INCLUDED_ENTITY
#define INCLUDED_ENTITY

#include <iostream>
#include <string>

namespace StevensDev
{

class Entity {
	private:
		int d_id;
		std::string d_name;

	public:
		// CONSTRUCTORS
		Entity();
			// Default constructor.
		Entity(int id, std::string name);
			// Constructor with Entity ID and name.

		// ACCESSORS
		int id() const;
			// Get Entity ID.
		std::string name() const;
			// Get Entity Name.
		
		// MUTATORS
		void setID(int id);
			// Set Entity ID.
		void setName(std::string name);
			// Set Entity Name.
};

// FREE OPERATORS
inline
std::ostream& operator<<( std::ostream& stream, const Entity& entity )
{
	return stream << "{ id: " << entity.id() << ", name: " << entity.name() << " }";
}

// CONSTRUCTORS
inline
Entity::Entity() : d_id( 0 ), d_name( "" )
{
}

inline
Entity::Entity(int id, std::string name) :
	d_id( id ),
	d_name( name )
{
}

// ACCESSORS

inline
int Entity::id() const
{
	return d_id;
}

inline
std::string Entity::name() const
{
	return d_name;
}

// MUTATORS

inline
void Entity::setID(int id)
{
	d_id = id;
}

inline
void Entity::setName(std::string name)
{
	d_name = name;
}

} // End namespace StevensDev.

#endif
