#ifndef ROCKET_HPP
#define ROCKET_HPP
#include <SFML/Graphics.hpp>
#include <cmath>

#define SHIP_HEIGHT 100
#define SHIP_WIDTH 40

static const sf::Color SPACE_ORANGE(sf::Color(250, 145, 5));

class Rocket : public sf::Drawable, public sf::Transformable {
private:

public:
    Rocket() {}
    ~Rocket() {}
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        sf::ConvexShape nose(3);
        nose.setPoint(0, sf::Vector2f(SHIP_WIDTH/2.0, 0));
        nose.setPoint(1, sf::Vector2f(0.0, SHIP_WIDTH));
        nose.setPoint(2, sf::Vector2f(SHIP_WIDTH, SHIP_WIDTH));
        sf::RectangleShape fuselage(sf::Vector2f(SHIP_WIDTH, SHIP_HEIGHT));
        fuselage.move(sf::Vector2f(0, SHIP_WIDTH));
        nose.setFillColor(SPACE_ORANGE);
        fuselage.setFillColor(sf::Color(0, 0, 0));
        target.draw(nose);
        target.draw(fuselage);
    }

};
#endif
