#include "HilbertCurve.h";

HilbertCurve::HilbertCurve(level) : vertices(sf::PrimitiveType::Points, )  {
    
}

void HilbertCurve::draw(sf::RenderTarget& target, sf::RenderStates states) const {   
    target.draw( points, getTransform() );    
}