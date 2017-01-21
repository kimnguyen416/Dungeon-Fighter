#include "EntityManager.h"

EntityManager::EntityManager(){
}


//Method to add the entity into the map
void EntityManager::Add(std::string name, Entity* entity){
	//checks for whether the new entity being added is within the map alrdy or not.
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);


	while (found != this->entities.end()){
		name += "0"; //if the name of the entity cannot be found, just add a 0 to it and check for whether the entity name is within the map again
		found = this->entities.find(name);
	}

	//this line actually adds the entity to the game
	this->entities.insert(std::make_pair(name, entity));
}


//Method to actually get the entity through its name
Entity* EntityManager::Get(std::string name){
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);

	if (found == this->entities.end()){
		return NULL;
	}
	else{
		return found->second;
	}
}


//Method to update the entity
bool EntityManager::Update(sf::RenderWindow* window){
	//creates a vector to see what entity that needs to be removed from the map
	std::vector<std::string> toRemove;


	//Big nested for loop + nested if statements to check for each entities active state and its collision with other entities within the game
	for (auto& iterator : this->entities){
		//First part of the if statement looks for groupIds past 2, while the player's id is set to 1, therefore, it checks the state of all entities.
		if (iterator.second->GroupID() > 2 || iterator.second->GroupID() == 1){
			for (auto& iterator2 : this->entities){
				if (iterator.first != iterator2.first){
					if (iterator.second->Active() && iterator2.second->Active()){
						//Keeps track of the collision every second and updates as need
						if (iterator.second->CheckCollision(iterator2.second)){
							iterator.second->Collision(iterator2.second);
						}
					}
				}
			}
		}


		//Looks at the active state of the entities
		switch (iterator.second->Active()){
		case 0:
			//if the active state is 0, that means it is inactive and should be pushed to the vector called toRemove for removal permanently from the game
			toRemove.push_back(iterator.first);
			break;
		//Otherwise, just let the entity continue to exist
		default:
			if (!iterator.second->Update(window)) {
				return false;
			}
			break;
		}
	}



	//The actual process of removing all of the inactive entities within the game
	for (auto& iterator : toRemove){
		std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(iterator);

		if (found != this->entities.end()){
			delete found->second;
			this->entities.erase(iterator);
		}
	}
	toRemove.clear();

	return true;
}


//Renders the entities to the game by using SFML's draw function
void EntityManager::Render(sf::RenderWindow* window){
	for (auto& iterator : this->entities){
		window->draw(*iterator.second);
	}
}



EntityManager::~EntityManager(){
	for (auto& iterator : this->entities){
		delete iterator.second;
	}
	this->entities.clear();
}