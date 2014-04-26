#ifndef EXPLODABLE_COMPONENTS
#define EXPLODABLE_COMPONENTS
	#include "ExplodableComponent.hpp"
	#include "ExplodableInput.hpp"
	#include <SFML/Graphics.hpp>
	#include <SFML/Audio.hpp>
	namespace Explodable {
		// Explodable should have core components, that is what this space will contain. If you would like to add a core component, go right ahead.
		class Component;
		class Input;
		namespace Components {
			class MovementComponent : public Explodable::Component {
				Input keys;
				public:
					Explodable::Component* clone() { return new Explodable::Component(*this); }
					MovementComponent(Input keys);
					MovementComponent(const MovementComponent&);
					virtual void init();
					virtual void update();
					virtual void dispose();
					void moveInDirection(int direction, float amount);
			};
			class ColorComponent : public Explodable::Component {
				sf::Color color;
				public:
					Explodable::Component* clone() { return new Explodable::Component(*this); }
					ColorComponent();
					ColorComponent(const ColorComponent&);
					virtual void init();
					virtual void update();
					virtual void dispose();
					void setColor(sf::Color color);
					sf::Color& getColor();
			};
			class BufferedAudioComponent : public Explodable::Component {
				sf::SoundBuffer buffer;
				sf::Sound sound;
				public:
					Explodable::Component* clone() { return new Explodable::Component(*this); }
					BufferedAudioComponent(string relativeAudioPath);
					BufferedAudioComponent(const MovementComponent&);
					virtual void init();
					virtual void update();
					virtual void dispose();
					void play();
					sf::SoundBuffer& getBuffer();
					sf::Sound& getAudio();
			};
			class StreamedAudioComponent : public Explodable::Component {
				sf::Music audio;
				public:
					Explodable::Component* clone() { return new Explodable::Component(*this); }
					StreamedAudioComponent(string relativeAudioPath);
					StreamedAudioComponent(const MovementComponent&);
					virtual void init();
					virtual void update();
					virtual void dispose();
					void play();
					sf::Music& getAudio();
			};
			class LightingComponent : public Explodable::Component {
				sf::CircleShape* light;
				sf::Color color;
				public:
					Explodable::Component* clone() { return new Explodable::Component(*this); }
					LightingComponent(sf::Color lightColor, float lightRadius);
					LightingComponent(const LightingComponent&);
					virtual void init();
					virtual void update();
					virtual void dispose();
					void setColor(sf::Color color);
					void setPosition(float x, float y);
					sf::Color& getColor();
					sf::CircleShape& getLight();
			};
		}
	}
#endif