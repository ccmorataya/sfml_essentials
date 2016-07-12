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
	rectShape.setPosition(sf::Vector2f(50,50));
	rectShape.setRotation(30);
	rectShape.setScale(sf::Vector2f(2,1));

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
