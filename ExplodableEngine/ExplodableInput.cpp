#include "ExplodableInput.hpp"

namespace Explodable {
	Input::Input() {
		bindings["forward"] = sf::Keyboard::W;
		bindings["backward"] = sf::Keyboard::S;
		bindings["left"] = sf::Keyboard::A;
		bindings["right"] = sf::Keyboard::D;
	}
	sf::Keyboard::Key Input::getBinding(string bindingName) {
		if (bindings.count(bindingName) != 0) {
			return bindings[bindingName];
			printf("Binding found.");
		}
		else {
			printf("Binding not found");
		}
	}

	void Input::addKeyBinding(string bindingName, sf::Keyboard::Key key) {
		bindings[bindingName] = key;
	}

	map<string, sf::Keyboard::Key>& Input::getBindings() {
		return bindings;
	}
}