#include "MainGame.h"
#include "BaseNPC.h"

//Constructor that sets out all of the basic properties of the NPC
BaseNPC::BaseNPC(Speech* speech, Map* map, float x, float y){
	this->setPosition(x, y);
	this->setColor(sf::Color::Cyan); //all NPCS will be blue
	this->map = map;
	this->groupId = 3; //Their group id is 3.
	this->speech = speech;
}


//Updates the NPC's status
bool BaseNPC::Update(sf::RenderWindow* window){
	Entity::Update(window);
	return true;
}


//This method is in charge of the collision of the NPC
void BaseNPC::Collision(Entity* entity){
	switch (entity->GroupID()) {
	//When the bullet(group id is 2) which the player has since the player bullet inherits from the bullet class, the player bullet
	//will technically have the bullet that will hit the NPC when the player presses the space bar near the NPC.
	//When that occurs, the NPC's text is activated and then destroyed afterwards.
	case 2:
		speech->SetText(this->text);
		entity->Destroy();
		break;
	}
}
