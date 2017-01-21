#include "MainGame.h"
#include "MainMenu.h"
#include "GameOver.h"

#include "Map.h"
#include "Player.h"
#include "Enemy.h"



bool gameOver = false;
//SaveSystem saveSystem;

//starting position of the player sprite(
float startingx = 1280 / 2;
float startingy = 768 / 2;


//The current area is set to test.map, which is the first line of the file for the first area
std::string nextarea = "test.map";


void MainGame::Initialize(sf::RenderWindow* window){
	//Portion to set the main game image and the text that is going to print out onto the main game screen
	this->font = new sf::Font();
	this->font->loadFromFile("Graphics/other/bloodcrow.ttf");
	this->score = new Score(*font, 64U);
	this->lives = new Lives(*font, 64U);
	this->lives->setPosition(window->getSize().x  - this->lives->getGlobalBounds().width, 0);
	this->speech = new Speech(*font, 20U, window);

	this->pausedtext = new sf::Text("			Paused\nPress Escape to Quit", *font, 64U);
	this->pausedtext->setOrigin(this->pausedtext->getGlobalBounds().width / 2, this->pausedtext->getGlobalBounds().height / 2);
	this->pausedtext->setPosition(window->getSize().x / 2, window->getSize().y / 2);

	//serves as a buffer to the paused method
	this->paused = false;
	this->enterkey = true;


	//Loads in the map and the player
	manager = new EntityManager();

	map = new Map(manager);

	map->Load(nextarea, this->speech);

	this->manager->Add("Player", new Player(this-> manager,this-> map, startingx, startingy));


	/*
	//music here
	this->backgroundmusicbuffer = new sf::SoundBuffer();
	this->backgroundmusicbuffer->loadFromFile("Sounds/WolfBoss.ogg");
	this->backgroundmusic = new sf::Sound(*this->backgroundmusicbuffer);
	this->backgroundmusic->setLoop(true);
	this->backgroundmusic->play();
	*/

}


//In charge of updating the game state constantly
void MainGame::Update(sf::RenderWindow* window){
	//Updates the lives and score of the game
	this->lives->SetValue(((Player*)this->manager->Get("Player"))->health);
	//this->score->SetValue(((Player*)this->manager->Get("pBullet"))->scorevalue);



	//Sections below shows how if the player presses enter key, the screen pausees. The scores and lives will update alogn with this pause state.
		if (this->paused){
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterkey){
				this->paused = false;

			}
			//if the game is in a pause state, the player has the option to return back to the main menu screen
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
				corestate.SetState(new MainMenu());
				return;
			}
		}

		else if (this->speech->speaking) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterkey){
				this->speech->speaking = false;
			}
		}

		else{
			if (!this->manager->Update(window)) {
				return;
			}

			
			this->score->Update();
			this->lives->Update();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) && !this->enterkey){
				this->paused = true;
			
			}
	}

	
		//if the player's health is 0, switch the game state to the game over screen
		if (gameOver || this->lives->Value() <= 0) {
			gameOver = false;
			corestate.SetState(new GameOver());
			return;
		}
		
	
	this->enterkey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);

}


//Draws the map, score, and lives onto the screen as well as the speech.
void MainGame::Render(sf::RenderWindow* window){
	window->draw(*map);
	this->manager->Render(window);
	window->draw(*this->score);
	window->draw(*this->lives);
	this->speech->Render();

	if (this->paused){
		window->draw(*this->pausedtext);
	}
}


//Destroys the remaining variables that is no longer needed
void MainGame::Destroy(sf::RenderWindow* window){
	delete this->score;
	delete this->lives;
	delete this->pausedtext;
	delete this->font;

	delete this->manager;

	//this->backgroundmusic->stop();

	//delete this->backgroundmusic;
	//delete this->backgroundmusicbuffer;
}