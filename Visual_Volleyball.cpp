#include <iostream>;
#include <string>;
const long int num_rows = 10;
const long int num_cols = 22;
const int vball_num_side = 6;

void vball_visual(std::string home_number[]);
void get_vball_home_roster(std::string vball_home_number_roster[]);

int main() {

	std::string volleyball_home_number_roster[vball_num_side];
	get_vball_home_roster(volleyball_home_number_roster);
	vball_visual(volleyball_home_number_roster);


	std::cout << "press enter to end.";
	std::string end;
	std::getline(std::cin, end);

	return 0;
}

void vball_visual(std::string volleyball_home_number_roster[]) {
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

void get_vball_home_roster(std::string vball_home_number_roster[]) {
	vball_home_number_roster[0] = "01";
	vball_home_number_roster[1] = "02";
	vball_home_number_roster[2] = "03";
	vball_home_number_roster[3] = "04";
	vball_home_number_roster[4] = "05";
	vball_home_number_roster[5] = "06";
}

void seperate_int() {
	std::cout << "Enter an integer " << std::endl;
	int number;
	number = 13;

	//convert the number into digits
	//lets say the number is 12345, of course this would require 5 variables, 

	int n1, n2;

	n1 = number % 10;
	number /= 10;
	n2 = number % 10;

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
}
