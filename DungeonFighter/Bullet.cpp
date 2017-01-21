#include "Bullet.h"
#include <iostream>


//Constructor of Bullets that set the general guidelines of bullets
Bullet::Bullet(Map *map, float x, float y, float direction, float distance){
	this->active = 1;
	this->groupId = 2; //bullet's groupid is 2
	this->Load("ball1.png");
	this->setColor(sf::Color::Transparent); //Transparent since you don't want to see the bullet that comes out to talk to the npcs

	this->setScale(.8f, .8f); 

	//Sets the direction and speed of the bullets going out from the player
	this->velocity.x = cos(direction / 180.0f * 3.14f) * 10; //converts to radians, divide by 3 to slow the bullets down
	this->velocity.y = sin(direction / 180.0f * 3.14f) * 10;
	this->setPosition(x + this->getGlobalBounds().width, y + this->getGlobalBounds().height);

	this->distance = distance;
	this->map = map;
}




//Updates the bullet's status
bool Bullet::Update(sf::RenderWindow* window){
	//if the position of the bullet is close to outside of the window's screen, destroy it
	if (this->getPosition().y <= 0 || this->getPosition().y + this->getGlobalBounds().height >= window->getSize().y) {
		this->Destroy();
	}

	//distance formula to check for the bullet's distance
	this->distance -= sqrt(this->velocity.x * this->velocity.x + this->velocity.y * this->velocity.y);

	//if the distance is out of bound, destroy it
	if (this->distance <= 0) {
		this->Destroy();
	}


	//Makes sure bullets are destroyed once it hits a block w/ collision properties
	if (this->map->CheckCollision(this, NONE) > 2) {
		this->Destroy();
	}

	//Updates
	Entity::Update(window);
	return true;
}


//Method for bullet's collision
void Bullet::Collision(Entity* entity){

}
