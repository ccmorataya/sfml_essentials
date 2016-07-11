#include <SFML/Window.hpp>

int main()
{
	sf::Window window (sf::VideoMode(300,200), "title");

	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//update frame
		
		//render frame
	}

	return 0;
}
