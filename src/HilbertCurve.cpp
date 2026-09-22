#include "HilbertCurve.h"
#include <cmath>

HilbertCurve::HilbertCurve(int level) : level(level) {
    //Total amount of points in the grid
    int total_points = (int)std::pow(2, 2 * level);

    //Calculates the width of the grid
    int grid_width = (int)std::pow(2, level);

    /*
    Since we need the points to take up most of the space in the window
    this will calculate the spacing required between points to fit within
    a 1000x1000 area to allow for a small 12px margin to see the full pattern
    */

    float drawing_size = 1000.f;
    float margin = 12.f;

    /*
    There are n-1 spaces between n points, so dividing the grid size we want
    by n-1 will give us the spacing required to fit the points in the area
    */

    float spacing = drawing_size / (grid_width - 1);


    this->points = sf::VertexArray(sf::PrimitiveType::Points, total_points);

    //This is for testing
    printf("The grid is %dx%d\n", (int)std::sqrt(total_points), (int)std::sqrt(total_points));

    //This populates the vertex array with the points for the grid
    for (int y = 0; y < grid_width; y++)
    {
        for (int x = 0; x < grid_width; x++)
        {
            //This will draw the grid from bottom left to top right
            int index = y * grid_width + x;

            points[index].position = sf::Vector2f(x * spacing + margin, y * spacing + margin);
            points[index].color = sf::Color::Black;
        }
    }

    HilbertCurve::generateHilbertCurve(level, grid_width, spacing, margin);

}

void HilbertCurve::draw(sf::RenderTarget& target, sf::RenderStates states) const {   
    target.draw( points, getTransform() );  
    target.draw( lines, getTransform() ); 
}

/*
    This function will generate the Hilbert Curve based on the level provided
    The algorithm for generating the Hilbert Curve is recursive starting with
    base level 1 and building up to the desired level.
*/
void HilbertCurve::generateHilbertCurve(int level, int grid_width, float spacing, float margin) {
    if (level <1) {
        printf("Level must be greater than 0\n");
        return;
    };

    this->lines = sf::VertexArray(sf::PrimitiveType::LineStrip, (int)std::pow(2, 2 * level));

    if (level == 1) {
        lines[0].position = sf::Vector2f(0 * spacing + margin, 0 * spacing + margin);
        lines[1].position = sf::Vector2f(0 * spacing + margin, 1 * spacing + margin);
        lines[2].position = sf::Vector2f(1 * spacing + margin, 1 * spacing + margin);
        lines[3].position = sf::Vector2f(1 * spacing + margin, 0 * spacing + margin);

        lines[0].color = sf::Color::Red;
        lines[1].color = sf::Color::Red;
        lines[2].color = sf::Color::Red;
        lines[3].color = sf::Color::Red;
    };
}