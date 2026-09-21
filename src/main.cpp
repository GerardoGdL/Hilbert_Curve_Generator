#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main()
{
	int level;

	//Gets the desired level of Hilbert Curve
	std::cout << "Enter the Hilbert Curve level you would like to draw: ";
	std::cin >> level;

	//Calculates the total number of points
	int gridSize = (int)std::pow(2, 2 * level);

	//Calculates the width of the grid
	int gridWidth = (int)std::sqrt(gridSize);

	//printf("The grid is %dx%d\n", gridWidth, gridWidth); //This is for testing
	

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
		window.display();
	}
}
