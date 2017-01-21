#include "GameOver.h"
#include "MainMenu.h"
#pragma warning(disable: 4996) 

//Method to define what each of the variables are and what will be printed onto the screen
void GameOver::Initialize(sf::RenderWindow* window){
	//Adds the title screen image
	this->gameovertexture = new sf::Texture();
	(*gameovertexture).loadFromFile("Graphics/background/GameOver.png");
	this->sprite = new sf::Sprite(*gameovertexture);
	(*sprite).setPosition(1280 / 1000, 768 / 1000);

	enterkey = false;
	sf::Font* font = new sf::Font();
	font->loadFromFile("Graphics/other/bloodcrow.ttf");

	this->gameovertext = new sf::Text("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPress Enter to go back \n\tto the title screen.......", *font, 40U);
	this->gameovertext->setColor(sf::Color::Red);
	//Defines the exact position of the text
	this->gameovertext->setOrigin(sf::Vector2f(this->gameovertext->getGlobalBounds().width / 2, this->gameovertext->getGlobalBounds().height / 2));
	this->gameovertext->setPosition(sf::Vector2f(window->getSize().x - 280, window->getSize().y / 6));
}


//Updates the status of the gameover screen
void GameOver::Update(sf::RenderWindow* window){
	//When player hits enter, returns the user back to 
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && enterkey){
		corestate.SetState(new MainMenu());
	}

	//serves as a buffer for when the player enters the gameoverscreen once
	enterkey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);
}


//Draws out the sprite & gameovertext
void GameOver::Render(sf::RenderWindow* window){
	window->draw(*this->sprite);
	window->draw(*this->gameovertext);
}



//Destroys the variables once out of the game over screen
void GameOver::Destroy(sf::RenderWindow* window){
	delete this->gameovertexture;
	delete this->sprite;
	delete this->gameovertext;
}