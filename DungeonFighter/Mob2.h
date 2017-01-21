#pragma once

#include "Enemy.h"

//Mob1 basically inherited the properties of the Enemy class, with some slight adjustment such as its health.


class Mob2 : public Enemy {
public:
	Mob2(Map *map, float x, float y) : Enemy(map, x, y, health, damage) {
		this->Load("mob2.png");
		this->health = 8;
	}
};