#include <iostream>
#include <fstream>
#include <sstream>

#include "Map.h"
#include "BaseNPC.h"
#include "Enemy.h"
#include "Npc1.h"
#include "Npc2.h"
#include "Npc3.h"
#include "Npc4.h"
#include "Mob1.h"
#include "Mob2.h"
#include "Mob3.h"
#include "Mob4.h"


//Basic Map properties
Map::Map(EntityManager* entityManager){
	this->texture = new sf::Texture();
	this->tilesetTexture = new sf::Image();
	this->entityManager = entityManager;
}


//Method to Load in the actual map
void Map::Load(std::string filename, Speech *speech){
	std::string temp;
	//reads in the maps text file from the maps folder.
	std::ifstream mapFile("Graphics/maps/" + filename);
	
	//first line of the file is the tileset, i.e. blocks.png
	std::getline(mapFile, this->tileset);


	//following lines of the file is considered as the toparea, etc.
	std::getline(mapFile, this->toparea);
	std::getline(mapFile, this->bottomarea);
	std::getline(mapFile, this->leftarea);
	std::getline(mapFile, this->rightarea);


	//use the temp to get the following variables
	std::getline(mapFile, temp);
	this->tilewidth = std::stoi(temp, nullptr);
	std::getline(mapFile, temp);
	this->tileheight = std::stoi(temp, nullptr);

	std::getline(mapFile, temp);
	this->width = std::stoi(temp, nullptr);
	std::getline(mapFile, temp);
	this->height = std::stoi(temp, nullptr);


	this->data = new int[this->tilewidth * this->tileheight];

	//reads in every # block of each map area. 
	for (int y = 0; y < this->height; y += 1){
		for (int x = 0; x < this->width; x += 1){
			char temp;
			mapFile >> this->data[x + y * this->width] >> temp;
		}
	}
	//close out of the file
	mapFile.close();


	//Creates the maps and render in all of the blocks
	this->texture->create(this->width * this->tilewidth, this->height * this->tileheight);
	this->tilesetTexture->loadFromFile("Graphics/" + this->tileset); //get the tile images from the Graphics folder

	//Only 3 tiles per area
	sf::Image tile1, tile2, tile3;

	//Declaration of the map size
	tile1.create(64, 64);
	tile2.create(64, 64);
	tile3.create(64, 64);

	//Creation of the tiles
	tile1.copy(*this->tilesetTexture, 0, 0, sf::IntRect(0, 0, this->tilewidth, this->tileheight), true);
	tile2.copy(*this->tilesetTexture, 0, 0, sf::IntRect(this->tilewidth, 0, this->tilewidth, this->tileheight), true);
	tile3.copy(*this->tilesetTexture, 0, 0, sf::IntRect(0, this->tileheight, this->tilewidth, this->tileheight), true);


	//This for loop is where the blocks are being updated and the actual placement of the npcs and enemies(mobs & bosses) within the game
	for (int y = 0; y < this->height; y += 1){
		for (int x = 0; x < this->width; x += 1){
			switch (this->data[x + y * this->width]){
			case 0:
				break;
			//Case 1-3, updates the blocks
			case 1:
				this->texture->update(tile1, x * 64, y * 64);
				break;
			case 2:
				this->texture->update(tile2, x * 64, y * 64);
				break;
			case 3:
				this->texture->update(tile3, x * 64, y * 64);
				break;
			//Case 4-7, creates the enemies
			case 4: //Npc1
				this->texture->update(tile1, x * 64, y * 64);
				this->entityManager->Add("Npc1", new Npc1(speech, this, x * 64, y * 64));
				this->data[x + y * this->width] = 1;
				break;
			case 5://Npc2
				this->texture->update(tile1, x * 64, y * 64);
				this->entityManager->Add("Npc2", new Npc2(speech, this, x * 64, y * 64));
				this->data[x + y * this->width] = 1;
				break;
			case 6://Npc3
				this->texture->update(tile1, x * 64, y * 64);
				this->entityManager->Add("Npc3", new Npc3(speech, this, x * 64, y * 64));
				this->data[x + y * this->width] = 1;
				break;
			case 7://Npc4
				this->texture->update(tile1, x * 64, y * 64);
				this->entityManager->Add("Npc4", new Npc4(speech, this, x * 64, y * 64));
				this->data[x + y * this->width] = 1;
				break;
			//Case 8-11, for regular mobs/enemies
			case 8://Mob1
				this->texture->update(tile1, x * 64, y * 64);
				this->entityManager->Add("Mob1", new Mob1(this, x * 64, y * 64));
				this->data[x + y * this->width] = 1;
				break;
			case 9://Mob2
				this->texture->update(tile1, x * 64, y * 64);
				this->entityManager->Add("Mob2", new Mob2(this, x * 64, y * 64));
				this->data[x + y * this->width] = 1;
				break;
			case 10://Mob3
				this->texture->update(tile1, x * 64, y * 64);
				this->entityManager->Add("Mob3", new Mob3(this, x * 64, y * 64));
				this->data[x + y * this->width] = 1;
				break;
			case 11://Mob4
				this->texture->update(tile1, x * 64, y * 64);
				this->entityManager->Add("Mob4", new Mob4(this, x * 64, y * 64));
				this->data[x + y * this->width] = 1;
				break;
			//Case 9-?, for bosses

			}
		}
	}

	//sets the texture of the blocks
	this->setTexture(*this->texture);
}




//Updates the maps
void Map::Update(sf::RenderWindow* window){
}




//Keeps track of the collision of the blocks at every angle
int Map::CheckCollision(Entity* entity, Direction direction){


	int x = (int)(entity->getPosition().x + entity->getGlobalBounds().width / 2) / this->tilewidth;
	int y = (int)(entity->getPosition().y + entity->getGlobalBounds().height / 2) / this->tileheight;


	switch (direction){
	case LEFT:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width) / this->tilewidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height / 2) / this->tileheight;
		break;
	case RIGHT:
		x = (int)(entity->getPosition().x) / this->tilewidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height / 2) / this->tileheight;
		break;
	case UP:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width / 2) / this->tilewidth;
		y = (int)(entity->getPosition().y) / this->tileheight;
		break;
	case DOWN:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width / 2) / this->tilewidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height) / this->tileheight;
		break;
	case TOP_LEFT:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width) / this->tilewidth;
		y = (int)(entity->getPosition().y) / this->tileheight;
		break;
	case TOP_RIGHT:
		x = (int)(entity->getPosition().x) / this->tilewidth;
		y = (int)(entity->getPosition().y) / this->tileheight;
		break;
	case BOTTOM_LEFT:
		x = (int)(entity->getPosition().x + entity->getGlobalBounds().width) / this->tilewidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height) / this->tileheight;
		break;
	case BOTTOM_RIGHT:
		x = (int)(entity->getPosition().x) / this->tilewidth;
		y = (int)(entity->getPosition().y + entity->getGlobalBounds().height) / this->tileheight;
		break;
	}
	return this->data[x + y * this->width];
}


Map::~Map(){
	delete this->texture;
	delete this->tilesetTexture;
	delete this->data;
}