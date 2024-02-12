#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");

	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);

	//Player texture loading 
	PlayerTex.loadFromFile("gfx/Goomba.png");

	//Player Texture Initialisation 
	playerSprite.setTexture(&PlayerTex);
	playerSprite.setSize(sf::Vector2f(100, 100));
	playerSprite.setPosition(300, 300);
	
	//Setting Input and Velocity 
	playerSprite.setInput(input);


	//Loading enemy Texture 
	e1Tex.loadFromFile("gfx/enemy.png");
	e2Tex.loadFromFile("gfx/enemy2.png");

	//Initialising Enemy Objects 
	e1.setTexture(&e1Tex);
	e1.setSize(sf::Vector2f(100, 100));
	e1.setPosition(500, 500);

	e2.setTexture(&e2Tex);
	e2.setSize(sf::Vector2f(100, 100));
	e2.setPosition(700, 500);

	move = sf::Vector2f(100, 0);
	move1 = sf::Vector2f(0, 100);

	e1.setWindow(window);
	e2.setWindow(window);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	playerSprite.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{

	e1.update(dt, move);
	e2.update(dt, move1);
	
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(testSprite);
	window->draw(playerSprite);

	window->draw(e1);
	window->draw(e2);
	endDraw();
}
