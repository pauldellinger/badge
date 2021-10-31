//
// Created by Paul Dellinger on 10/30/2021.
//

#include "Ball.hpp"
#include <SFML/Graphics/CircleShape.hpp>

// call the superclass constructor as part of the signature
// no return type for constructors?
Ball::Ball(float size, sf::Vector2f position, sf::Vector2f velocity): sf::CircleShape(size){
    // do I need "this" here?
    this->setPosition(position);
    this->velocity = velocity;

}
void Ball::update(float dt){
    move(velocity * dt);
}


sf::Vector2f Ball::getVelocity() {
    return this->velocity;
}

void Ball::setVelocity(sf::Vector2f v) {
    this->velocity = v;
}

