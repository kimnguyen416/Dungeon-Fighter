#include "Score.h"

//Display the score onto the game screen
Score::Score(sf::Font &font, unsigned int size) : sf::Text("Score: 0", font, size){
	this->value = 0;
}


//Increments the score by 1 for now
void Score::IncrementScore(){
	this->value += 1;
}


//Updates the score whenever something occurs
void Score::Update(){
	this->setString("Score: " + std::to_string(this->value));
}