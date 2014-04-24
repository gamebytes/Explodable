#include "ExplodableShapes.hpp"

namespace Explodable {
	namespace Shapes {
		Square::Square(float x, float y, float size) {
			this->x = x;
			this->y = y;
			this->size = size;
			shape = sf::RectangleShape(sf::Vector2f(this->size, this->size));
			shape.setPosition(sf::Vector2f(this->x, this->y));
		}
		Circle::Circle(float x, float y, float radius, int points) {
			this->x = x;
			this->y = y;
			this->radius = radius;
			this->points = points;
			shape = sf::CircleShape(this->radius, this->points);
			shape.setPosition(sf::Vector2f(this->x, this->y));
		}
		sf::RectangleShape& Square::getShape() {
			return shape;
		}
		sf::CircleShape& Circle::getShape() {
			return shape;
		}
		sf::Shape& Shape::getShape() {
			return shape;
		}
	}
}