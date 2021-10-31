#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

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

int main() {
    sf::CircleShape shape(50);
    // set the shape color to green
    shape.setFillColor(sf::Color(100, 250, 50));
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pong Clone");

    // create the game logic
    Game gameObj(window.getSize());
    // run the program as long as the window is open
    sf:: Keyboard keyboard;

    while (window.isOpen())
    {
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
        gameObj.update(keyboard, .01);
        // draw everything here...
        gameObj.draw(window);

        // end the current frame
        window.display();
    }
    return 0;
}
