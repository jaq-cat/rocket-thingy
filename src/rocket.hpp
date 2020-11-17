#ifndef ROCKET_HPP
#define ROCKET_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "math.hpp"

#define SHIP_HEIGHT 100
#define SHIP_WIDTH 40

static const sf::Color NOSE(sf::Color(250, 145, 5));
static const sf::Color FUSELAGE(sf::Color(250, 145, 5));
static const sf::Color ENGINE(sf::Color(0, 0, 0));

class Rocket : public sf::Drawable, public sf::Transformable {
private:
    double xspd;
    double yspd;
    double r;
    sf::ConvexShape nose;
    sf::RectangleShape fuselage;
    sf::ConvexShape eTop;
    sf::ConvexShape eBottom;

public:
    Rocket() :
    nose(sf::ConvexShape(3)),
    fuselage(sf::RectangleShape(sf::Vector2f(SHIP_WIDTH, SHIP_HEIGHT))),
    eTop(sf::ConvexShape(3)),
    eBottom(sf::ConvexShape(3)) {
        r = -90.0;
        // nose
        nose.setPoint(0, sf::Vector2f(SHIP_WIDTH/2.0, 0));
        nose.setPoint(1, sf::Vector2f(0.0, SHIP_WIDTH));
        nose.setPoint(2, sf::Vector2f(SHIP_WIDTH, SHIP_WIDTH));
        nose.setFillColor(NOSE);
        // fuselage
        fuselage.move(sf::Vector2f(0, SHIP_WIDTH));
        fuselage.setFillColor(FUSELAGE);
        // engine top
        eTop.setPoint(0, sf::Vector2f(0.0, 0.0));
        eTop.setPoint(1, sf::Vector2f(SHIP_WIDTH, 0.0));
        eTop.setPoint(2, sf::Vector2f(SHIP_WIDTH/2.0, SHIP_WIDTH));
        eTop.move(sf::Vector2f(0, SHIP_WIDTH+SHIP_HEIGHT));
        eTop.setFillColor(ENGINE);
        // engine bottom
        eBottom.setPoint(0, sf::Vector2f(SHIP_WIDTH/2.0, 0));
        eBottom.setPoint(1, sf::Vector2f(0.0, SHIP_WIDTH));
        eBottom.setPoint(2, sf::Vector2f(SHIP_WIDTH, SHIP_WIDTH));
        eBottom.setFillColor(sf::Color(0, 0, 0));
        eBottom.move(sf::Vector2f(0, SHIP_WIDTH+SHIP_HEIGHT));
        eBottom.setFillColor(ENGINE);

        setOrigin(SHIP_WIDTH/2.0, SHIP_HEIGHT);
        double ox = getOrigin().x;
        double oy = getOrigin().y;
        nose.setOrigin(ox, oy);
        fuselage.setOrigin(ox, oy);
        eTop.setOrigin(ox, oy);
        eBottom.setOrigin(ox, oy);
    }
    ~Rocket() {}

    void rotate_ship(double r) {
        rotate(r);
        this->r += r;
        //std::cout << r << std::endl;
        //std::cout << this->getRotation() << std::endl;
    }

    void accelerate(double acc) {
        xspd += rX(acc, this->r);
        yspd += rY(acc, this->r);
    }

    void tick(bool grav) {
        move(sf::Vector2f(xspd, yspd));
        if (grav) yspd += 0.1f;
        else if (yspd > 0.00) yspd = 0.0;
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(nose, states);
        target.draw(fuselage, states);
        target.draw(eTop, states);
        target.draw(eBottom, states);
    }

};
#endif
