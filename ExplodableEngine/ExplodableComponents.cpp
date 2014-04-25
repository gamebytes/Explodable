#include "ExplodableComponents.hpp"
#include "ExplodableEntity.hpp"
#include "ExplodableInput.hpp"

namespace Explodable {
	namespace Components {
		// MOVEMENT COMPONENT
		// Allow's entity movement.
		void MovementComponent::init(Input keys) {
			this->keys = keys;
		}

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
		void BufferedAudioComponent::init(string relativeAudioPath) {
			if (!buffer.loadFromFile(relativeAudioPath)) {}
			sound.setBuffer(buffer);
		}

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
		void StreamedAudioComponent::init(string relativeAudioPath) {
			if (!audio.openFromFile(relativeAudioPath)) {}
		}

		void StreamedAudioComponent::update() {}

		void StreamedAudioComponent::dispose() {}

		void StreamedAudioComponent::play() {
			audio.play();
		}

		sf::Music& StreamedAudioComponent::getAudio() {
			return audio;
		}
	}
}