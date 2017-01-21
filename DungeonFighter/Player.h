#pragma once
#include "Entity.h"
#include "Map.h"
#include "Lives.h"
#include "Score.h"

//indicates that saveSystem is defined somewhere in within the source file
//extern SaveSystem saveSystem;

extern std::string nextarea; //variable that keeps track of what area the player is in
extern float startingx, startingy; //these 2 variables just keeps track of the player's position throughout the map


//Player class contains all of the properties of the player, such as the player's walking speed and health.

class Player : public Entity {
public:
	//Constructor
	Player( EntityManager *entityManager, Map *map, float x, float y);

	//Methods
	bool Update(sf::RenderWindow *window); //updates the player's status 
	void Collision(Entity *entity); //keeps track of the player's collision w/ other objects

	int health;

private:
	float speed; //controls the player's speed
	EntityManager *entityManager;
	bool spaceKey, dKey; //spacekey = spacebar, dKey = D key on keyboard. It is for throwing in this case
	float direction;
	Map *map;
	float damageknockback;
};
