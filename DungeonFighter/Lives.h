#pragma once

#include <SFML/Graphics.hpp>

//Lives class displays the player's current life count before GameOver


class Lives : public sf::Text{
public:
	//Constructor
	Lives(sf::Font &font, unsigned int size);

	//Methods
	inline void SetValue(int value) {
		this->value = value;
	}

	void RemoveLife(); //remove the player's life
	void Update(); //updates the player's life
	int Value();//gets the current value of the player's life
private:
	int value;
};