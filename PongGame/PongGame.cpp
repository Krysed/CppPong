#include <SFML/Graphics.hpp>
#include <sstream>
#include <cstdlib>

#include "Bat.h"
#include "Ball.h"

int main()
{
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    
    //variables
    int playerScore = 0;
    int playerLives = 3;

    Bat bat(WIDTH / 2, HEIGHT - 20);
    Ball ball(WIDTH / 2, 0);

    sf::VideoMode videomode(WIDTH, HEIGHT);
    sf::RenderWindow window(videomode, "Pong!", sf::Style::Fullscreen);
    
    sf::Text hud;

    //text render
    sf::Font font;
    font.loadFromFile("fonts/DSDIGI.ttf");
    
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(sf::Color::White);

    sf::Clock clock;
    
    while (window.isOpen())
    {

        //handle player input
        //quit game keybind
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }
        //update bat,ball and HUD
        sf::Time dTime = clock.restart();

        bat.update(dTime);
        ball.update(dTime);

        std::stringstream displayedText;
        displayedText << "Score: " << playerScore << "  Lives: " << playerLives;

        hud.setString(displayedText.str());
        hud.setPosition(30, 30);

        if (ball.getPosition().top > window.getSize().x)
        {
            ball.boundsBottom();
            playerLives--;

            //reseting the game
            if (playerLives < 1)
            {
                playerScore = 0;
                playerLives = 3;
            }
        }

        if (ball.getPosition().top < 0)
        {
            ball.boundsBatOrTop();
            playerScore++;
        }
        //bounce ball when hitting sides
        if ((ball.getPosition().left < 0) || (ball.getPosition().left +10 > window.getSize().x))
        {
            ball.boundsSides();
        }
        if (ball.getPosition().intersects(bat.getPosition()))
        {
            ball.boundsBatOrTop();
        }
        //Draw bat,ball and HUD
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());

        window.display();
    }

    return 0;
}
