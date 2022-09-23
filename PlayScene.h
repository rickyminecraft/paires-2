#pragma once

#include <random>
#include "Assets.h"
#include "scene.h"
#include "Animation.h"

class PlayScene : public scene
{
public:
	void Render(sf::RenderWindow* Window);
	void DoEvent(evenement* Event);

	const bool Loadassets(Fichier* fichiers);
	void Ready();

	struct Action :Player_Actions
	{
		bool Leave = false;
	}Actions;

private:

	Animation Tuile_1;
	short Tuile_1_number = -1;
	Animation Tuile_2;
	short Tuile_2_number = -1;
	const short Min = 0, Max = 48;
	int Score = 0;
	bool _Ready = false;
	short Fondnumero = 0;
	bool Show = false; //cheat
	bool Is_animating[2] = { false, false };
	int Taille_x = 1024;
	int Taille_y = 768;
	std::vector<std::pair<short, short>> Tuile_statut;
	//Tuile Tuile_statut[48] = {}; // 3 etats : pas choisi, choisi et eliminer (0,1,2)
	sf::RectangleShape Tuiles[48];
	sf::Texture TuilesT[24];
	sf::RectangleShape Fond;
	sf::Texture FondT[17];
	sf::RectangleShape Hover;
	sf::Texture HoverT;
	sf::RectangleShape TuilesBack;
	sf::Texture TuilesBackT;

	sf::Font Fonte;
	sf::Text Texte_1, Texte_2;
	
	void Shuffle();
	void Animate(sf::RenderWindow* Window, const bool Show = true);
	void Tuilesevent();
};

