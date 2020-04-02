#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	playerObject.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		//beachBalls.spawn();
		//goombas.spawn();
	}
	playerObject.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	//beachBalls.update(dt);
	//goombas.update(dt);
	playerObject.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	//beachBalls.Render(window);
	//goombas.Render(window);
	window->draw(playerObject);
	playerObject.getBulletManager().Render(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}