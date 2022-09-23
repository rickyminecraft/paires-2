#include "Display.h"

Display::Display()
{
}

Display::~Display()
{
}

const bool Display::CreateWindows()
{
	Window = std::make_unique<sf::RenderWindow>(sf::VideoMode(Taille_x, Taille_y), Nom);
	Time = Horloge.now();
	return false;
}

sf::RenderWindow* Display::GetWindowHandle()
{
	return Window.get();
}

void Display::Render(scene* Scene)
{
	auto Time2 = Horloge.now();
	//permet de tourner avec un ips limiter
	if ((Time2 - Time) >= std::chrono::microseconds(20000)) //11111 = 90 ips 20000 = 50 ips 10000 = 100 ips
	{
		//on efface
		Window->clear();
		Scene->Render(Window.get());
		//et on affiche le tout
		Window->display();
		Time = Horloge.now();
	}
}
