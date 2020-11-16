#ifndef ROCKET_HPP
#define ROCKET_HPP
#include <SFML/Graphics.hpp>
class Rocket : public sf::Drawable, public sf::Transformable {
private:
public:
    Rocket() {}
    ~Rocket() {}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        sf::CircleShape shape(10);
        shape.setFillColor(sf::Color(255, 0, 255));
        target.draw(shape);
    }

};
#endif
