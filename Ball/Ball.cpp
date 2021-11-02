//
// Created by Jordan Burton on 10/30/21.
//

#include <iostream>
#include "Ball.h"

Ball::Ball(float x, float y, float velocityX, float velocityY): sf::CircleShape(30) {
    this->velocityX = velocityX;
    this->velocityY = velocityY;
}

Ball::Ball(sf::Vector2f position, float velocityX, float velocityY): sf::CircleShape(30) {
    this->velocityX = velocityX;
    this->velocityY = velocityY;
}