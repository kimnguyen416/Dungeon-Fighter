#include "Speech.h"


//Constructor that sets out the basic properties of the speech bubble
Speech::Speech(sf::Font &font, unsigned int size, sf::RenderWindow *window) : sf::Text("", font, size) {
	this->texture = new sf::Texture();
	this->texture->loadFromFile("Graphics/dialoguebox.png"); //loads in image of speech bubble
	this->setTexture(*this->texture);
	//sets the position of the speech bubble as well as the text message from the NPCs
	sf::Sprite::setPosition(0, window->getSize().y - sf::Text::getGlobalBounds().height);
	sf::Text::setPosition(5.0f, window->getSize().y - sf::Text::getGlobalBounds().height);
	this->window = window;
	this->speaking = false; //by default, set speaking to false to indicate no one is talking
}


//Display the text onto the screen once the player hits the spacebar whenever they are near an npc
void Speech::SetText(std::string text) {
	this->speaking = true; //set speaking to true now

	//Sections below sets the positioning of the text directly towards the center
	this->setString(text);
	float scaleWidth = sf::Text::getGlobalBounds().width / sf::Sprite::getTextureRect().width + 0.2f;
	float scaleHeight = sf::Text::getGlobalBounds().height / sf::Sprite::getTextureRect().height + 0.2f;

	sf::Sprite::setScale(scaleWidth, scaleHeight);

	sf::Sprite::setPosition(this->window->getSize().x / 2 - sf::Text::getGlobalBounds().width / 2, this->window->getSize().y - sf::Text::getGlobalBounds().height - 64);
	sf::Text::setPosition(this->window->getSize().x / 2 - sf::Text::getGlobalBounds().width / 2 + 5.0f, this->window->getSize().y - sf::Text::getGlobalBounds().height - 64);
}

//If the NPC is speaking, draw the NPCS words onto the screen
void Speech::Render() {
	if (this->speaking) {
		this->window->draw((sf::Sprite) *this);
		this->window->draw((sf::Text) *this);
	}

}

