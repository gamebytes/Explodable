#ifndef EXPLODABLE_SHAPES
#define EXPLODABLE_SHAPES
	#include <SFML/Graphics.hpp>
	namespace Explodable {
		namespace Shapes {
			class Shape {
				float x, y, size;
				sf::RectangleShape shape;
				public:
					Shape() { x = 0.0f; y = 0.0f; size = 10.0f; }
					Shape(float x, float y, float size);
					virtual sf::Shape& getShape();
			};
			class Square : public Shape {
				float x, y, size;
				sf::RectangleShape shape;
				public:
					Square() : Shape() {}
					Square(float x, float y, float size);
					virtual sf::RectangleShape& getShape();
			};
			class Circle : public Shape {
				float x, y, radius;
				int points;
				sf::CircleShape shape;
				public:
					Circle() : Shape() {}
					Circle(float x, float y, float radius, int points);
					virtual sf::CircleShape& getShape();
			};
		}
	}
#endif