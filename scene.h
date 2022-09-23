#pragma once

#include "Fichier.h"
#include "evenement.h"
#include <SFML/Graphics.hpp>

class scene
{
public:

	virtual void Render(sf::RenderWindow* Window) = 0;
	virtual void DoEvent(evenement* Event) = 0;

	virtual const bool Loadassets(Fichier* fichiers ) = 0;

	struct Player_Actions {};

protected:
	const bool Inside(sf::RectangleShape Bouton, const int X, const int Y);
};

