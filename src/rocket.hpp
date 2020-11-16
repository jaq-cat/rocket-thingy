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
        //sf::CircleShape shape(10);
        sf::CircleShape nose(SHIP_WIDTH, 3);
        sf::RectangleShape fuselage(sf::Vector2f(SHIP_WIDTH, SHIP_HEIGHT));
        fuselage.move(sf::Vector2f(0, (SHIP_WIDTH/2.0) * pow(3.0, 0.5)));
        nose.setFillColor(SPACE_ORANGE);
        fuselage.setFillColor(SPACE_ORANGE);
        target.draw(nose);
        target.draw(fuselage);
    }

};
#endif
