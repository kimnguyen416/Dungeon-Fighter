#pragma once

#include "BaseNPC.h"

//Npc2 inherits from BaseNPC to become an NPC, with slight variations.

class Npc2 : public BaseNPC{
public:
	Npc2(Speech *speech, Map *map, float x, float y) : BaseNPC(speech, map, x, y) {
		this->Load("npc2.png");
		this->setColor(sf::Color::Cyan);
		this->text = "\t\t\t\t\t\tThere is no escape, \nonly pointless and endless fighting exists here.";
	}

};
