#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

const int num_per_roster = 12;

const int vball_num_side = 6;
void vball_visual();
void Get_Teams(std::string&, std::string&);
void get_vball_rosters(std::string, std::string, std::string Volleyball_Home_Names[], std::string Volleyball_Home_Numbers[], std::string Volleyball_Home_Positions[], std::string Volleyball_Away_Names[],std::string Volleyball_away_Numbers[], std::string Volleyball_Away_Positions[]);

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
	while(std::getline(stream, line)){
		std::stringstream ss(line);
		std::string substr;
		
		//Read the name
		std::string name;
		std::getline(ss, name, ',');
		Names[i] = name;
		

		//Read the number
		std::getline(ss, substr, ',');
		int num = std::stoi(substr);
		if (num<10){ substr = "0" + std::to_string(num);}
		Numbers[i] = substr;
			

		//Read the position
		std::string position;
		std::getline(ss, position, ',');
		Positions[i] = position;

		std::cout << Names[i] << "\t" << Numbers[i] << "\t" << Positions[i] << std::endl;
		i++;
	}
	stream.close();
}

int main() {

	std::string home, away;

	std::string Volleyball_Home_Names[num_per_roster];
	std::string Volleyball_Home_Numbers[num_per_roster];
	std::string Volleyball_Home_Positions[num_per_roster];
	std::string Volleyball_Away_Names[num_per_roster];
	std::string Volleyball_away_Numbers[num_per_roster];
	std::string Volleyball_Away_Positions[num_per_roster];

	Get_Teams(home, away);
	get_vball_rosters(home, away, Volleyball_Home_Names, Volleyball_Home_Numbers, Volleyball_Home_Positions, Volleyball_Away_Names, Volleyball_away_Numbers, Volleyball_Away_Positions);
	vball_visual();


	std::cout << "press enter to end.";
	std::string end;
	std::getline(std::cin, end);

	return 0;
}

void Get_Teams(std::string& home, std::string& away) {
	std::cout << "What is the home team's name? (Input as seen on roster)" << std::endl;
	std::getline(std::cin, home);
	std::cout << "What is the away team's name? (Input as seen on roster)" << std::endl;
	std::getline(std::cin, away);
}

void vball_visual() {
	std::string hpos1 = "01";
	std::string hpos2 = "02";
	std::string hpos3 = "03";
	std::string hpos4 = "04";
	std::string hpos5 = "05";
	std::string hpos6 = "06";
	std::string opos1 = "01";
	std::string opos2 = "02";
	std::string opos3 = "03";
	std::string opos4 = "04";
	std::string opos5 = "05";
	std::string opos6 = "06";

	std::cout << " ____________________ " << std::endl;
	std::cout << "|      |      |      |" << std::endl;
	std::cout << "|  " << hpos1 << "  |  " << hpos6 << "  |  " << hpos5 << "  |" << std::endl;
	std::cout << "|------|------|------|" << std::endl;
	std::cout << "|  " << hpos2 << "  |  " << hpos3 << "  |  " << hpos4 << "  |" << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "|  " << opos4 << "  |  " << hpos3 << "  |  " << hpos2 << "  |" << std::endl;
	std::cout << "|------|------|------|" << std::endl;
	std::cout << "|  " << opos5 << "  |  " << hpos6 << "  |  " << hpos1 << "  |" << std::endl;
	std::cout << "|______|______|______|" << std::endl;
}

/*
			 ____________________
			|      |      |      |
			|  02  |  19  |  06  |
			|------|------|------|
			|  08  |  12  |  07  |
			======================
			|  99  |  13  |  02  |
			|------|------|------|
			|  12  |  04  |  03  |
			|______|______|______|
*/

void get_vball_rosters(std::string home, std::string away,std::string Home_Names[], std::string Volleyball_Home_Numbers[], std::string Volleyball_Home_Positions[], std::string Volleyball_Away_Names[], std::string Volleyball_away_Numbers[], std::string Volleyball_Away_Positions[]) {
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