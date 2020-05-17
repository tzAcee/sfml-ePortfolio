#pragma once
#include "SFML/Graphics.hpp"

class Ball
{
private:
	// Pointer to the RenderWindow
	sf::RenderWindow*	_win;
	// Position of the Ball
	sf::Vector2f		_pos;
	// Velocity of the Ball
	sf::Vector2f		_vel;

	// The Circle object which is drawn on the window
	sf::CircleShape		_obj;

	// Bounce checking on the windows corners
	void				check_sides();
	// Init the Circle Object
	void				init_obj(int radius, sf::Color col);
	// Move the Circle Object
	void				move();

public:
	// Default Con / Destructor
	Ball()				{ }
	~Ball()				{ }

	// Our "Main" Constructor
	Ball(sf::RenderWindow& win, sf::Vector2f pos, sf::Vector2f vel);

	// Whole Logic goes in here
	void				update();
};

