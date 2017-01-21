#include "Entity.h"

//Definition of the entity constructor
Entity::Entity(){
	this->texture = new sf::Texture();
	this->active = 1;
	this->groupId = 0; //the general entity has a groupid of 0.
}

//The sprites are being loaded from the sprites folder
void Entity::Load(std::string filename){
	this->texture->loadFromFile("Graphics/sprites/" + filename);
	this->setTexture(*this->texture);
}


//Updates whenever the entity moves
bool Entity::Update(sf::RenderWindow* window){
	this->move(this->velocity); //keeps track of entity movement
	return true;
}


//Template for when the entity collides with something
void Entity::Collision(Entity* entity){
}

//A method that further checks for collision, if so it makes sure the position of the entity is set properly
bool Entity::CheckCollision(Entity* entity){
	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

//Returns the groupid of the entity
int Entity::GroupID(){
	return this->groupId;
}

//Returns the active state of the entity
int Entity::Active(){
	return this->active;
}

//Destroys the entity if it is not in an active state anymore and sets its active int back to 0.
void Entity::Destroy(){
	this->active = 0;
}


Entity::~Entity(){
	delete this->texture;
}