#pragma once
#include <SFML/Graphics.hpp>

//Class that allows entities to produce speech bubbles and allow more interaction to occur within the game.

class Speech : public sf::Text, public sf::Sprite {
public:
	//Constructor
	Speech(sf::Font &font, unsigned int size, sf::RenderWindow *window);

	//Methods
	void SetText(std::string text); //set the text for each npc/entities to whatever you wish it to be.
	void Render(); //method to allow the actual rendering or display of this text onto the window

	//variable to check whether the entity is currently speaking or not
	bool speaking;


private:
	sf::Texture* texture; //variable needed to display the text
	sf::RenderWindow * window; //variable to switch the window of the game
};
