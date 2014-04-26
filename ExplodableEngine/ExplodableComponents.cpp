#include "ExplodableComponents.hpp"
#include "ExplodableEntity.hpp"
#include "ExplodableInput.hpp"

namespace Explodable {
	namespace Components {
		// MOVEMENT COMPONENT
		// Allow's entity movement.
		MovementComponent::MovementComponent(Input keys) {
			this->name = name;
			this->keys = keys;
		}
		void MovementComponent::init() {}

		void MovementComponent::update() {
			if (sf::Keyboard::isKeyPressed(keys.getBinding("forward"))) {
				moveInDirection(1, -0.5f);
			}
			if (sf::Keyboard::isKeyPressed(keys.getBinding("backward"))) {
				moveInDirection(1, 0.5f);
			}
			if (sf::Keyboard::isKeyPressed(keys.getBinding("left"))) {
				moveInDirection(0, -0.5f);
			}
			if (sf::Keyboard::isKeyPressed(keys.getBinding("right"))) {
				moveInDirection(0, 0.5f);
			}
		}

		void MovementComponent::dispose() {}

		void MovementComponent::moveInDirection(int direction, float amount) {
			if (direction == 0) {
				entity->getShape().move(amount, 0);
			}
			else {
				entity->getShape().move(0, amount);
			}
		}

		// COLOR COMPONENT
		// Changes an entity's color.
		ColorComponent::ColorComponent() {}
		void ColorComponent::init() {
			color = sf::Color(245, 255, 125, 255);
		}

		void ColorComponent::update() {
	
		}

		void ColorComponent::dispose() {}

		void ColorComponent::setColor(sf::Color color) {
			this->color = color;
			entity->getShape().setFillColor(color);
		}

		sf::Color& ColorComponent::getColor() {
			return color;
		}

		// BUFFERED AUDIO COMPONENT
		// Plays audio from a buffer.
		BufferedAudioComponent::BufferedAudioComponent(string relativeAudioPath) {
			this->name = name;
			if (!buffer.loadFromFile(relativeAudioPath)) {}
			sound.setBuffer(buffer);
		}
		void BufferedAudioComponent::init() {}

		void BufferedAudioComponent::update() {}

		void BufferedAudioComponent::dispose() {
			sound.stop();
		}

		void BufferedAudioComponent::play() {
			sound.play();
		}

		sf::SoundBuffer& BufferedAudioComponent::getBuffer() {
			return buffer;
		}

		sf::Sound& BufferedAudioComponent::getAudio() {
			return sound;
		}

		// STREAMED AUDIO COMPONENT
		// Plays audio from the file specified.
		StreamedAudioComponent::StreamedAudioComponent(string relativeAudioPath) {
			this->name = name;
			if (!audio.openFromFile(relativeAudioPath)) {}
		}
		void StreamedAudioComponent::init() {}

		void StreamedAudioComponent::update() {}

		void StreamedAudioComponent::dispose() {}

		void StreamedAudioComponent::play() {
			audio.play();
		}

		sf::Music& StreamedAudioComponent::getAudio() {
			return audio;
		}

		// LIGHTING COMPONENT
		// Half assed lighting is great
		LightingComponent::LightingComponent(sf::Color color, float radius) {
			this->name = name;
			color.a = 50;
			light = new sf::CircleShape(radius);
			light->setFillColor(color);
		}
		void LightingComponent::init() {
			light->setPosition(entity->getPosition());
		}

		void LightingComponent::update() {}

		void LightingComponent::setColor(sf::Color color) {
			this->color = color;
			light->setFillColor(color);
		}

		void LightingComponent::setPosition(float x, float y) {
			light->setPosition(x, y);
		}

		void LightingComponent::dispose() {
			delete light;
		}

		sf::Color& LightingComponent::getColor() {
			return color;
		}

		sf::CircleShape& LightingComponent::getLight() {
			return *light;
		}
	}
}