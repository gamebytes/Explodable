/*
	Explodable
	An Engine By Tinfoilboy
	Tinfoilboy © 2014
*/

#include "ExplodableEntity.hpp"

#include "ExplodableComponent.hpp"

#include <SFML/System.hpp>

#include <SFML/Graphics.hpp>

namespace Explodable {
	Entity::Entity(int x, int y, int size) {
	   this->x = x;
	   this->y = y;
	   this->size = size;
	   this->shape = sf::CircleShape(80, 8);
	   shape.setPosition(sf::Vector2f((float)x, (float)y));
	}
	void Entity::addComponent(Component* component) {
		component->initComponent(this);
		components[component->name] = component;
	}
	void Entity::removeComponent(string name) {
		if (components.count(name) != 0) {
			delete components[name];
			components.erase(name);
			printf("Component removed.");
		}
		else {
			printf("Component not found.");
		}
	}
	Component* Entity::getComponent(string name) {
		if (components.count(name) != 0) {
			return components[name];
			printf("Component found.");
		}
		else {
			printf("Component not found.");
		}
	}
	sf::CircleShape& Entity::getShape() {
		return shape;
	}
}