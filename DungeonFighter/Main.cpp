#include "GameState.h"
#include "MainMenu.h"

GameState corestate;
bool quitgame = false;

//Main.cpp represents the current window that the player is in


int main(){
	//sets the window size and name of thwe iwndow.
	sf::RenderWindow window(sf::VideoMode(1280, 768), "Dungeon Fighter");

	//Makes sure that the first thing that the player sees on the start up window is the main menu screen
	corestate.SetWindow(&window);
	corestate.SetState(new MainMenu());

	// run the program as long as the window is open
	while (window.isOpen()){
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)){
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		//Updates whatever is within the window, and renders them all onto the screen
		corestate.Update();
		corestate.Render();

		window.display();

		//If the player chooses to quit the game, safely closes the window
		if (quitgame){
			window.close();
		}

	}

	return 0;
}