#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


void get_bball_rosters(std::string home, std::string away, std::string Home_Names[], std::string Basketball_Home_Numbers[], std::string Basketball_Home_Positions[], std::string Basketball_Away_Names[], std::string Basketball_away_Numbers[], std::string Basketball_Away_Positions[]) {
	std::cout << "Reading home team roster... " << std::endl;
	try {
		read_data_from_file(home, Home_Names, Basketball_Home_Numbers, Basketball_Home_Positions);
		std::cout << "Success!" << std::endl;
	}
	catch (...) {
		std::cout << "Failed!" << std::endl;
		std::exit(1);
	}

	try {
		read_data_from_file(away, Basketball_Away_Names, Basketball_away_Numbers, Basketball_Away_Positions);
		std::cout << "Success!" << std::endl;
	}
	catch (...) {
		std::cout << "Failed!" << std::endl;
		std::exit(1);
	}

}

void read_data_from_file(std::string filename, std::string Names[], std::string Numbers[], std::string Positions[]) {

	std::string PATH;
	PATH = "Basketball\\Rosters\\" + filename + ".csv";
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