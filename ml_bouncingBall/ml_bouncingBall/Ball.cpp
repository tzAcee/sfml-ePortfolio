#include "Ball.hpp"

void Ball::check_sides()
{
	// As soon as the position is less then 1, invert the x Velocity and reset the x Pos to 1
	if (_pos.x <= 0)
	{
		_pos.x = 1;
		_vel.x *= -1;
	}
	// Same for the right Border
	else if (_pos.x >= _win->getSize().x)
	{
		_pos.x = _win->getSize().x - 1;
		_vel.x *= -1;
	}

	// All the Same for the y coordinates
	if (_pos.y <= 0)
	{
		_pos.y = 1;
		_vel.y *= -1;
	}
	else if (_pos.y >= _win->getSize().y)
	{
		_pos.y = _win->getSize().y - 1;
		_vel.y *= -1;
	}
}

void Ball::init_obj(int radius, sf::Color col)
{
	// Init the Position
	_obj.setPosition(_pos);
	// Init the Color
	_obj.setFillColor(col);
	// Init the Radius
	_obj.setRadius(radius);
	// Set the Origin in the Center of the Circle instead on (0,0)
	_obj.setOrigin(radius, radius);
}

void Ball::move()
{
	// Add the Velocity to the pos
	_pos += _vel;

	// Give the _obj the new pos
	_obj.setPosition(_pos);

	// You can just call _obj.move(_vel), but I like to keep track of the pos as a separate Vector instead of _obj.getPosition()
}

Ball::Ball(sf::RenderWindow& win, sf::Vector2f pos, sf::Vector2f vel)
{
	// Default Constructor stuff
	_win = &win;
	_pos = pos;
	_vel = vel;

	// Call the init
	init_obj(5, sf::Color(125, 100, 50));
}

void Ball::update()
{
	// Move and then check the collision
	move();
	check_sides();

	_win->draw(_obj);
}
