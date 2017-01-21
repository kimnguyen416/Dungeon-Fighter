#pragma once

#include "GameState.h"
#include "SFML/Audio.hpp"

//Class for the gamestate of when the player just enters the game. This is the first window that the player sees before entering the game.
//It serves as a navigation window 


class MainMenu : public TinyState{
public:
	//Methods inherited from TinyState
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	//variables needed to print out the following information to the main menu screen
	sf::Font* font;
	sf::Text* title;
	sf::Text* play;
	sf::Text *controls;
	sf::Text* quit;

	//related to title screen
	sf::Texture *titleTexture;
	sf::Sprite *sprite;

	//variables to keep track of which option of the main menu that the player is currently hovering over
	int selected;
	bool upKey, downKey, leftKey, rightKey;

	//Main Menu music variable
	sf::SoundBuffer *soundtrack;
	sf::Sound *song;
};

