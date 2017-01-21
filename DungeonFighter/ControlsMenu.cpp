#include <iostream>
#include "MainMenu.h"
#include "ControlsMenu.h"
#pragma warning(disable: 4996) //to allow the set color method to work



void ControlsMenu::Initialize(sf::RenderWindow *window) {
	//Main Menu Music here(It just replays from the beginning for simplicity sake)
	this->soundtrack = new sf::SoundBuffer();
	this->soundtrack->loadFromFile("Sounds/MainMenu.ogg");
	this->song = new sf::Sound(*soundtrack);

	(*song).setLoop(true);
	(*song).setVolume(10);
	(*song).play();



	//Adds the controls screen image
	this->optionTexture = new sf::Texture();
	(*optionTexture).loadFromFile("Graphics/background/ControlsMenu.jpg");
	this->sprite = new sf::Sprite(*optionTexture);
	(*sprite).setScale(3.0f, 2.0f);

	//Code below is how to display the title screen options, as well as centering it.
	this->optionFont = new sf::Font();
	this->optionFont->loadFromFile("Graphics/other/bloodcrow.ttf");

	this->optionsIntro = new sf::Text("Options\n", *optionFont, 100u);
	this->optionsIntro->setOrigin(this->optionsIntro->getGlobalBounds().width / 2, this->optionsIntro->getGlobalBounds().height / 2);
	this->optionsIntro->setPosition(window->getSize().x / 2, window->getSize().y / 8);
	this->optionsIntro->setColor(sf::Color::Red);

	this->controlsText1 = new sf::Text("-Up, Down, Left, &  Right Arrow Keys: \npress to move character around.\n\n", *optionFont, 40U);
	this->controlsText1->setOrigin(this->controlsText1->getGlobalBounds().width / 2, this->controlsText1->getGlobalBounds().height / 2);
	this->controlsText1->setPosition(window->getSize().x / 2, window->getSize().y / 8 + this->optionsIntro->getGlobalBounds().height);
	this->controlsText1->setColor(sf::Color::Cyan);

	this->controlsText2 = new sf::Text("\t\t\t-Space bar: to talk to NPCs.\n-Return/Enter: to pause the game and exit.\n", *optionFont, 40U);
	this->controlsText2->setOrigin(this->controlsText2->getGlobalBounds().width / 2, this->controlsText2->getGlobalBounds().height / 2);
	this->controlsText2->setPosition(window->getSize().x / 2, window->getSize().y / 8 + this->optionsIntro->getGlobalBounds().height + this->controlsText1->getGlobalBounds().height);
	this->controlsText2->setColor(sf::Color::Cyan);

	this->controlsText3 = new sf::Text("-D: to shoot your bullets.\n", *optionFont, 40U);
	this->controlsText3->setOrigin(this->controlsText3->getGlobalBounds().width / 2, this->controlsText3->getGlobalBounds().height / 2);
	this->controlsText3->setPosition(window->getSize().x / 2, window->getSize().y / 8 + this->optionsIntro->getGlobalBounds().height + this->controlsText1->getGlobalBounds().height + this->controlsText2->getGlobalBounds().height);
	this->controlsText3->setColor(sf::Color::Cyan);

	this->controlsText4 = new sf::Text("\n-You must pause your game before you can escape(Esc), \n but you can press escape now to leave this options menu.\n", *optionFont, 40U);
	this->controlsText4->setOrigin(this->controlsText4->getGlobalBounds().width / 2, this->controlsText4->getGlobalBounds().height / 2);
	this->controlsText4->setPosition(window->getSize().x / 2, window->getSize().y / 8 + this->optionsIntro->getGlobalBounds().height + this->controlsText1->getGlobalBounds().height + this->controlsText2->getGlobalBounds().height + this->controlsText3->getGlobalBounds().height);
	this->controlsText4->setColor(sf::Color::Cyan);

}

void ControlsMenu::Update(sf::RenderWindow *window) {
	//Allows player to exit back out into the main menu
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		corestate.SetState(new MainMenu());
		return;
	}
}


//Draws out the text below onto the screen
void ControlsMenu::Render(sf::RenderWindow *window) {
	window->draw(*this->sprite);
	window->draw(*this->optionsIntro);
	window->draw(*this->controlsText1);
	window->draw(*this->controlsText2);
	window->draw(*this->controlsText3);
	window->draw(*this->controlsText4);
}


//Destroys the variables below to free up space
void ControlsMenu::Destroy(sf::RenderWindow *window) {
	delete this->optionFont;
	delete this->optionsIntro;
	delete this->controlsText1;
	delete this->controlsText2;
	delete this->controlsText3;
	delete this->controlsText4;

	delete this->optionTexture;
	delete this->sprite;

	delete this->soundtrack;
	delete this->song;
}
