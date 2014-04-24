#ifndef EXPLODABLE_COMPONENTS
#define EXPLODABLE_COMPONENTS
	#include "ExplodableComponent.hpp"
	#include <SFML/Graphics.hpp>
	namespace Explodable {
		// Explodable should have core components, that is what this namespace will contain. If you would like to add a core component, go right ahead.
		class Component;
		namespace Components {
			class MovementComponent : public Component {
				public:
					Explodable::Component* clone() { return new Explodable::Component(*this); }
					MovementComponent(string name) : Component(name) {}
					MovementComponent(const MovementComponent&);
					virtual void init();
					virtual void update();
					void moveInDirection(int direction, float amount);
			};
			class ColorComponent : public Explodable::Component {
				sf::Color color;
				public:
					Explodable::Component* clone() { return new Explodable::Component(*this); }
					ColorComponent(string name) : Component(name) {}
					ColorComponent(const ColorComponent&);
					virtual void init();
					virtual void update();
					void setColor(sf::Color color);
					sf::Color& getColor();
			};
		}
	}
#endif