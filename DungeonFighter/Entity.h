#pragma once

#include <SFML/Graphics.hpp>
#include <string>

//Class that is in charge of all of the entities within the game. For ex, players and enemies, plus lives are all considered as entities

class Entity : public sf::Sprite{
public:
	//Default constructor
	Entity();

	//needed to control the entities speed in general
	sf::Vector2f velocity;

	//Methods
	void Load(std::string filename); //loads the image of the entity
	virtual bool Update(sf::RenderWindow* window); //updates the entity's every action
	bool CheckCollision(Entity* entity); //method that is in charge of the entity's collision w/ one another
	virtual void Collision(Entity* entity); //another variable to check for collision
	int GroupID(); //GroupID is important since you want to have each entity have its own # to differentiate them from one another
	int Active(); //checks whether the entity is still active or not
	void Destroy(); //Destroy the enemy when needed(such as if they have no more health).

	~Entity();
protected:
	//Variables to check for the groupid/ whether the entity is still active
	int active;
	int groupId;
private:
	//variable needed to properly display the entity's image
	sf::Texture* texture;
};
