#ifndef EXPLODABLE_INPUT
#define EXPLODABLE_INPUT
	#include <map>
	#include <string>
	#include <SFML/Window.hpp>
	using std::map;
	using std::string;
	namespace Explodable {
		class Input {
			map<string, sf::Keyboard::Key> bindings;
			public:
				Input();
				void addKeyBinding(string bindingName, sf::Keyboard::Key key);
				sf::Keyboard::Key getBinding(string bindingName);
				map<string, sf::Keyboard::Key>& getBindings();
		};
	}
#endif