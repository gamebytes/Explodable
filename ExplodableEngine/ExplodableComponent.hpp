/*
	Explodable
	An Engine By Tinfoilboy
	Tinfoilboy © 2014
*/

#ifndef EXPLODABLE_COMPONENT
#define EXPLODABLE_COMPONENT
	#include <string>
	#include <map>
	using std::string;
	using std::map;
	namespace Explodable {
		class Entity;
		class Component {
			public:
				Entity* entity;
				string name;
				Component() { name = "NO NAMED COMPONENT."; }
				Component(string name) { this->name = name; }
				// Used to initialize the actual component (i.e. set values.)
				virtual void init() {}
				virtual void update() {}
				virtual void dispose() {}
				// Used to initialize the internals of the component
				void initComponent(Entity *entityInst);
		};
	}
#endif