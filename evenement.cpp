#include "evenement.h"

void evenement::DoEvents()
{
	Window->pollEvent(event);
	switch (event.type)
	{
	case sf::Event::Closed:
		Action.Closed = true;
		break;
	case sf::Event::KeyPressed:
		Action.Key_pressed = true;
		Action.touche = event.key.code;
		break;
	case sf::Event::KeyReleased:
		Action.Key_pressed = false;
		break;
	case sf::Event::MouseButtonPressed:
		Action.x = event.mouseButton.x;
		Action.y = event.mouseButton.y;
		Action.Mouse_Button_pressed = true;
		break;
	case sf::Event::MouseButtonReleased:
		Action.Mouse_Button_pressed = false;
		break;
	case sf::Event::MouseMoved:
		Action.x = event.mouseMove.x;
		Action.y = event.mouseMove.y;
		break;
	}
}

void evenement::SetlinkedWindow(sf::Window* Win)
{
	Window = Win;
}
