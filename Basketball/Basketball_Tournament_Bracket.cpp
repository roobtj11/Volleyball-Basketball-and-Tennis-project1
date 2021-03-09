#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Basketball.h"

void BBALL_bracket_generator(std::string BBALL_Participating_Teams[8])
{
	std::cout << BBALL_Participating_Teams[0] << "          " << BBALL_Participating_Teams[1] << std::endl;
	std::cout << "_____          _____" << std::endl;
	std::cout << "_____|--------|_____" << std::endl;
	std::cout << BBALL_Participating_Teams[2] << "          " << BBALL_Participating_Teams[3] << std::endl;
	std::cout << BBALL_Participating_Teams[4] << "          " << BBALL_Participating_Teams[5] << std::endl;
	std::cout << "_____          _____" << std::endl;
	std::cout << "_____|--------|_____" << std::endl;
	std::cout << BBALL_Participating_Teams[6] << "          " << BBALL_Participating_Teams[7] << std::endl;
}



void Basketball_Tournament()
{
	std::string BBALL_Participating_Teams[8];
	for (int i = 0; i < 8; i++)
	{
		std::string BBALL_Team;
		std::cout << "Please enter the " << i + 1 << " team entering the tournament(up to 8)" << std::endl;
		std::getline(std::cin, BBALL_Team);
		BBALL_Participating_Teams[i] = BBALL_Team;
	}
	BBALL_bracket_generator(BBALL_Participating_Teams);
}