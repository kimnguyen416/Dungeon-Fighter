#pragma once

#include "BaseNPC.h"

//Npc1 inherits from BaseNPC to become an NPC, with slight variations.

class Npc1 : public BaseNPC{
public:
	Npc1(Speech *speech, Map *map, float x, float y) : BaseNPC(speech, map, x, y) {
		this->Load("npc1.png");
		this->setColor(sf::Color::Cyan);
		this->text = "So your locked down here too? \nWell no matter, you're just going \nto die like the rest of them.";
	}

};
