#include "HilbertCurve.h"
#include <cmath>

HilbertCurve::HilbertCurve(int level) : level(level) {

    lines = sf::VertexArray(sf::PrimitiveType::LineStrip);

    //This starts us off with no transformation (identity matrix)
    sf::Transform identity;

    HilbertCurve::generateHilbertCurve(level, identity);

    //Scale the actual curve to be visible in the window
    setScale({ 1000.f, 1000.f });

    //Add a 12px margin to be able to properly see the curve
    setPosition({ 12.f, 12.f });

}

void HilbertCurve::draw(sf::RenderTarget& target, sf::RenderStates states) const { 
    states.transform *= getTransform();
    target.draw( lines, states ); 
}


// This function will generate the Hilbert Curve based on the level provided
// The algorithm for generating the Hilbert Curve is recursive starting with
// base level 1 and building up to the desired level.

void HilbertCurve::generateHilbertCurve(int level, const sf::Transform& parentTransform) {
    if (level <1) {
        printf("Level must be greater than 0\n");
        return;
    };

    if (level == 1) {

        //Base case for the recursion
        sf::Vector2f basePoints[4] =
        {
            { 0.f, 0.f },
            { 0.f, 1.f },
            { 1.f, 1.f },
            { 1.f, 0.f }
        };

        for (int i = 0; i < 4; i++) {
            sf::Vector2f transformedPoint = parentTransform.transformPoint(basePoints[i]);
            lines.append(sf::Vertex());
            int index = lines.getVertexCount() - 1;
            lines[index].position = transformedPoint;
            lines[index].color = sf::Color::Black;
            printf("Point %d: (%f, %f)\n", i, transformedPoint.x, transformedPoint.y);
        }

        return;
    }

    //This will be the 4 orientations of the copies of the n-1 level Hilbert Curve
    sf::Transform bottomLeft;
    sf::Transform topLeft;
    sf::Transform topRight;
    sf::Transform bottomRight;

    createTransformations(level, bottomLeft, topLeft, topRight, bottomRight);

    //Recursively generates the 4 copies of the n-1 level Hilbert Curve in the correct orientation and position
    printf("Level %d bottom left:\n", level);
    generateHilbertCurve(level - 1, parentTransform * bottomLeft);
    printf("Level %d top left:\n", level);
    generateHilbertCurve(level - 1, parentTransform * topLeft);
    printf("Level %d top right:\n", level);
    generateHilbertCurve(level - 1, parentTransform * topRight);
    printf("Level %d bottom right:\n", level);
    generateHilbertCurve(level - 1, parentTransform * bottomRight);
}

void HilbertCurve::createTransformations(int level, sf::Transform& bottomLeft, sf::Transform& topLeft, sf::Transform& topRight, sf::Transform& bottomRight) {
    //The scale variable is used to scale the n-1 level to fit the nth level
    //Since the n level has two n-1 levels stacked on top of each other
    //plus an extra line (length 1/(2^n - 1)) in between, we need 
    //to scale the n-1 level down by a factor of (2^(n-1) - 1)/(2^n - 1)

    float scale =(float)(std::pow(2, level - 1) - 1) / (float)(std::pow(2, level) - 1);

    //The half variable finds the middle line in the shape:
    //Ex: n = 2
    //  __    __
    // |  |__|  |
    // |__    __| <-- This is the middle line (2/3 of the way up)
    //  __|  |__

    float half = (float)(std::pow(2, level - 1)) / (float)(std::pow(2, level) - 1);

    //Using the structure of affine transformations given in class:
    //
    //  [ scale    0     translationX ]
    //  [   0    scale   translationY ]
    //  [   0      0         1        ]
    //
    //We can then use this to determine each transformation for every orientation

    //Bottom left (Flip x and y / 90 degree CW rotation) 

    bottomLeft = sf::Transform(
        0.f,     scale,  0.f,
        scale,   0.f,    0.f,
        0.f,     0.f,    1.f
    );

    //Top left (Translate up by half the height)

    topLeft = sf::Transform(
        scale,   0.f,    0.f,
        0.f,     scale,  half,
        0.f,     0.f,    1.f
    );

    //Top right (Translate up by half the height and right by half the width)

    topRight = sf::Transform(
        scale,   0.f,    half,
        0.f,     scale,  half,
        0.f,     0.f,    1.f
    );

    //Bottom right (Opposite of bottom left, translate right by half the width)

    bottomRight = sf::Transform(
        0.f,     -scale,  1.f,
        scale,    0.f,    0.f,
        0.f,      0.f,    1.f
    );
}
