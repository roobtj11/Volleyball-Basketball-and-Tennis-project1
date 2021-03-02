#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Volleyball.h"




void Get_Teams(std::string& home, std::string& away) {
	std::cout << "What is the home team's name? (Input as seen on roster)" << std::endl;
	std::getline(std::cin, home);
	std::cout << "What is the away team's name? (Input as seen on roster)" << std::endl;
	std::getline(std::cin, away);
}

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

void get_vball_rosters(std::string home, std::string away, std::string Home_Names[], std::string Volleyball_Home_Numbers[], std::string Volleyball_Home_Positions[], std::string Volleyball_Away_Names[], std::string Volleyball_away_Numbers[], std::string Volleyball_Away_Positions[]) {
	std::cout << "Reading home team roster... " << std::endl;
	try {
		read_data_from_file(home, Home_Names, Volleyball_Home_Numbers, Volleyball_Home_Positions);
		std::cout << "Success!" << std::endl;
	}
	catch (...) {
		std::cout << "Failed!" << std::endl;
		std::exit(1);
	}

	try {
		read_data_from_file(away, Volleyball_Away_Names, Volleyball_away_Numbers, Volleyball_Away_Positions);
		std::cout << "Success!" << std::endl;
	}
	catch (...) {
		std::cout << "Failed!" << std::endl;
		std::exit(1);
	}

}

void read_data_from_file(std::string filename, std::string Names[], std::string Numbers[], std::string Positions[]) {

	std::string PATH;
	PATH = "Volleyball\\Rosters\\" + filename + ".csv";
	std::cout << PATH;
	std::ifstream stream;
	stream.open(PATH);

	//Skip the first line
	std::string line;
	std::getline(stream, line);
	std::cout << line << std::endl;

	int i = 0;

	//Read every line in the file
	while (std::getline(stream, line)) {
		std::stringstream ss(line);
		std::string substr;

		//Read the name
		std::string name;
		std::getline(ss, name, ',');
		Names[i] = name;


		//Read the number
		std::getline(ss, substr, ',');
		int num = std::stoi(substr);
		if (num < 10) { substr = "0" + std::to_string(num); }
		Numbers[i] = substr;


		//Read the position
		std::string position;
		std::getline(ss, position, ',');
		Positions[i] = position;

		i++;
	}
	stream.close();
}

void On_Court(std::string team, std::string Names[], std::string Numbers[], std::string Positions[], std::string Lineup[]) {
	std::cout << "Here is the roster for " << team << ":" << std::endl << std::endl;
	for (int i = 0; i < Num_Per_Roster; i++) {
		std::cout << Names[i] << "\t" << Numbers[i] << "\t" << Positions[i] << std::endl;
	}
	std::cout << std::endl << std::endl;

	for (int i = 0; i < Num_Per_Side; i++) {
		std::cout << "Who is in position " << i + 1 << "? Enter their number:\t";
		std::string number;
		std::getline(std::cin, number);
		for (int p = 0; p < Num_Per_Roster; p++) {
			if (Numbers[p] == number) {
				Lineup[i] = Numbers[p];
			}
		}
	}
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