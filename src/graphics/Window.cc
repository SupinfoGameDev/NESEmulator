#include "Window.h"
#include "graphics.h"

Window::Window() : window_(sf::VideoMode(constants::screen_width * 2, constants::screen_height * 2), "NES Emulator", sf::Style::Close)
{
    window_.setFramerateLimit(30);
    while (window_.isOpen())
    {
        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        window_.clear();
        window_.display();
    }
}

Window::~Window()
{
}

void Window::blit(const sf::Sprite& sprite)
{
    window_.draw(sprite);
}
