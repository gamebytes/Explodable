/*
	Explodable
	An Engine By Tinfoilboy
	Tinfoilboy © 2014
*/

#include "ExplodableEntity.hpp"

#include "ExplodableComponent.hpp"

#include "ExplodableShapes.hpp"

#include <SFML/System.hpp>

#include <SFML/Graphics.hpp>

#include <map>

using std::map;

namespace Explodable {
	Entity::Entity(int x, int y, int size, Shapes::Shape* shape) {
	   this->x = x;
	   this->y = y;
	   this->size = size;
	   this->shape = shape;
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
	void Entity::update() {
		for (map<string, Component*>::iterator i = components.begin(); i != components.end(); ++i) {
			i->second->update();
		}
	}
	void Entity::dispose() {
		for (map<string, Component*>::iterator i = components.begin(); i != components.end(); ++i) {
			delete i->second;
		}
		components.clear();
	}
	Shapes::Shape& Entity::getShape() {
		return *shape;
	}
}