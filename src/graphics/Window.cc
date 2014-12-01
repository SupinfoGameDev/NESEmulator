#include "Window.h"

Window::Window() : window_(sf::VideoMode(800, 600), "NES Emulator")
{
}

Window::~Window()
{
    window_.close();
}

void Window::blit(const sf::Sprite& sprite)
{
    window_.draw(sprite);
}
