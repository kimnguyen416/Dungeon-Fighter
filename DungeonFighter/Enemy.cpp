#include "MainGame.h"
#include "Enemy.h"

#include <iostream>
using namespace std;


//Constructor that sets out the basic properties of the base enemy class
Enemy::Enemy(Map* map, float x, float y, int health, int damage){
	this->setPosition(x, y); 
	this->setColor(sf::Color::Red);
	this->map = map;
	this->groupId = 5;
	this->health = health; 
}


//Updates the Enemies status
bool Enemy::Update(sf::RenderWindow* window){
	//if the health is at 0, destroy the entity.
	if (this->health <= 0) {
		this->Destroy();
	}

	Entity::Update(window);
	return true;
}


//Keeps track of collision of the enemies
void Enemy::Collision(Entity* entity){
	switch (entity->GroupID()) {

	//when player bullets hit the enemy, they lose health by one point and the bullet disappears
	case 4:
		entity->Destroy();
		this->health -= 1;

		break;
	}

}
