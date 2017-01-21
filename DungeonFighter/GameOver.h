#pragma once

#include "GameOver.h"
#include "MainMenu.h"

//When the player's health goes down to 0, this screen appears.

class GameOver : public TinyState{
public:
	//Methods inherited from TinyState
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);

private:
	sf::Text* gameovertext; //variable to set the game over text
	bool enterkey;//serves like a buffer for when the enter key is being pressed

	//Variables needed to properly display the backround image of the Game over screen
	sf::Texture *gameovertexture;
	sf::Sprite *sprite;
};