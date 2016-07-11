#include <SFML/Window.hpp>

int main()
{
	sf::Window window (sf::VideoMode(300,200), "title");
	sf::sleep(sf::seconds(3));
	return 0;
}
