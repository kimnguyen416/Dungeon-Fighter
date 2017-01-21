#pragma once

#include "Enemy.h"

//Mob1 basically inherited the properties of the Enemy class, with some slight adjustment such as its health.



class Mob3 : public Enemy {
public:
	Mob3(Map *map, float x, float y) : Enemy(map, x, y, health, damage) {
		this->Load("mob3.png");
		this->health = 5;
	}
};