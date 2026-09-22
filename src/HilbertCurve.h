#include <SFML/Graphics.hpp>
#include <vector>

class HilbertCurve : public sf::Drawable, public sf::Transformable {
private:
    //Vertex array that contains all the individual points for the grid
    sf::VertexArray points;

    //This will be to store the level desired
    int level;

    //This will store the lines in the grid that will be drawn
    sf::VertexArray lines;

    //Override of the draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void generateHilbertCurve(int level,int grid_width, float spacing, float margin);

public:
    //Default constructor (must have a level)
    HilbertCurve(int level);
};