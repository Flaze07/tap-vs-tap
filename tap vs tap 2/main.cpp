#include <SFML/Graphics.hpp>

enum class Condition {red, blue};

int main()
{
    sf::Vector2f window_size(720, 480);
    sf::RenderWindow window(sf::VideoMode(window_size.x, window_size.y), "tap vs tap");
    sf::RectangleShape red(sf::Vector2f(window_size.x , window_size.y));
    red.setOrigin(red.getSize().x, 0);
    red.setFillColor(sf::Color::Red);
    red.setPosition(window_size.x / 2, 0);
    sf::RectangleShape blue(sf::Vector2f(window_size.x , window_size.y));
    blue.setOrigin(0, 0);
    blue.setPosition(window_size.x / 2, 0);
    blue.setFillColor(sf::Color(0, 0, 128));
    bool pressed1;
    bool pressed2;
    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arial.ttf");
    sf::Text bluewins;
    sf::Text redwins;
    sf::Text Retry;
    int CharSize = 20;
    sf::Vector2f CharPos(window_size.x /2 , window_size.y / 2);
    bluewins.setFont(font);
    redwins.setFont(font);
    Retry.setFont(font);
    bluewins.setString("blue wins");
    redwins.setString("red wins");
    Retry.setString("press R to retry");
    bluewins.setCharacterSize(CharSize);
    redwins.setCharacterSize(CharSize);
    Retry.setCharacterSize(CharSize);
    bluewins.setPosition(CharPos);
    redwins.setPosition(CharPos);
    Retry.setPosition(CharPos.x, CharPos.y + CharSize);
    bool finished;
    Condition condition;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        if (!finished)
        {
            if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) && (pressed1 == false) )
            {
                red.move(1, 0);
                blue.move(1, 0);
                pressed1 = true;
            }
            else
            {
                pressed1 = false;
            }
            if ( (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) && (pressed2 == false) )
            {
                blue.move(-1, 0);
                red.move(-1, 0);
                pressed2 = true;
            }
            else
            {
                pressed2 = false;
            }
            window.clear();
            window.draw(red);
            window.draw(blue);
            window.display();
            if (red.getPosition().x == window_size.x)
            {
                condition = Condition::red;
                finished = true;
            }
            else if (blue.getPosition().x == 0)
            {
                condition = Condition::blue;
                finished = true;
            }
        }
        else
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                finished = false;
                red.setPosition(window_size.x / 2, 0);
                blue.setPosition(window_size.x / 2, 0);
            }
            window.clear();
            if (condition == Condition::red) window.draw(redwins);
            else window.draw(bluewins);
            window.draw(Retry);
            window.display();
        }
    }
}
