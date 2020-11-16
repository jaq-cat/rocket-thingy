#define WIDTH 1400
#define HEIGHT 1000

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <cstdlib>

#include "rocket.hpp"

using sf::Vector2u;
using sf::Vector2i;
using sf::Vector2f;
using sf::Color;
using sf::Event;
using sf::Keyboard;
using sf::CircleShape;

using std::string;
using std::unordered_map;

int main() {
    // settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    // create window
    sf::RenderWindow win(sf::VideoMode(WIDTH, HEIGHT), "Cat Space Program",
            sf::Style::Titlebar, settings);
    win.setPosition(Vector2i(250, 50));
    //win.setVerticalSyncEnabled(true);
    win.setFramerateLimit(60);
    win.setKeyRepeatEnabled(false);

    // input handler
    unordered_map<char, bool> ih = unordered_map<char, bool>();

    // initialization
    Rocket r = Rocket();

    while (win.isOpen()) {
        // event handling
        Event ev;
        while (win.pollEvent(ev)) {
            switch(ev.type) {
                case Event::Closed:
                    win.close();
                    break;
                case Event::TextEntered:
                    break;
                case Event::KeyPressed:
                    //if (ev.key.code == Keyboard::W)
                        //ih['w'] = true;
                    break;
                case Event::KeyReleased:
                    //if (ev.key.code == Keyboard::W)
                        //ih['w'] = false;
                    break;
                default:
                    break;

            }
        }
        // updating
        // collision
        // rendering
        win.clear(Color(147, 208, 249));
        r.draw(win, sf::RenderStates::Default);
        win.display();
    }
    return EXIT_SUCCESS;
}
