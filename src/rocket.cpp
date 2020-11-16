#include "rocket.hpp"

Rocket::Rocket() {

}

void Rocket::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    sf::CircleShape shape(10);
    shape.setFillColor(sf::Color(255, 0, 255));
    target.draw(shape);
}
