#pragma once

#include <chrono>
#include "scene.h"
#include "MainScene.h"
#include "PlayScene.h"
#include "Display.h"
#include "evenement.h"
#include "Fichier.h"

class Paire
{
public:
	enum class Phase
	{
		Init,
		Main_screen,
		Play_screen,
		Play_screen_transition,
		Exit
	};

	Paire();
	~Paire();
	const bool Main_loop();


private:
	Phase Current_phase = Phase::Init;

	Fichier* fichier;

	evenement Event;
	MainScene Main;
	PlayScene Play;

	std::chrono::steady_clock horloge;
	std::chrono::steady_clock::time_point time;
	std::chrono::steady_clock::time_point time2;
};

