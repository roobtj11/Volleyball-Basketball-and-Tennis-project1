#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

void Startup_Script() {
	std::cout << "               Welcome to the" << std::endl;
	std::cout << "               SPORTS MACHINE" << std::endl;
	std::cout << "     Made by: Tyler Roob and Jack Schnor" << std::endl;

	std::cout << "This program will let you, Keep track of team rosters for - Volleyball, Basketball, and Tennis\n ";
}

std::string Sport_Select(std::string sport) {
	std::cout << "Which sport would you like to access?" << std::endl;
	std::getline(std::cin, sport);

	return(sport);
}

void Menu_Direct(std::string choice)
{
	if (choice == "Basketball")
	{
		
	}
	else if (choice == "Volleyball")
	{

	}
	else if (choice == "Tennis")
	{

	}
}

int main() {
	Startup_Script();
	std::string selection = "empty";
	selection = Sport_Select(selection);
	std::cout << "you chose " << selection << std::endl;
	Menu_Direct(selection);
	return 0;
}