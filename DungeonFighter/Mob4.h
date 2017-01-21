#pragma once

#include "Enemy.h"

//Mob1 basically inherited the properties of the Enemy class, with some slight adjustment such as its health.


class Mob4 : public Enemy {
public:
	Mob4(Map *map, float x, float y) : Enemy(map, x, y, health, damage) {
		this->Load("mob4.png");
		this->health = 12;
	}
};