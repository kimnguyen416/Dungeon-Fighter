#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "EntityManager.h"
#include "Entity.h"
#include "Speech.h"

//This keeps track of collision direction, at every angle of the collision.
typedef enum {
	NONE = -1,
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3,
	TOP_LEFT = 4,
	TOP_RIGHT = 5,
	BOTTOM_LEFT = 6,
	BOTTOM_RIGHT = 7
}Direction;


//Map class is in charge of the actual rendering of the map levels to the game screen.
class Map : public sf::Sprite{
public:
	//Constructor
	Map(EntityManager* entityManager);


	//Methods
	void Load(std::string filename, Speech *speech); //loads int he map
	virtual void Update(sf::RenderWindow* window); //updates the map
	int CheckCollision(Entity* entity, Direction direction); //checks for the collisions of the blocks within the map

	//Variables to indicate each area that is being entered
	std::string toparea, bottomarea, rightarea, leftarea; 

	~Map();
protected:
	std::string tileset; //name of the different blocks that are being used in each area
	//Variable dimensions of the maps
	int width = 0;
	int height = 0;
	int tilewidth = 0;
	int tileheight = 0;
	int* data;
private:
	//Variables needed to load the map images into the game
	sf::Texture* texture;
	sf::Image* tilesetTexture;
	//Variable needed to keep track of the entities being loaded into each map.
	EntityManager* entityManager;
};