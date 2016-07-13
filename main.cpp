#include <SFML/Graphics.hpp>

void initShape(sf::RectangleShape& shape, sf::Vector2f const& position, sf::Color const& color)
{
	shape.setFillColor(color);
	shape.setPosition(position);
	shape.setOrigin(shape.getSize() * 0.5f);	//the center of the shape
}

int main()
{
	sf::RenderWindow window (sf::VideoMode(480, 180), "Squares");
	window.setFramerateLimit(60);

	sf::Texture texture;
	texture.loadFromFile("texture.png");

	sf::Vector2f startPos = sf::Vector2f(50, 50);
	sf::RectangleShape playerRect(sf::Vector2f(50, 50));
	//initShape(playerRect, startPos, sf::Color::Green);
	playerRect.setTexture(&texture);

	sf::RectangleShape targetRect(sf::Vector2f(50, 50));
	initShape(targetRect, sf::Vector2f(400,50), sf::Color::Blue);

	sf::RectangleShape badRect(sf::Vector2f(50, 100));
	initShape(badRect, sf::Vector2f(250, 50), sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			//if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right) {
			//	moving = true;
			//}
			//if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right) {
			//	moving = false;
			//}
		}

		//update frame
		playerRect.move(1,0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			playerRect.move(0,1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			playerRect.move(0,-1);
		}

		if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds())) {
			window.close();
		}

		if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds())) {
			playerRect.setPosition(startPos);
		}
		//render cycle
		window.clear(sf::Color::White);

		//window.draw(circleShape);
		window.draw(playerRect);
		window.draw(badRect);
		window.draw(targetRect);
		//window.draw(triangle);

			//render objects
			window.display();
	}

	return 0;
}

