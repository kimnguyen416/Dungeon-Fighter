#pragma once

#include "Bullet.h"
#include <iostream>
#include "Enemy.h"
#include "Entity.h"

using namespace std;

//PlayerBullet class inherits from the Bullet class. Instead of counting as a bullet, it belongs to the player specifically now.

class PlayerBullet : public Bullet{
public:
	//Constructor
	PlayerBullet(Map *map, float x, float y, float direction, float distance) : Bullet( map, x, y, direction, distance) {
		this->groupId = 4; //the groupId of the player's bullet is now 4, so this number is used when you want to specifically do something with the player's bullet if
		//it hits another entity
		this->Load("glassball.png"); //image of the player's bullet
		this->setColor(sf::Color::White);
	
	}

	
};









