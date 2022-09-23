#pragma once

#include "Assets.h"
#include "scene.h"

class MainScene : public scene
{
public:
	void Render(sf::RenderWindow* Window);
	void DoEvent(evenement* Event);

	const bool Loadassets(Fichier* fichiers);

	struct Action:Player_Actions
	{
		bool Playclick = false;
		bool Exitclick = false;
	}Actions;

private:
	sf::RectangleShape Play;
	sf::Texture PlayT;
	sf::RectangleShape Exit;
	sf::Texture ExitT;
	sf::RectangleShape Hover;
	sf::Texture HoverT;
	bool IsHover = false;
};

