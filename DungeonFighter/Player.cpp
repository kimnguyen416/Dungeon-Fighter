#include "Player.h"
#include "MainGame.h"
#include "GameState.h"
#include "Bullet.h"
#include "PlayerBullet.h"
#include "Enemy.h"

#include <iostream>
using namespace std;


//Basic properties of the Player class
Player::Player(EntityManager *entityManager, Map *map, float x, float y) {
	this->Load("ball1.png");
	this->setPosition(x, y);
	this->map = map;
	this->speed = .5f; //sets the player's speed
	this->groupId = 1; //the player's group id is 1.
	this->entityManager = entityManager;
	this->health = 5; // player's health

}




//Keeps track of the player's input throughout the game
bool Player::Update(sf::RenderWindow *window) {
	//Manages the positioning of the player's sprite when they press the right/left/up/down keys w/ relation to the set speed.
	this->velocity.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) * this->speed;
	this->velocity.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) * this->speed;

	//Sections below keeps track of the direction that the player is constantly facing
	if (this->velocity.x > 0) {
		if (this->velocity.y > 0) {
			this->direction = 45.0f;
		}
		else if (this->velocity.y < 0) {
			this->direction = 315.0f;
		}
		else {
			this->direction = 0.0f;
		}
	}

	else if (this->velocity.x < 0) {
		if (this->velocity.y > 0) {
			this->direction = 135.0f;
		}
		else if (this->velocity.y < 0) {
			this->direction = 225.0f;
		}
		else {
			this->direction = 180.0f;
		}
	}

	else {
		if (this->velocity.y > 0) {
			this->direction = 90.0f;
		}
		else if (this->velocity.y < 0) {
			this->direction = 270.0f;
		}
	}



	//Section that is in charge of knocking back the character once it hits an enemy

	this->velocity.x += this->damageknockback;

	if (abs(this->damageknockback) < 2.0f){
		this->damageknockback = 0.0f;
	}

	if (this->damageknockback > 0){
		this->damageknockback -= 8.0f;
	}

	else if (this->damageknockback < 0){
		this->damageknockback += 8.0f;
	}





	//The sections below keeps track of how the player moves from one area to the next when entering from one room to another.
	if (this->getPosition().y <= 0) {
		nextarea = map->toparea; //if they go to the top open area, they transition to the next area
		//sets the players position to the bottom when entering a new room
		startingx = this->getPosition().x;
		startingy = window->getSize().y - this->getGlobalBounds().height - 32; 
		corestate.SetState(new MainGame()); //recreate a new MainGame state since its a new area
		return false;
	}

	if (this->getPosition().y + this->getGlobalBounds().height >= window->getSize().y) {
		nextarea = map->bottomarea; //if they go to the bottom open area, they transition to the next area.
		//sets the players position to the top when entering a new room
		startingx = this->getPosition().x;
		startingy = 32;
		corestate.SetState(new MainGame());//recreate a new MainGame state since its a new area
		return false;
	}

	if (this->getPosition().x <= 0) {
		nextarea = map->leftarea;//if they go to the left open area, they transition to the next area.
		//sets the players position to the left when entering a new room
		startingx = window->getSize().x - this->getGlobalBounds().width - 32;
		startingy = window->getPosition().y + 200;
		corestate.SetState(new MainGame());//recreate a new MainGame state since its a new area
		return false;
	}


	if (this->getPosition().x + this->getGlobalBounds().width >= window->getSize().x) {
		nextarea = map->rightarea;//if they go to the right open area, they transition to the next area.
		//sets the players position to the right when entering a new room
		startingx = 32;
		startingy = window->getPosition().y + 200;
		corestate.SetState(new MainGame());//recreate a new MainGame state since its a new area
		return false;
	}




	//Creates the bullet for whenever the NPC speech is activated
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !this->spaceKey) {
		this->entityManager->Add("Bullet", new Bullet(this->map, this->getPosition().x, this->getPosition().y, direction, 32));

	}


	//Creates the player bullets and controls the direction and distance the bullet travels
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && !this->dKey) {
		this->entityManager->Add("pBullet", new PlayerBullet(this->map, this->getPosition().x, this->getPosition().y, direction, 800));

	}



	//The sections below makes sure that the tiles past 2 within the image file will have collision, while certain blocks below 2 do not have collision properties
	if (this->map->CheckCollision(this, LEFT) > 2) {
		this->move(-abs(this->speed), 0);
	}

	if (this->map->CheckCollision(this, RIGHT)>  2) {
		this->move(abs(this->speed), 0);
	}

	if (this->map->CheckCollision(this, UP)>  2) {
		this->move(0, abs(this->speed));
	}

	if (this->map->CheckCollision(this, DOWN)>  2) {
		this->move(0, -abs(this->speed));
	}



	//Serves as buffer whenever player talks to an npc or throws projectiles
	this->spaceKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
	this->dKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);

	//Updates 
	Entity::Update(window);

	return true;
}





//Keeps track of the player's collision itself
void Player::Collision(Entity *entity) {

	//Control of player collision with other entities witthin the game
	switch (entity->GroupID()) {
	//collision w/ npcs(since their groupid is 3
	case 3:
		this->move(-this->velocity.x, -this->velocity.y);
		break;
	//collision w/ enemies, since their groupid is 5
	case 5: 
		if (((Enemy*)entity)->Health() > 0) {

			//Sections below to determine how much the player will knockback from the enemy
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				this->velocity.x = 0;

				this->velocity.y = -58;

			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				this->velocity.x = this->damageknockback;

				this->velocity.y = 58;

			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
				this->velocity.x = -58;

				this->velocity.y = 0;

			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
				this->velocity.x = 58;

				this->velocity.y = 0;

			}


			
			//this->health -= ((Enemy*)entity)->Damage(); // for testing now

			this->health -= 1;
			this->move(-this->velocity.x , -this->velocity.y);

		}

		break;
	}


}



