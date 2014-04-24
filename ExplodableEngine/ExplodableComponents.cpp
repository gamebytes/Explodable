#include "ExplodableComponents.hpp"
#include "ExplodableEntity.hpp"

namespace Explodable {
	namespace Components {
		// MOVEMENT COMPONENT
		void MovementComponent::init() {
	
		}

		void MovementComponent::update() {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				moveInDirection(1, -0.5f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				moveInDirection(1, 0.5f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				moveInDirection(0, -0.5f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				moveInDirection(0, 0.5f);
			}
		}

		void MovementComponent::moveInDirection(int direction, float amount) {
			if (direction == 0) {
				entity->getShape().getShape().move(amount, 0);
			}
			else {
				entity->getShape().getShape().move(0, amount);
			}
		}

		// COLOR COMPONENT

		void ColorComponent::init() {
			color = sf::Color(245, 255, 125, 255);
		}

		void ColorComponent::update() {
	
		}

		void ColorComponent::setColor(sf::Color color) {
			this->color = color;
			entity->getShape().getShape().setFillColor(color);
		}

		sf::Color& ColorComponent::getColor() {
			return color;
		}
	}
}