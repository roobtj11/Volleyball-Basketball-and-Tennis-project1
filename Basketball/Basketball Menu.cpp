#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Basketball.h"

int Basketball_Menu() {
	std::cout << "Welcome to the Basketball section of our app!" << std::endl
		<< "Here are your sub topic options enter the reference number to go." << std::endl;
	std::cout
		<< "1.\tTeam Rosters" << std::endl
		<< "2.\tTournement Schedule" << std::endl
		<< "3.\tGame View" << std::endl
		<< "4.\tGame Recording" << std::endl
		<< "5.\tGame Transcript" << std::endl
		<< "6.\tReturn to MAIN MENU\nInput the refrence number to the section you want:\n";
	std::string SelectionStr;
	std::getline(std::cin, SelectionStr);
	int Selection = std::stoi(SelectionStr);

	if (Selection == 1) {
		
	}
	else if (Selection == 2) {
		Basketball_Tournament();
	}
	else if (Selection == 3) {
		
	}
	else if (Selection == 4) {

	}
	else if (Selection == 5) {
		
	}
	else if (Selection == 6) {
		main();
	}
	return 0;
}