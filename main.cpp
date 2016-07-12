#include <SFML/Window.hpp>

int main()
{
	sf::Window window (sf::VideoMode(300,200), "title");
	sf::String buffer;

	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Space)
					{
						window.setTitle("Space");
					}
					break;
				case sf::Event::TextEntered:
					buffer += event.text.unicode;
					break;
				case sf::Event::KeyReleased:
					if (event.key.code == sf::Keyboard::Return) {
						window.setTitle(buffer);
						buffer.clear();
					}
					break;
				default:
					break;
			}
		}

		//update frame
		
		//render frame
	}

	return 0;
}
