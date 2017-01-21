#pragma once

#include <SFML/Graphics.hpp>

#include "SaveSystem.h"

//extern SaveSystem saveSystem;


//This is the core class that controls all of the game states and windows of the game. TinyState is constantly being inherited to the different states within the game
//with the same structure of initialize, update, render, and destroy.


class TinyState{
public:
	//Initiliaze is simply the method to declare whatever variables you need within a state and to define it right then and there in the .cpp file of the game state.
	virtual void Initialize(sf::RenderWindow* window){
	}

	//This method makes sure that the game is constantly being updated no matter which game state the game is currently in.
	virtual void Update(sf::RenderWindow* window){
	}

	//Draws whatever visuals that is needed to allow the player to see what is going on.
	virtual void Render(sf::RenderWindow* window){
	}

	//Destroys the unncessary variables that are no longer used once the game state is switched to another game state.
	virtual void Destroy(sf::RenderWindow* window){
	}
};


class GameState{
public:
	//Default constructor of the GameState
	GameState(){
		this->state = NULL;
	}

	//Just switches the window that is currently being displayed to a different window when needed
	void SetWindow(sf::RenderWindow* window){
		this->window = window;
	}

	//States: GameOver, MainGame, MainMenu, ControlsMenu. Switches to one of those whenever.
	void SetState(TinyState* state){
		//If statements below just makes sure that the window switches to one of those states safely

		if (this->state != NULL){
			this->state->Destroy(this->window);
		}
		//saveSystem.Save();

		this->state = state;

		if (this->state != NULL){
			this->state->Initialize(this->window);
		}
	}

	//Method to ensure that the game state is constantly being updated
	void Update(){
		if (this->state != NULL){
			this->state->Update(this->window);
		}
	}


	//Method that ensures that the game state draws out the needed visuals per window
	void Render(){
		if (this->state != NULL){
			this->state->Render(this->window);
		}
	}



	~GameState(){
		if (this->state != NULL){
			this->state->Destroy(this->window);
		}
	}


private:
	//Following variables needed to set the window and the state
	sf::RenderWindow* window;
	TinyState* state;
};

extern GameState corestate; //variable that represents the corestate<<so main state of the game as the game is constantly switched from one state to another
extern bool quitgame; //boolean needed to make sure if the game can be exited out safely