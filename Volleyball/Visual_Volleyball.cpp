#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Volleyball.h"




void vball_visual(std::string Home_Lineup[], std::string Away_Lineup[]) {

	std::cout << " ____________________ " << std::endl;
	std::cout << "|      |      |      |" << std::endl;
	std::cout << "|  " << Home_Lineup[0] << "  |  " << Home_Lineup[5] << "  |  " << Home_Lineup[4] << "  |" << std::endl;
	std::cout << "|------|------|------|\t HOME" << std::endl;
	std::cout << "|  " << Home_Lineup[1] << "  |  " << Home_Lineup[2] << "  |  " << Home_Lineup[3] << "  |" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "|  " << Away_Lineup[3] << "  |  " << Away_Lineup[2] << "  |  " << Away_Lineup[1] << "  |" << std::endl;
	std::cout << "|------|------|------|\t AWAY" << std::endl;
	std::cout << "|  " << Away_Lineup[4] << "  |  " << Away_Lineup[5] << "  |  " << Away_Lineup[0] << "  |" << std::endl;
	std::cout << "|______|______|______|" << std::endl;
}



void Starting_Lineups(std::string home, std::string away, std::string Home_Names[], std::string Home_Numbers[], std::string Home_Positions[], std::string Away_Names[], std::string Away_Numbers[], std::string Away_Positions[], std::string Home_Lineup[], std::string Away_Lineup[]) {
	try {
		On_Court(home, Home_Names, Home_Numbers, Home_Positions, Home_Lineup);
		std::cout << "Success!" << std::endl;
	}
	catch (...) {
		std::cout << "Failed!" << std::endl;
		std::exit(2);
	}

	try {
		On_Court(away, Away_Names, Away_Numbers, Away_Positions, Away_Lineup);
		std::cout << "Success!" << std::endl;
	}
	catch (...) {
		std::cout << "Failed!" << std::endl;
		std::exit(2);
	}
}