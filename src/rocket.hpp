#ifndef ROCKET_HPP
#define ROCKET_HPP
#include <SFML/Graphics.hpp>

#define SHIP_HEIGHT 100
#define SHIP_WIDTH 40

class Rocket : public sf::Drawable, public sf::Transformable {
private:

public:
    Rocket() {}
    ~Rocket() {}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        //sf::CircleShape shape(10);
        sf::CircleShape nose(SHIP_WIDTH, 3);
        sf::RectangleShape fuselage(sf::Vector2f(SHIP_WIDTH, SHIP_HEIGHT));
        nose.setFillColor(sf::Color(0, 0, 0));
        target.draw(nose);
        target.draw(fuselage);
    }

};
#endif
