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

	sf::Vector2u textureSize = texture.getSize();
	float rectWidth = static_cast<float>(textureSize.x);
	float rectHeight = static_cast<float>(textureSize.y);

	sf::ConvexShape shape(5);
	shape.setPoint(0, sf::Vector2f(0,0));
	shape.setPoint(1, sf::Vector2f(200,0));
	shape.setPoint(2, sf::Vector2f(180,120));
	shape.setPoint(3, sf::Vector2f(100,200));
	shape.setPoint(4, sf::Vector2f(20,120));
	shape.setTexture(&texture);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Blue);
	shape.move(20,20);

	sf::Vector2f startPos = sf::Vector2f(50, 50);
	sf::RectangleShape playerRect(sf::Vector2f(rectWidth, rectHeight));
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
		window.draw(shape);
		//window.draw(triangle);

			//render objects
			window.display();
	}

	return 0;
}

