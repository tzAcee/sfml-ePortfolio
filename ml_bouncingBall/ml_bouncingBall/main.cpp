#include "Ball.hpp"
#include "SFML/Graphics.hpp"

int main()
{
	// Create a 500x500 RenderWindow with the title "SFML Portfolio"
	sf::RenderWindow win(sf::VideoMode(500, 500), "SFML Portfolio");

	// Cap the Frames
	win.setFramerateLimit(60);

	// Define a Velocity
	const sf::Vector2f VEL(20, 10);

	// Create a Ball object in the Center of the Window
	Ball ball(win, sf::Vector2f(win.getSize()) / 2.0f, VEL);
	
	// Enter Game Loop while window is open
	while (win.isOpen())
	{
		// Window Event Handling
		sf::Event ev;

		// Poll the Events on the RenderWindow
		while (win.pollEvent(ev))
		{
			// If the Event is a click on closing cross, close the RenderWindow
			if (ev.type == sf::Event::Closed)
			{
				win.close();
			}
		}

		// Clear the window with black color
		win.clear();


		/////
		// DRAWING STUFF GOES IN HERE
		/////
		ball.update();

		// Display all drawn Objects on the RenderWindow
		win.display();

	}

	return 1;
}