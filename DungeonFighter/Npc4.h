#pragma once

#include "BaseNPC.h"

//Npc1 inherits from BaseNPC to become an NPC, with slight variations.

class Npc4 : public BaseNPC{
public:
	Npc4(Speech *speech, Map *map, float x, float y) : BaseNPC(speech, map, x, y) {
		this->Load("npc4.png"); 
		this->setColor(sf::Color::Cyan);
		this->text = "Stop trying to escape and just accept your fate,little boy. \n\t\t\t\t\t\t\t\tNo one can help you here.";
	}

};
