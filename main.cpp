#include <SFML/Graphics.hpp>

class Game
{
	public:
				Game();
		void	run();
		void	handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	private:
		void	processEvents();
		void	update();
		void	render();
		sf::RenderWindow mWindow;
		sf::CircleShape mPlayer;
		bool	mIsMovingUp;
		bool	mIsMovingDown;
		bool	mIsMovingRight;
		bool	mIsMovingLeft;
};

Game::Game()
	:mWindow(sf::VideoMode(640, 480), "SFML modularization"), mPlayer()
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Red);
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
		switch (event.type) {
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
		}
		if (event.type == sf::Event::Closed) {
			mWindow.close();
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W) {
		mIsMovingUp = isPressed;
	}
	else if (key == sf::Keyboard::S) {
		mIsMovingDown = isPressed;
	}
	else if (key == sf::Keyboard::A) {
		mIsMovingLeft = isPressed;
	}
	else if (key == sf::Keyboard::D) {
		mIsMovingRight = isPressed;
	}
}

void Game::update()
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp) {
		movement.y -= 1.f;
	}
	if (mIsMovingDown) {
		movement.y += 1.f;
	}
	if (mIsMovingRight)	{
		movement.x += 1.f;
	}
	if (mIsMovingLeft){
		movement.x -+ 1.f;
	}

	mPlayer.move(movement);
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

int main()
{
	Game game;
	game.run();
}
