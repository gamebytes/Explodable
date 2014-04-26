/*
	Explodable
	An Engine By Tinfoilboy
	Tinfoilboy � 2014
*/
#ifndef EXPLODABLE_ENTITY
#define EXPLODABLE_ENTITY
	#include "ExplodableComponent.hpp"
	#include "ExplodableShapes.hpp"
	#include <map>
	#include <string>
	#include <SFML/Graphics.hpp>
	using std::vector;
	using std::string;
	using std::map;
	namespace Explodable {
		namespace Shapes {
			class Shape;
		}
		class Entity {
			// The x and y position of the entity, as well as the size.
			int x, y, size;
			// Is this an invisible entity?
			bool invisible;
			// The entity's shape reference
			Shapes::Shape* shape;
			// The components for this entity.
			map<string, Component*> components;
			public:
				// Default Constructor.
				Entity();
				// Define the initials for this entity.
				Entity(int x, int y, int size, Shapes::Shape* shape);
				// Define an invisiable entity.
				Entity(int x, int y);
				// Add a component to this entity.
				void addComponent(string name, Component* newComponent);
				// Remove a component from this entity.
				void removeComponent(string name);
				// Does this entity have a certain component?
				bool hasComponent(string name);
				// Dispose of this entity.
				void dispose();
				// Update this entity.
				void update();
				// Get a component from this entity.
				Component* getComponent(string name);
				// Get this entity's shape reference.
				sf::Shape& getShape();
                // Get the position of this entity.
				sf::Vector2f getPosition();
		};
	}
#endif