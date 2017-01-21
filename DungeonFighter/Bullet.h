#pragma once

#include "Entity.h"

#include "Map.h"
#include "Score.h"

//Bullet class is the main class behind the mechanics of how a "bullet" should behave within the game.
//It will be inherited by both the enemy and player class

class Bullet : public Entity{
public:
	//Constructor
	Bullet(Map *map, float x, float y, float direction, float distance); //for just the text messages from npc, doesnt need a score

	//Methods
	bool Update(sf::RenderWindow* window);
	void Collision(Entity* entity);


private:
	Map *map; 
	float distance; //This variable determines how far the bullet will travel within the map
};
