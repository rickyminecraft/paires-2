#include "Paire.h"

Paire::Paire()
{
	//Current_phase = Phase::Init;
}

Paire::~Paire()
{
}

const bool Paire::Main_loop()
{
	bool End = false;
	bool Error = false;
	Display Affichage;

	while (!End)
	{
		//Event.DoEvents();
		switch (Current_phase)
		{
		case Phase::Init:
			fichier = new Fichier();
			if (!fichier->Has_error())
			{
				if (!Main.Loadassets(fichier))
				{
					Error = true;
					Current_phase = Phase::Exit;
				}
				else if (!Play.Loadassets(fichier))
				{
					Error = true;
					Current_phase = Phase::Exit;
				}
				else
				{
					Affichage.CreateWindows();
					Event.SetlinkedWindow(Affichage.GetWindowHandle());
					Current_phase = Phase::Main_screen;
				}
			}
			else
			{
				Error = true;
				Current_phase = Phase::Exit;
			}
			break;
		case Phase::Main_screen:
			Main.DoEvent(&Event);
			Affichage.Render(&Main);
			if (Main.Actions.Exitclick || Event.Action.Closed)
			{
				Current_phase = Phase::Exit;
			}
			if (Main.Actions.Playclick)
			{
				time = horloge.now();
				Play.Ready();
				Current_phase = Phase::Play_screen_transition;
			}
			break;
		case Phase::Play_screen_transition:
			//laisse un peut de temps pour vider le pool d'event
			time2 = horloge.now();
			if (time2 - time >= std::chrono::milliseconds(200))
			{
				Event.DoEvents();
				Current_phase = Phase::Play_screen;
			}
			break;
		case Phase::Play_screen:
			Play.DoEvent(&Event);
			Affichage.Render(&Play);
			if (Play.Actions.Leave)
			{
				Current_phase = Phase::Main_screen;
			}
			break;
		case Phase::Exit:
			delete fichier;
			End = true;
			break;
		}

		if (Event.Action.Closed)
		{
			Current_phase = Phase::Exit;
		}

		/*if (event.key.code == sf::Keyboard::M)
		{
			Mute = !Mute;
		}*/
		
	}

	if (Error)
	{
		return false;
	}
	return true;
}
