//
// Created by Paul Dellinger on 10/30/2021.
//

#ifndef BADGE_PADDLE_H
#define BADGE_PADDLE_H


#include <SFML/Graphics/RectangleShape.hpp>

enum Side {Left, Right};

class Paddle: public sf::RectangleShape {
public:
    Paddle(float height, float width, float sideOffset, sf::Vector2u windowSize, Side side);
    Side side;
    sf::Vector2f velocity;
    sf::Vector2f  getVelocity();
    void setVelocity(sf::Vector2f v);
    void update(float dt);

};


#endif //BADGE_PADDLE_H
