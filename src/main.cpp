#include <SFML/Graphics.hpp>
#include <iostream>
#include "HilbertCurve.h"

int main()
{
	int level;

	//Gets the desired level of Hilbert Curve
	std::cout << "Enter the Hilbert Curve level you would like to draw: ";
	std::cin >> level;

	//Call the constructor for the Hilbert Curve class with the desired level
	HilbertCurve hilbertCurve(level);
	

	sf::RenderWindow window( sf::VideoMode( { 1024, 1024 } ), "HW1 - Hilbert-Curve" );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		//Makes background white so black points display clearly
		window.clear(sf::Color::White); 
		window.draw(hilbertCurve);
		window.display();
	}
}
