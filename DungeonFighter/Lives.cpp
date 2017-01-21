#include "Lives.h"


//Draws out the lives of the player onto the screen, set to 5.
Lives::Lives(sf::Font &font, unsigned int size) : sf::Text("Lives: 5", font, size){
	this->value = 5;
}


//Method to remove the life.
void Lives::RemoveLife(){
	this->value -= 1;
}


//Get the current value of the lives
int Lives::Value(){
	return this->value;
}


//Updates the life whenever something occurs
void Lives::Update(){
	this->setString("Lives: " + std::to_string(this->value));
}