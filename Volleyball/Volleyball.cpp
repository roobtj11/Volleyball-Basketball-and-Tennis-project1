#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Volleyball.h"

void Visual_Court();

int Volleyball_Menu();

int main() {

	std::cout << "Welcome to the Volleyball section of our app!" << std::endl;

	if (Volleyball_Menu() == 1) {

	}
	else if (Volleyball_Menu() == 2) {

	}
	else if (Volleyball_Menu() == 3) {
		Visual_Court();
	}

	return 0;
}

int Volleyball_Menu() {
	std::cout
		<< "1.\tTeam Rosters" << std::endl
		<< "2.\tTournement Schedule" << std::endl
		<< "3.\tGame View" << std::endl
		<< "4.\tGame Recording" << std::endl
		<< "5.\tGame Transcript" << std::endl;
	std::string SelectionStr;
	std::getline(std::cin, SelectionStr);
	int Selection = std::stoi(SelectionStr);

	return Selection;
}

void Visual_Court() {
	std::string home, away;

	std::string Volleyball_Home_Names[Num_Per_Roster];
	std::string Volleyball_Home_Numbers[Num_Per_Roster];
	std::string Volleyball_Home_Positions[Num_Per_Roster];
	std::string Volleyball_Away_Names[Num_Per_Roster];
	std::string Volleyball_away_Numbers[Num_Per_Roster];
	std::string Volleyball_Away_Positions[Num_Per_Roster];
	std::string Home_Lineup[Num_Per_Side];
	std::string Away_Lineup[Num_Per_Side];

	Get_Teams(home, away);
	get_vball_rosters(home, away, Volleyball_Home_Names, Volleyball_Home_Numbers, Volleyball_Home_Positions, Volleyball_Away_Names, Volleyball_away_Numbers, Volleyball_Away_Positions);
	Starting_Lineups(home, away, Volleyball_Home_Names, Volleyball_Home_Numbers, Volleyball_Home_Positions, Volleyball_Away_Names, Volleyball_away_Numbers, Volleyball_Away_Positions, Home_Lineup, Away_Lineup);
	vball_visual(Home_Lineup, Away_Lineup);
}