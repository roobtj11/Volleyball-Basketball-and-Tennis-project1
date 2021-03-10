#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Volleyball_Class.h"
#include "Menus.h"



int Volleyball_Menu() {
	std::cout << "Welcome to the Volleyball section of our app!" << std::endl
		<< "Here are your sub topic options enter the reference number to go." << std::endl;
	std::cout
		<< "1.\tTeam Rosters" << std::endl
		<< "2.\tTournement Schedule" << std::endl
		<< "3.\tGame View" << std::endl
		<< ".\tReturn to MAIN MENU\nInput the refrence number to the section you want:\n";
	std::string SelectionStr;
	std::getline(std::cin, SelectionStr);
	int Selection = std::stoi(SelectionStr);

	if (Selection == 1) {
		Volleyball_Main();
	}
	else if (Selection == 2) {
		;
	}
	else if (Selection == 3) {

	}
	else if (Selection == 4) {
		main();
	}
	return 0;
}

