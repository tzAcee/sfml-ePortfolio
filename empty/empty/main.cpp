#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow win(sf::VideoMode(500, 500), "SFML Portfolio");

	sf::CircleShape circle;
	circle.setRadius(15);
	circle.setFillColor(sf::Color::Cyan);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(sf::Vector2f(win.getSize()) / 2.0f);

	while (win.isOpen())
	{
		sf::Event ev;
		while (win.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				win.close();
			}
		}

		win.clear(sf::Color::White);

		// <<---
		win.draw(circle);

		win.display();
	}

	return 1;
}