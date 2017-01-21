#pragma once

#include <SFML/Graphics.hpp>

//Main class that keeps track of the score within the game.

class Score : public sf::Text{
public:
	//Constructor
	Score(sf::Font &font, unsigned int size);
	
	inline void SetValue(int value) {
		this->value = value;
	}


	inline int GetScore() {
		return this->value;
	}
	
	//Methods
	void IncrementScore(); //increases the score
	void Update(); //updates the score
private:
	int value;
};