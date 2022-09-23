#include "PlayScene.h"

void PlayScene::Render(sf::RenderWindow* Window)
{
	//on dessine le fond en premier
	Window->draw(Fond);
	//puis les 48 tuiles
	for (int h = 0; h < 48; h++)
	{
		//caché
		if (Tuile_statut[h].second == 0)
		{
			if (this->Show)
			{
				Window->draw(Tuiles[h]);
			}
			else
			{
				TuilesBack.setPosition(Tuiles[h].getPosition());
				Window->draw(TuilesBack); 
			}
		}

		//totalement retourné
		if (Tuile_statut[h].second == 1)
		{
			Window->draw(Tuiles[h]);
		}

		//on montre
		if (Tuile_statut[h].second == 3)
		{
			Animate(Window);
			Tuile_statut[h].second = 1;
		}

		//on cache
		if (Tuile_statut[h].second == 4)
		{
			Animate(Window, false);
			Tuile_statut[h].second = 0;
		}

		if (Tuile_statut[h].second == 5)
		{
			
		}
	}

	sf::String String = "nombre d'essai : " + std::to_string(Score);
	Texte_1.setString(String);
	Window->draw(Texte_1);
}

void PlayScene::DoEvent(evenement* Event)
{
	this->Actions.Leave = false;
	this->Show = false;
	Event->DoEvents();
	if (Event->Action.Key_pressed)
	{
		if (Event->Action.touche == sf::Keyboard::Escape)
		{
			this->Actions.Leave = true;
		}
		//cheat
		if (Event->Action.touche == sf::Keyboard::S)
		{
			this->Show = true;
		}
	}
	if (Event->Action.Mouse_Button_pressed)
	{
		for (short h = 0; h < 48; h++)
		{
			if (Inside(Tuiles[h], Event->Action.x, Event->Action.y))
			{
				if (Tuile_statut[h].second == 0)
				{
					Tuile_statut[h].second = 3;
				}
			}
		}
	}

	Tuilesevent();
}

const bool PlayScene::Loadassets(Fichier* fichiers)
{
	short Position = 0;
	for (short y = 0; y < 6; ++y)
	{
		for (short x = 0; x < 8; ++x)
		{
			Tuiles[Position].setPosition(sf::Vector2f((float)(x * 128), (float)(y * 128)));
			Tuiles[Position].setSize(sf::Vector2f(128.0f, 128.0f));
			Position++;
		}
	}
	Tuile_statut.resize(48);

	Fond.setPosition(0.0f, 0.0f);
	Fond.setSize(sf::Vector2f(this->Taille_x, this->Taille_y));
	Hover.setSize(sf::Vector2f(128.0f, 128.0f));
	TuilesBack.setSize(sf::Vector2f(128.0f, 128.0f));
	HoverT = fichiers->Get_File<sf::Texture>(Divers_name[1]);
	if (fichiers->Has_error())
	{
		return false;
	}
	Hover.setTexture(&HoverT);
	TuilesBackT = fichiers->Get_File<sf::Texture>(Divers_name[0]);
	if (fichiers->Has_error())
	{
		return false;
	}
	TuilesBack.setTexture(&TuilesBackT);
	for (short h = 0; h < 24; h++)
	{
		TuilesT[h] = fichiers->Get_File<sf::Texture>(Tuiles_name[h]);
	}
	if (fichiers->Has_error())
	{
		return false;
	}
	for (short h = 0; h < 17; h++)
	{
		FondT[h] = fichiers->Get_File<sf::Texture>(Fonds_name[h]);
	}
	if (fichiers->Has_error())
	{
		return false;
	}
	Fond.setTexture(&FondT[0]);

	Fonte = fichiers->Get_File<sf::Font>(Fonte_name);
	if (fichiers->Has_error())
	{
		return false;
	}
	//petit
	Texte_1.setFont(Fonte);
	Texte_1.setOutlineColor(sf::Color::Black);
	Texte_1.setFillColor(sf::Color::Red);
	Texte_1.setStyle(sf::Text::Regular);
	Texte_1.setOutlineThickness(1.0f);
	Texte_1.setCharacterSize(20);
	Texte_1.setPosition(sf::Vector2f(30.0f, 30.0f));
	//gros
	Texte_2.setFont(Fonte);
	Texte_2.setOutlineColor(sf::Color::Black);
	Texte_2.setFillColor(sf::Color::Transparent);
	Texte_2.setStyle(sf::Text::Regular);
	Texte_2.setOutlineThickness(2.0f);
	Texte_2.setCharacterSize(150);
	Texte_2.setPosition(sf::Vector2f(80.0f, 300.0f));

	return true;
}

void PlayScene::Ready()
{
	if (!_Ready)
	{
		//on met 2 fois les meme valeurs qui vont être melanger dans shuffle
		for (short Boucle = Min; Boucle < Max / 2; ++Boucle)
		{
			Tuile_statut[Boucle].first = Boucle;
			Tuile_statut[Boucle].second = 0;
			Tuile_statut[Boucle + Max / 2].first = Boucle;
			Tuile_statut[Boucle + Max / 2].second = 0;
		}

		Shuffle();

		for (short h = 0; h < 48; h++)
		{
			Tuiles[h].setTexture(&TuilesT[Tuile_statut[h].first]);
		}
		Score = 0;
		
		_Ready = true;
	}
}

void PlayScene::Shuffle()
{
	std::random_device Rdevice;
	std::default_random_engine Engine(Rdevice());
	std::shuffle(Tuile_statut.begin(), Tuile_statut.end(), Engine);
}

void PlayScene::Animate(sf::RenderWindow* Window, const bool Show)
{

	//
}

void PlayScene::Tuilesevent()
{
	short Activé = 0;
	bool fini = true;
	short Numero_1 = -1;
	short Numero_2 = -1;
	for (short h = 0; h < 48; h++)
	{
		if (Tuile_statut[h].second != 2)
		{
			fini = false;
		}

		if (Tuile_statut[h].second == 1)
		{
			if (Numero_1 == -1)
			{
				Numero_1 = h;
				Activé++;
			}
			else if (Numero_2 == -1)
			{
				Numero_2 = h;
				Activé++;
			}
		}
	}
	if (Activé == 2)
	{
		Score++;
		if (Tuile_statut[Numero_1].first == Tuile_statut[Numero_2].first)
		{
			Tuile_statut[Numero_1].second = 2;
			Tuile_statut[Numero_2].second = 2;
		}
		else
		{
			Tuile_statut[Numero_1].second = 4;
			Tuile_statut[Numero_2].second = 4;
		}
	}
	//on a fini
	if (fini)
	{
		Fondnumero++;
		if (Fondnumero == 17)
		{
			Fondnumero = 0;
		}
		Fond.setTexture(&FondT[Fondnumero]);
		_Ready = !_Ready;
		Ready();
	}
}
