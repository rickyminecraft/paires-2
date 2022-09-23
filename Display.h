#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <chrono>
#include "scene.h"


class Display
{
public:
	Display();
	~Display();

	const bool CreateWindows();
	sf::RenderWindow* GetWindowHandle();
	void Render(scene* Scene);

private:
	int Taille_x = 1024;
	int Taille_y = 768;
	sf::String Nom = "Paires";

	std::unique_ptr<sf::RenderWindow> Window = nullptr;
	//obliger en version release, pour temporisation
	std::chrono::steady_clock Horloge;
	std::chrono::steady_clock::time_point Time;
	
protected:
};

