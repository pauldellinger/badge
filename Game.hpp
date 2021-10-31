//
// Created by Paul Dellinger on 10/30/2021.
//

#ifndef BADGE_GAME_HPP
#define BADGE_GAME_HPP
#include "SFML/Graphics.hpp"
#include "GameObjects/Ball.hpp"
#include "GameObjects/Paddle.hpp"


class Game {
public:
    Game(sf::Vector2u);
    // how will we create a variable number of game objects?
    Ball ball;
    Paddle leftPaddle;
    Paddle rightPaddle;

    // called in the game loop
    // each game object needs corresponding methods
    void update(sf::Keyboard, float dt);
    void draw(sf::RenderWindow &window);
};


#endif //BADGE_GAME_HPP
