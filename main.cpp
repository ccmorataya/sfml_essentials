#include <SFML/Graphics.hpp>

class Game
{
	public:
				Game();
		void	run();

	private:
		void	processEvents();
		void	update();
		void	render();
		sf::RenderWindow mWindow;
		sf::CircleShape mPlayer;
		sf::CircleShape mSqare;
};

Game::Game()
	:mWindow(sf::VideoMode(640, 480), "SFML modularization"), mPlayer(), mSqare()
{
	mSqare.setRadius(40.f);
	mSqare.setPosition(100.f, 100.f);
	mSqare.setFillColor(sf::Color::Red);
}

void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent (event))
	{
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
	}
}
void Game::update(){}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mSqare);
	mWindow.display();
}

int main()
{
	Game game;
	game.run();
}
