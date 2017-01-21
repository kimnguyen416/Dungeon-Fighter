#pragma once

#include <iostream>
#include <fstream>
#include <string>

//Save system of the game
//*****CURRENTLY DOESNT WORK THOUGH.....

class SaveSystem{
public:
	SaveSystem(){
		std::ifstream input("test.sav");
		std::string temp;
		if (input)
		{
			input >> x >> y >> currentMap;
		}
		
		if (currentMap == "")
		{
			currentMap = "test.map";
			x = 1280 / 2;
			y = 768 / 2;
			this->Save();
		}
		
		input.close();
	}


	void Save()
	{
		std::ofstream output("test.sav");
		output << x  << " " << y  << " " << currentMap;
		output.close();
	}

	float x, y;
	std::string currentMap;
};