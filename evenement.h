#pragma once

#include <SFML/Window.hpp>

class evenement
{
public:
	struct Event_Stat
	{
		sf::Keyboard::Key touche;
		int x = 0;
		int y = 0;
		bool Key_pressed = false;
		bool Mouse_Button_pressed = false;
		bool Closed = false;
	}Action;

	void DoEvents();
	void SetlinkedWindow(sf::Window* Win);

private:
	sf::Event event;
	sf::Window* Window;
};

