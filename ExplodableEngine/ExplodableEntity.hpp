/*
	Explodable
	An Engine By Tinfoilboy
	Tinfoilboy © 2014
*/
#ifndef EXPLODABLE_ENTITY
#define EXPLODABLE_ENTITY
	#include "ExplodableComponent.hpp"
	#include <map>
	#include <string>
	#include <SFML/Graphics.hpp>
	using std::vector;
	using std::string;
	using std::map;
	namespace Explodable {
		class Entity {
			int x, y, size;
			sf::CircleShape shape;
			map<string, Component*> components;
			public:
				Entity() {}
				Entity(int x, int y, int size);
				void addComponent(Component* newComponent);
				void removeComponent(string name);
				Component* getComponent(string name);
				sf::CircleShape& getShape();
		};
	}
#endif