#include "scene.h"

const bool scene::Inside(sf::RectangleShape Bouton, const int X, const int Y)
{
	//si on est dedans a l'horizontal
	if (X >= Bouton.getPosition().x && X <= Bouton.getPosition().x + Bouton.getSize().x)
	{
		//est on dedans a la vertical
		if (Y >= Bouton.getPosition().y && Y <= Bouton.getPosition().y + Bouton.getSize().y)
		{
			return true;
		}
	}
	return false;
}
