/*
	Explodable
	An Engine By Tinfoilboy
	Tinfoilboy © 2014
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
		class Shapes::Shape;
		class Entity {
			int x, y, size;
			Shapes::Shape* shape;
			map<string, Component*> components;
			public:
				Entity();
				Entity(int x, int y, int size, Shapes::Shape* shape);
				void addComponent(Component* newComponent);
				void removeComponent(string name);
				void dispose();
				void update();
				Component* getComponent(string name);
				sf::Shape& getShape();
				sf::Vector2f& getPosition();
		};
	}
#endif