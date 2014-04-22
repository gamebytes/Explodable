/*
	Explodable
	An Engine By Tinfoilboy
	Tinfoilboy © 2014
*/
#include "ExplodableMain.hpp"

#include <SFML/System.hpp>

#include <SFML/Graphics.hpp>

namespace Explodable {

	Main::Main(int width, int height, sf::String title) {
		this->width = width;
		this->height = height;
		window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	}

	void Main::setTitle(sf::String title) {
		this->title = title;
		window->setTitle(title);
	}

	void Main::setFullscreen(bool fullscreen) {
		if (!this->fullscreen && fullscreen) {
			window->create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
		}
		else if (this->fullscreen && !fullscreen) {
			window->create(sf::VideoMode(width, height), title);
		}
		this->fullscreen = fullscreen;
	}


	void Main::setVsync(bool vsync) {
		vsyncEnabled = vsync;
		window->setVerticalSyncEnabled(vsyncEnabled);
	}

	void Main::setFPS(int fps) {
		fixedFPS = fps;
		if (!vsyncEnabled) {
			window->setFramerateLimit(fixedFPS);
		}
		else {
			printf("VSync is enabled, so therefor, the frames per second is already fixed.");
		}
	}

	void Main::dispose() {
		delete window;
	}

	sf::RenderWindow* Main::getWindow() {
		return window;
	}
}