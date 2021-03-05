#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "Basketball.h"





void bracket_generator(std::string Teams[8])
{
	std::cout << Teams[0] << "____                    ____" << Teams[1] << std::endl;
	std::cout << Teams[2] << "____|__              __|____" << Teams[3] << std::endl;
	std::cout << "           |-----------|          " << std::endl;
	std::cout << Teams[4] << "____ __              __ ____" << Teams[5] << std::endl;
	std::cout << Teams[6] << "____|                  |____" << Teams[7] << std::endl;

}



int Basketball_Tournament()
{
	std::string Participating_Teams[8];
	for (int i = 0; i < 8; i++)
	{
		std::string Team;
		std::cout << "Please enter the " << i + 1 << " team entering the tournament(up to 8)" << std::endl;
		std::getline(std::cin, Team);
		Participating_Teams[i] = Team;
	}
	bracket_generator(Participating_Teams);
	return 0;
}