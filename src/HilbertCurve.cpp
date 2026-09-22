#include "HilbertCurve.h"
#include <cmath>

HilbertCurve::HilbertCurve(int level) : level(level) {
    //Total amount of points in the grid
    int total_points = (int)std::pow(2, 2 * level);

    //Calculates the width of the grid
    int gridWidth = (int)std::pow(2, level);

    this->points = sf::VertexArray(sf::PrimitiveType::Points, total_points);

    //This is for testing
    printf("The grid is %dx%d\n", (int)std::sqrt(total_points), (int)std::sqrt(total_points));

    //This populates the vertex array with the points for the grid
    for (int y = 0; y < gridWidth; y++)
    {
        for (int x = 0; x < gridWidth; x++)
        {
            //This will draw the grid from bottom left to top right
            int index = y * gridWidth + x;

            points[index].position = sf::Vector2f(x, y);
            points[index].color = sf::Color::Black;
        }
    }

}

void HilbertCurve::draw(sf::RenderTarget& target, sf::RenderStates states) const {   
    target.draw( points, getTransform() );    
}