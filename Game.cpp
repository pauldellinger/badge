//
// Created by Jordan Burton on 10/31/21.
//

#include "Game.h"

Game::Game() : ball(sf::Vector2f(this->window.getSize().x / 2,
                                 this->window.getSize().y / 2),
                    .1,
                    .1) {
}

Game::Game(float initialVelocity) : ball(sf::Vector2f(this->window.getSize().x / 2,
                                                      this->window.getSize().y / 2),
                                         initialVelocity,
                                         initialVelocity) {
}

void Game::run() {
    window.create(sf::VideoMode(1080,960), "My SFML Game" /* ... */);
    //this->ball.setPosition(this->window.getSize().x / 2, this->window.getSize().y / 2);
    while (window.isOpen())
    {
        sf::Mouse mouse;
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);
        this->update();
        // draw everything here...
        window.draw(ball);

        // end the current frame
        window.display();
    }
}

void Game::update() {
    this->ball.setPosition(this->ball.getXPosition() + this->ball.getVelocityX(), this->ball.getYPosition() + this->ball.getVelocityY());
    this->updateVelocity();
}

bool Game::updateVelocity() {
    if (!this->hasHitBoundary()) {
        return false;
    }
    bool hasHitLeftBoundary = this->hasBallHitLeftBoundary();
    bool hasHitRightBoundary = this->hasBallHitRightBoundary();
    bool hasHitTopBoundary = this->hasBallHitTopBoundary();
    bool hasHitBottomBoundary = this->hasBallHitBottomBoundary();

    if (hasHitRightBoundary || hasHitLeftBoundary) {
        this->ball.setVelocityX(-this->ball.getVelocityX());
    }

    if (hasHitTopBoundary || hasHitBottomBoundary) {
        this->ball.setVelocityY(-this->ball.getVelocityY());
    }

    return true;
}

bool Game::hasHitBoundary() {
    bool hasHitLeftBoundary = this->hasBallHitLeftBoundary();
    bool hasHitRightBoundary = this->hasBallHitRightBoundary();
    bool hasHitTopBoundary = this->hasBallHitTopBoundary();
    bool hasHitBottomBoundary = this->hasBallHitBottomBoundary();


    return hasHitBottomBoundary || hasHitTopBoundary || hasHitLeftBoundary || hasHitRightBoundary;
}

bool Game::hasBallHitBottomBoundary() {
    return this->ball.getYPosition() + this->ball.getRadius() * 2 >= this->window.getSize().y;
}

bool Game::hasBallHitTopBoundary() {
    return this->ball.getYPosition() <= 0;
}

bool Game::hasBallHitLeftBoundary() {
    return this->ball.getXPosition() <= 0;
}

bool Game::hasBallHitRightBoundary() {
    return this->ball.getXPosition() + this->ball.getRadius() * 2 >= this->window.getSize().x;
}