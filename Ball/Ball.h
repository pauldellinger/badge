//
// Created by Jordan Burton on 10/30/21.
//

#ifndef BADGE_BALL_H
#define BADGE_BALL_H


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Ball: public sf::CircleShape {
private:
    float velocityX;
    float velocityY;
public:
    Ball(float x, float y, float velocityX, float velocityY);
    Ball(sf::Vector2f position, float velocityX, float velocityY);
    sf::Vector2f getPosition() { return sf::CircleShape::getPosition(); };
    float getVelocityX() { return this-> velocityX; };
    float getVelocityY() { return this-> velocityY; };
    void setVelocityY(float velocityY) { this->velocityY = velocityY; };
    void setVelocityX(float velocityX) { this->velocityX = velocityX; };
    float getXPosition() { return sf::CircleShape::getPosition().x; };
    float getYPosition() { return sf::CircleShape::getPosition().y; };
    void update();
};


#endif //BADGE_BALL_H
