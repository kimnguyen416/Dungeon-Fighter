#include <iostream>
#include "MainMenu.h"
#include "MainGame.h"
#include "ControlsMenu.h"
#pragma warning(disable: 4996)

#include "Map.h"



void MainMenu::Initialize(sf::RenderWindow* window){
	//Main Menu Music here
	this->soundtrack = new sf::SoundBuffer();
	this->soundtrack->loadFromFile("Sounds/MainMenu.ogg"); //.ogg to save amount of resources being used
	this->song = new sf::Sound(*soundtrack);

	(*song).setLoop(true);
	(*song).setVolume(10);
	(*song).play();
	


	this->selected = 0;

	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/other/bloodcrow.ttf");


	//Adds the title screen image
	this->titleTexture = new sf::Texture();
	(*titleTexture).loadFromFile("Graphics/background/MainMenu.jpg");
	this->sprite = new sf::Sprite(*titleTexture);
	(*sprite).setScale(.7f, 1.1f);

	//Declares the position and positioning of the text below
	this->title = new sf::Text("Dungeon Fighter", *this->font, 170U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 8);
	this->play = new sf::Text("Play", *this->font, 100u);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
	this->play->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	this->controls = new sf::Text("Controls", *this->font, 100u);
	this->controls->setOrigin(this->controls->getGlobalBounds().width / 2, this->controls->getGlobalBounds().height / 2);
	this->controls->setPosition(window->getSize().x / 2, window->getSize().y / 2 + this->play->getGlobalBounds().height);

	this->quit = new sf::Text("Quit", *this->font, 100u);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
	this->quit->setPosition(window->getSize().x / 2, window->getSize().y / 2 + this->play->getGlobalBounds().height + this->controls->getGlobalBounds().height);


}



void MainMenu::Update(sf::RenderWindow* window){
	//Allows the player to press the up and down keys constantly, as they contemplate on what option to pick.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey) {
		this->selected -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey) {
		this->selected += 1;
	}
	if (this->selected > 2) {
		this->selected = 0;
	}
	if (this->selected < 0) {
		this->selected = 1;
	}
	if (this->selected < 0) {
		this->selected = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){
		switch (this->selected){
		case 0:
			//switches to the main game if the play option was picked
			corestate.SetState(new MainGame());
			break;
		case 1:
			//Switches to the controls menu
			corestate.SetState(new ControlsMenu());
			break;
		case 2:
			//quits out of the game safely if this was picked.
			quitgame = true;
			break;
		}
	}


	//Serves as a buffer when the up and down arrow keys are pressed
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}


void MainMenu::Render(sf::RenderWindow* window){
	//Options are default to appear white
	this->play->setColor(sf::Color::White);
	this->controls->setColor(sf::Color::White);
	this->quit->setColor(sf::Color::White);
	//Once player hovers over an option, it becomes blue instead.
	switch (this->selected) {
	case 0:
		this->play->setColor(sf::Color::Blue);
		break;
	case 1:
		this->controls->setColor(sf::Color::Blue);
		break;
	case 2:
		this->quit->setColor(sf::Color::Blue);
		break;
	}


	//draws the elements below to screen
	window->draw(*this->sprite);
	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->controls);
	window->draw(*this->quit);
}

//Deletes the following variables after the game state switches to another state besides the main menu
void MainMenu::Destroy(sf::RenderWindow* window){
	delete this->font;
	delete this->title;
	delete this->play;
	delete this->controls;
	delete this->quit;

	delete this->titleTexture;
	delete this->sprite;
	
	delete this->soundtrack;
	delete this->song;
}