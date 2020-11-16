#ifndef ROCKET_HPP
#define ROCKET_HPP
#include <SFML/Graphics.hpp>
class Rocket : public sf::Drawable, public sf::Transformable {
private:
   virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Rocket();
};
#endif
