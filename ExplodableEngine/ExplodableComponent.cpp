#include "ExplodableComponent.hpp"
#include "ExplodableEntity.hpp"

namespace Explodable {
	void Component::initComponent(Entity *entityInst) {
		entity = entityInst;
	}
}