#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window (sf::VideoMode(300,200), "title");
	window.setFramerateLimit(60);
	sf::String buffer;

	sf::CircleShape circleShape(50);
	circleShape.setFillColor(sf::Color::Blue);
	circleShape.setOutlineColor(sf::Color::Black);
	circleShape.setOutlineThickness(3);

	sf::RectangleShape rectShape(sf::Vector2f(50,50));
	rectShape.setFillColor(sf::Color::Red);
	rectShape.setOrigin(sf::Vector2f(25, 25));
	rectShape.setPosition(sf::Vector2f(50,50));

	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(100,0));
	triangle.setPoint(1, sf::Vector2f(100,100));
	triangle.setPoint(2, sf::Vector2f(0,100));
	triangle.setFillColor(sf::Color::Green);

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
		rectShape.rotate(1.5f);
		rectShape.move(sf::Vector2f(1, 0));
		
		//render cycle
		window.clear(sf::Color::White);

		//window.draw(circleShape);
		window.draw(rectShape);
		//window.draw(triangle);

			//render objects
			window.display();
	}

	return 0;
}
