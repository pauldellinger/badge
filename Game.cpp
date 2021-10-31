//
// Created by Paul Dellinger on 10/30/2021.
//

#include "Game.hpp"

// this feels really ugly
// any way to initialize members inside the constructor instead of this initialization list?
Game::Game(sf::Vector2u windowSize) :

        /* A paddle shouldn't inherently know how big it should be
         * If Game class decides we can vary based on screen size
        */
        leftPaddle(30, 150, 50, windowSize, Left),
        rightPaddle(30, 150, 50, windowSize, Right),
        ball(20,
             sf::Vector2f(windowSize.x / 2, windowSize.y / 2),
             sf::Vector2f(10, 0)
        ){/* constructor is empty? */}

void Game::update(sf::Keyboard keyboard, float dt) {

    // paddles have no knowledge of keypresses, just velocity
    if (keyboard.isKeyPressed(sf::Keyboard::W)){
        leftPaddle.setVelocity(sf::Vector2f(0, -10));
    }
    else if (keyboard.isKeyPressed(sf::Keyboard::S)){
        leftPaddle.setVelocity(sf::Vector2f(0, 10));
    }
    else{
        leftPaddle.setVelocity(sf::Vector2f(0,0));
    }
    if (keyboard.isKeyPressed(sf::Keyboard::Up)){
        rightPaddle.setVelocity(sf::Vector2f(0, -10));
    }
    else if (keyboard.isKeyPressed(sf::Keyboard::Down)){
        rightPaddle.setVelocity(sf::Vector2f(0, 10));
    }
    else{
        rightPaddle.setVelocity(sf::Vector2f(0,0));
    }

    // TODO: collision detection somewhere around here
    ball.update(dt);
    leftPaddle.update(dt);
    rightPaddle.update(dt);


}

void Game::draw(sf::RenderWindow &window){
    // pass by reference because window is non-copyable
    window.draw(ball);
    window.draw(leftPaddle);
    window.draw(rightPaddle);
}
