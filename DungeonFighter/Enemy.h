#pragma once

#include "Entity.h"
#include "Map.h"


//This is the base template enemy class, which is inherited by other header enemy types to get the following properties

class Enemy : public Entity{
public:
	//constructor
	Enemy( Map* map, float x, float y, int health, int damage);

	void Updates(sf::RenderWindow *window);

	//Methods
	bool Update(sf::RenderWindow* window); //updates the enemy's actions


	void Collision(Entity* entity); //keeps track of its collision w/ the player class & blocks

	inline int Health() {
		return this->health;
	}

	
	inline int Damage() {
		return this->damage;
	}



protected:
	Map* map; //variable to find the location of the enemy
	int health, damage; //variables for the health and damage of the enemy

};
