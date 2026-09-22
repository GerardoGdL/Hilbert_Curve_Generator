#include <SFML/Graphics.hpp>
#include <vector>

class HilbertCurve : public sf::Drawable, public sf::Transformable {
private:
    // Vertex array that contains all the individual points for the grid
    sf::VertexArray points;
    //This will be to store the level desired
    int level;

    //Override of the draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    //Default constructor (must have a level)
    HilbertCurve(int level);
};