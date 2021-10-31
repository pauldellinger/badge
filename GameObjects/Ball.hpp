//
// Created by Paul Dellinger on 10/30/2021.
//


#ifndef BADGE_BALL_HPP
#define BADGE_BALL_HPP
#include <iostream>
#include <string>
#include <SFML/Graphics/CircleShape.hpp>

class Ball: public sf::CircleShape // should have position and drawing built in
{
public:
    Ball(float size, sf::Vector2f position, sf::Vector2f velocity);
    // Call the superclass constructor in the subclass' initialization list.
    // getPosition and setPosition already defined on CircleShape
    sf::Vector2f velocity;
    sf::Vector2f  getVelocity();
    void setVelocity(sf::Vector2f v);
    void update(float dt);

};




#endif //BADGE_BALL_HPP
