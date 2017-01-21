#pragma once

#include "Entity.h"
#include "Map.h"

//Class that serves as the general template of how NPCS should behave and rendering of the NPCS speech and its location w/ in the map.
//W/ in the game, all NPCS are Blue.

class BaseNPC : public Entity{
public:
	//Constructor
	BaseNPC(Speech* speech, Map* map,  float x, float y);

	//Methods
	bool Update(sf::RenderWindow* window); //updates the NPC
	void Collision(Entity* entity);//keeps track of the NPCS collision with the player & blocks

protected:
	std::string text; //variable needed to print out each NPCS text message
	Map* map; //keeps track of where the NPC is within the game
private:
	Speech* speech; //speech is related to how the NPC will talk w/in the game
};
