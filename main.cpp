#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window (sf::VideoMode(300,200), "title");
	sf::String buffer;

	sf::CircleShape circleShape(50);
	circleShape.setFillColor(sf::Color::Blue);
	circleShape.setOutlineColor(sf::Color::Black);
	circleShape.setOutlineThickness(3);

	sf::RectangleShape rectShape(sf::Vector2f(50,50));
	rectShape.setFillColor(sf::Color::Red);

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
		
		//render cycle
		window.clear(sf::Color::White);

		window.draw(circleShape);
		window.draw(rectShape);

			//render objects
			window.display();
	}

	return 0;
}
