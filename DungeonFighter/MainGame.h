#pragma once
#include "SFML/Audio.hpp"

#include "EntityManager.h"
#include "GameState.h"
#include "Score.h"
#include "Lives.h"
#include "Speech.h"

#include "Map.h"

#include "SaveSystem.h"


extern bool gameOver;
//extern SaveSystem saveSystem;
extern float startingx, startingy;
extern std::string nextarea;


//Class to keep track of everything that happens within the main game.

class MainGame : public TinyState{
public:
	//Methods inherited from TinyState
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);


private:
	Score *score; //variable for the score of the player
	Lives* lives; //variable for the lives of the player
	Speech *speech; //variable for Entity's speech
	sf::Text* pausedtext; //variable for the paused text whenever the player pauses the screen

	sf::Font* font;//variable of the text font

	bool paused, enterkey; //serves as buffers for when the player presses the enter key 

	EntityManager* manager;

	Map* map; 

	//variables for the background music within the game
	sf::SoundBuffer *backgroundmusicbuffer;
	sf::Sound *backgroundmusic;
};