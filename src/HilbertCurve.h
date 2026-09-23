#include <SFML/Graphics.hpp>
#include <vector>

class HilbertCurve : public sf::Drawable, public sf::Transformable {
private:
    //This will be to store the level desired
    int level;

    //This will store the lines in the grid that will be drawn
    sf::VertexArray lines;

    //Override of the draw function
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void generateHilbertCurve(int level, const sf::Transform& parentTransform);

    void createTransformations(int level,sf::Transform& bottomLeft,sf::Transform& topLeft,sf::Transform& topRight,sf::Transform& bottomRight);

public:
    //Default constructor (must have a level)
    HilbertCurve(int level);
};