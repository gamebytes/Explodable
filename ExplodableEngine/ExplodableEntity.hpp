/*
	Explodable
	An Engine By Tinfoilboy
	Tinfoilboy © 2014
*/
#ifndef EXPLODABLE_ENTITY
#define EXPLODABLE_ENTITY
	#include <vector>
	#include <SFML/Graphics.hpp>
	namespace Explodable {
		class Entity {
			int x, y, size;
			sf::ConvexShape shape;
			public:
				Entity() {}
				Entity(int x, int y, int size);
				sf::ConvexShape getShape();
		};
	}
#endif