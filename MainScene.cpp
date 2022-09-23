#include "MainScene.h"

void MainScene::Render(sf::RenderWindow* Window)
{
	if (IsHover)
	{
		Window->draw(Hover);
	}
	Window->draw(Play);
	Window->draw(Exit);
}

void MainScene::DoEvent(evenement* Event)
{
	IsHover = false;
	Actions.Playclick = false;
	Actions.Exitclick = false;
	Event->DoEvents();
	if (Inside(Play, Event->Action.x, Event->Action.y))
	{
		IsHover = true;
		Hover.setPosition(sf::Vector2f(400.0f, 334.0f));
		if (Event->Action.Mouse_Button_pressed)
		{
			Actions.Playclick = true;
		}
	}
	if (Inside(Exit, Event->Action.x, Event->Action.y))
	{
		IsHover = true;
		Hover.setPosition(sf::Vector2f(524.0f, 334.0f));
		if (Event->Action.Mouse_Button_pressed)
		{
			Actions.Exitclick = true;
		}
	}
}

const bool MainScene::Loadassets(Fichier* fichiers)
{
	Play.setPosition(sf::Vector2f(400.0f, 334.0f));
	Play.setSize(sf::Vector2f(100.0f, 100.0f));
	Exit.setPosition(sf::Vector2f(524.0f, 334.0f));
	Exit.setSize(sf::Vector2f(100.0f, 100.0f));
	Hover.setSize(sf::Vector2f(100.0f, 100.0f));
	PlayT = fichiers->Get_File<sf::Texture>(Divers_name[3]);
	if (fichiers->Has_error())
	{
		return false;
	}
	ExitT = fichiers->Get_File<sf::Texture>(Divers_name[2]);
	if (fichiers->Has_error())
	{
		return false;
	}
	Play.setTexture(&PlayT);
	Exit.setTexture(&ExitT);
	Hover.setFillColor(sf::Color::Red);
	return true;
}
