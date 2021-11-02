//
// Created by Jordan Burton on 10/31/21.
//

#ifndef BADGE_GAME_H
#define BADGE_GAME_H


#include "Ball/Ball.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Game {
private:
    Ball ball;
    sf::RenderWindow window;
    sf::Event event{};
    sf::Mouse mouse;
public:
    Game();
    Game(float initialVelocity);
    void run();
    void update();

private:
    bool updateVelocity();
    bool hasHitBoundary();
    bool hasBallHitTopBoundary();
    bool hasBallHitBottomBoundary();
    bool hasBallHitLeftBoundary();
    bool hasBallHitRightBoundary();
};


#endif //BADGE_GAME_H
