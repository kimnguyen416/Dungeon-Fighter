#pragma once

#include "BaseNPC.h"

//Npc1 inherits from BaseNPC to become an NPC, with slight variations.

class Npc3 : public BaseNPC{
public:
	Npc3(Speech *speech, Map *map, float x, float y) : BaseNPC(speech, map, x, y) {
		this->Load("npc3.png"); 
		this->setColor(sf::Color::Cyan);
		this->text = "Less talking, more fighting.";
	}

};
