//
// Created by Paul Dellinger on 10/30/2021.
//

#include "Paddle.hpp"


Paddle::Paddle(float height, float width, float sideOffset, sf::Vector2u windowSize, Side side)
:RectangleShape(sf::Vector2f(height, width)){

    if (side == Left){
        // this.setPosition or just setPosition?
        setPosition(sf::Vector2f(sideOffset,0));
    }
    else{
        setPosition(sf::Vector2f(windowSize.x - sideOffset - height, 0));
    }

}

void Paddle::update(float dt){
    move(getVelocity() * dt);
}


sf::Vector2f Paddle::getVelocity() {
    return this->velocity;
}

void Paddle::setVelocity(sf::Vector2f v) {
    this->velocity = v;
}
