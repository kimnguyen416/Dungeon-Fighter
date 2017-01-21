#pragma once
#include "GameState.h"
#include "SFML/Graphics.hpp"

//This is just another state(inherits from TinyState) that is a part of the Main Menu screen. If the player chooses Controls, it brings them to this window.

class ControlsMenu : public TinyState {
public:
	//Methods inherited from TinyState
	virtual void Initialize(sf::RenderWindow *window);
	virtual void Update(sf::RenderWindow *window);
	virtual void Render(sf::RenderWindow *window);
	virtual void Destroy(sf::RenderWindow *window);

private:
	//All variables needed to print out the controls of the game for the user
	sf::Font *optionFont;
	sf::Text *optionsIntro;
	sf::Text *controlsText1;
	sf::Text *controlsText2;
	sf::Text *controlsText3;
	sf::Text *controlsText4;

	//Variables needed to properly display the backround image of the controls menu
	sf::Texture *optionTexture;
	sf::Sprite *sprite;

	//Controls music variable
	sf::SoundBuffer *soundtrack;
	sf::Sound *song;

};

