#include <SFML/Graphics.hpp>
#include <vector>

class HilbertCurve : public sf::Drawable, public sf::Transformable {
private:
    // Vertex array that contains all the individual points for the grid)
    sf::VertexArray points;

    //Override of the draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    //Default constructor
    HilbertCurve(level); //Default must have a level (base = 1)
}