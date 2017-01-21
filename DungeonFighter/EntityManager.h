#pragma once

#include <unordered_map>
#include <vector>

#include "Entity.h"

//This is a class that adds more control over the entity's within the game and to keep track of their locations within each map.

class EntityManager{
public:
	//Default constructor
	EntityManager();

	//Methods
	void Add(std::string name, Entity* entity); //adds the entity into existence
	Entity *Get(std::string name); //As the method is name, you simply use this to get the Entity
	bool Update(sf::RenderWindow* window);//updates the entity
	void Render(sf::RenderWindow* window);//renders the entity

	~EntityManager();


private:
	std::unordered_map<std::string, Entity*> entities;
};