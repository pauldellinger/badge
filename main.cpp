#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

//bool isMouseOver(sf::Shape &shape, const sf::Input &input)
//{
//    sf::Vector2f mousePos(input.GetMouseX(), input.GetMouseY());
//
//    if(
//        // check mouse position
//            (mousePos.x >= shape.GetPosition().x)
//            &&
//            (mousePos.x <= shape.GetPosition().x + shape.GetSubRect().GetWidth())
//            &&
//            (mousePos.y >= shape.GetPosition().y)
//            &&
//            (mousePos.y <= shape.GetPosition().y + shape.GetSubRect().GetHeight())
//            &&
//            // check pixel on shape
//            (shape.GetPixel(mousePos.x - shape.GetPosition().x, mousePos.y - shape.GetPosition().y).a == 255)
//            )
//        return true;
//    return false;
//}

int getRandomNumber(int max, int min) {
    return rand()%(max-min + 1) + min;
}

bool isClickWithinShape(sf::Shape &shape, sf::Mouse &mouse, sf::RenderWindow &window)
{

//    std::cout << "mouse positions x, y: " << mouse.getPosition(window).x << ", " << mouse.getPosition(window).y;
//    std::cout << '\n';
//    std::cout << "shape positions x, y, width, height: " << shape.getPosition().x << ", " << shape.getPosition().y << ", " << shape.getLocalBounds().width << ", " << shape.getLocalBounds().height;
//    std::cout << "\n";
    if (
            mouse.getPosition(window).x >= shape.getPosition().x &&
            mouse.getPosition(window).x <= shape.getPosition().x + shape.getGlobalBounds().width &&
            mouse.getPosition(window).y >= shape.getPosition().y &&
            mouse.getPosition(window).y <= shape.getPosition().y + shape.getGlobalBounds().height
            ) {
        return true;
    }

    return false;
}

int main() {
    sf::CircleShape circle(50);
    // set the circle color to green
    circle.setFillColor(sf::Color(100, 250, 50));
    // create the window
    Game game;
    game.run();
    return 0;
}
