/*
	Explodable
	An Engine By Tinfoilboy
	Tinfoilboy © 2014
*/

#include "ExplodableEntity.hpp"

#include <SFML/System.hpp>

#include <SFML/Graphics.hpp>

namespace Explodable {
	Entity::Entity(int x, int y, int size) {
	   this->x = x;
	   this->y = y;
	   this->size = size;
	   this->shape = sf::ConvexShape();
	   shape.setPointCount(4);
	   shape.setPoint(0, sf::Vector2f(-this->size, -this->size));
	   shape.setPoint(1, sf::Vector2f(this->size, 0));
	   shape.setPoint(2, sf::Vector2f(this->size, this->size));
	   shape.setPoint(3, sf::Vector2f(0, 0));
	   shape.setPosition(sf::Vector2f(x, y));
	}
	sf::ConvexShape Entity::getShape() {
		return shape;
	}
}