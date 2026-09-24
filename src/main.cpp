#include <SFML/Graphics.hpp>
#include <iostream>
#include "HilbertCurve.h"

int main()
{
	int level;

	//Gets the desired level of Hilbert Curve
	std::cout << "Enter the Hilbert Curve level you would like to draw: ";
	std::cin >> level;

	HilbertCurve hilbertCurve(level);
	
	sf::RenderWindow window( sf::VideoMode( { 1024, 1024 }, sf::Style::Titlebar | sf::Style::Close), "HW1 - Hilbert-Curve" );

	//SFML starts the coordinate system at top left, so we switch to bottom left
	sf::View view = window.getView();

	//Puts the origin at the bottom-left by setting the center at half our window height/width
	view.setCenter({512.f, 512.f});

	//Flips the Y axis so its pointing upwards and not down
	view.setSize({1024.f, -1024.f});

	window.setView(view);

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->code == sf::Keyboard::Key::Up)
				{
					++level;
					hilbertCurve = HilbertCurve(level);
				}
				else if (keyPressed->code == sf::Keyboard::Key::Down)
				{
					if (level > 1)
					{
						--level;
						hilbertCurve = HilbertCurve(level);
					}
				}
			}

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		//Makes background white so black points display clearly
		window.clear(sf::Color::White); 
		window.draw(hilbertCurve);
		window.display();
	}
}
