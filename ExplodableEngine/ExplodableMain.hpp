#ifndef EXPLODABLE_MAIN
#define EXPLODABLE_MAIN
	#include <SFML/System.hpp>
	#include <SFML/Graphics.hpp>
	namespace Explodable {
		class Main {
			// width of window to create, height of window to create, and if vsync is not enabled, a fixed frames per second.
			int width, height, fixedFPS;
			// the title of the window.
			sf::String title;
			// enable or disable vsync, as well as toggle fullscreen.
			bool vsyncEnabled, fullscreen, noBorder, resizable;
			// the window that was created
			sf::RenderWindow window;
			public:
				Main(int width, int height, sf::String title);
				void setTitle(sf::String);
				void setFullscreen(bool fullscreen);
				void setVsync(bool vsync);
				void setFPS(int fps);
				sf::RenderWindow getWindow();
		};
	}
#endif