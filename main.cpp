#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window (sf::VideoMode(300,200), "title");
	sf::String buffer;

	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//update frame
		
		//render cicle
		window.clear(sf::Color::White);

		//render objects
		window.display();
	}

	return 0;
}
