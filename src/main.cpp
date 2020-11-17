#define WIDTH 1500
#define HEIGHT 900

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
using sf::View;

using std::string;
using std::cout;
using std::endl;
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
    View cam = View(sf::Vector2f(WIDTH/2.0, HEIGHT/2.0), sf::Vector2f(WIDTH, HEIGHT));
    win.setView(cam);
    Rocket r = Rocket();
    r.move(WIDTH/2.0, HEIGHT + SHIP_HEIGHT/6.0);
    sf::RectangleShape ground = sf::RectangleShape(Vector2f(WIDTH*200, 500));
    ground.setPosition(Vector2f(0.0, HEIGHT));
    ground.setFillColor(Color(0, 255, 0));
    double acc = 0.001;

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
                    if (ev.key.code == Keyboard::W)
                        ih['w'] = true;
                    if (ev.key.code == Keyboard::A)
                        ih['a'] = true;
                    if (ev.key.code == Keyboard::D)
                        ih['d'] = true;
                    break;
                case Event::KeyReleased:
                    if (ev.key.code == Keyboard::W)
                        ih['w'] = false;
                    if (ev.key.code == Keyboard::A)
                        ih['a'] = false;
                    if (ev.key.code == Keyboard::D)
                        ih['d'] = false;
                    break;
                default:
                    break;

            }
        }
        if (ih.count('w')>0 && ih['w']) {
            acc += 0.0005f;
            r.accelerate(acc);
        } else {
            acc = 0.001f;
        }
        if (ih.count('d')>0 && ih['d']) {
            r.rotate_ship(0.5f);
        }
        if (ih.count('a')>0 && ih['a']) {
            r.rotate_ship(-0.5f);
        }
        // updating
        // collision
        if (r.getPosition().y > ground.getPosition().y)
            r.tick(false);
        else
            r.tick(true);
        // rendering
        win.clear(Color(147, 208, 249));
        View v = win.getView();
        Vector2f n = Vector2f(r.getPosition().x, r.getPosition().y - SHIP_HEIGHT*3);
        v.setCenter(n);
        win.setView(v);
        win.draw(ground);
        r.draw(win, sf::RenderStates::Default);
        win.display();
    }
    return EXIT_SUCCESS;
}
