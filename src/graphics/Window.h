#ifndef EMU_WINDOW_H
#define EMU_WINDOW_H

#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();
	~Window();
	void blit(const sf::Sprite& sprite);

private:
	sf::RenderWindow window_;
};

#endif // EMU_WINDOW_H
