#include <iostream>
#include "Volleyball_Class.h"

const int Num_Teams = 8;
std::vector<V_Players> Teams[Num_Teams];
std::string Team_Names[Num_Teams];
std::string home, away;
int home_num, away_num;
const int Num_Side=6;
std::string Home_Lineup[Num_Side];
std::string Away_Lineup[Num_Side];
int home_score, away_score;
bool serving;

void Volleyball_Main() {
	Get_Team_Names();
	
	
	/*

	for (int t = 0; t < Num_Teams; t++) {
		std::cout << "Here is the Roster for " << Team_Names[t] << std::endl;
		for (int i = 0; i < Teams[t].size(); i++) {
			Teams[t][i].print_basic();
		}
		std::cout << std::endl << std::endl;
	}
	*/
	Volleyball_Tournament(Team_Names, Num_Teams);
	
	Start_Game();

	std::cout << "\t\tHere is the Roster for " << Team_Names[home_num] << std::endl << std::endl;
	for (int i = 0; i < Teams[home_num].size(); i++) {
		Teams[home_num][i].print_full();
	}
	std::cout << std::endl << std::endl << std::endl;

	std::cout << "\t\tHere is the Roster for " << Team_Names[away_num] << std::endl << std::endl;
	for (int i = 0; i < Teams[away_num].size(); i++) {
		Teams[away_num][i].print_full();
	}
}

void Get_Team_Names()
{
	std::cout << "Enter the name of each of the 8 teams that are playing?" << std::endl;
	for (int i = 0; i < Num_Teams; i++) {
		std::cout << "Team " << i+1 << ".\t";
		std::getline(std::cin, Team_Names[i]);
	}
	try {
		Store_Team_Info();
	}
	catch (...) {
		std::cout << "error";
		std::exit(123);
	}
}

void Store_Team_Info() {
	for (int i = 0; i < Num_Teams; i++) {
		std::string PATH;
		PATH = "Volleyball\\Volleyball_Rosters\\" + Team_Names[i] + ".csv";

		std::ifstream stream;
		stream.open(PATH);
		//Skip the first line
		std::string line;
		std::getline(stream, line);
		if (line == "") {
			std::cout << "PLEASE MAKE SURE TO ENTER THE TEAM NAMES CORRECTLY!" << std::endl;
			Get_Team_Names();
		}

		//Read every line in the file
		while (std::getline(stream, line)) { // this gets us the whole row
			std::stringstream ss(line);
			std::string substr;

			//get the Name
			std::string name;
			std::getline(ss, name, ',');
			//Get the Number
			std::getline(ss, substr, ',');
			int number = std::stoi(substr);

			//get the Position
			std::string position;
			std::getline(ss, position, ',');

			Teams[i].push_back(V_Players(name, number,position,0,0,0,0,0,0,0,0,0,0));
			number = NULL;
		}
		stream.close();
	}
}

void Start_Game()
{
	home_score = 0;
	away_score = 0;
	std::cout << "It's time for the game to begin! What 2 teams are playing, here are your options" << std::endl;
	get_teams();
	serving = get_serving();
	std::cout << serving;


	get_lineups();
	while (home_score != 25 && away_score != 25) {
		Visual_Court();
		Point_Play();
	}
	

}

void get_teams()
{
	for (int i = 0; i < Num_Teams; i++) {
		std::cout << Team_Names[i] << std::endl;
	}
	std::cout << "Who is the Home team?" << std::endl;
	home_num = 100;
	away_num = 100;

	std::getline(std::cin, home);

	for (int i = 0; i < Num_Teams; i++) {
		if (home == Team_Names[i]) {
			home_num = i;
		}
	}
	if (home_num == 100) {
		std::exit(12);
	}
	std::cout << "Who is the Away team?" << std::endl;
	std::getline(std::cin, away);

	for (int i = 0; i < Num_Teams; i++) {
		if (away == Team_Names[i]) {
			away_num = i;
		}
	}
	if (away_num == 100) {
		std::exit(13);
	}

	std::cout << "Home Team is team #" << home_num << ".\t" << home << "\nAway team is team #" << away_num << ".\t" << away << std::endl;
}

int get_serving()
{
begining:
	std::string serving_str;
	std::cout << "If the Home team is serving enter 0, if the Away team is serving enter 1" << std::endl;
	std::getline(std::cin, serving_str);
	int serving = std::stoi(serving_str);
	if (serving != 1 && serving != 0) {
		std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
		goto begining;
	}
	return serving;
}

void get_lineups() {
	std::cout << "Here is the Roster for " << Team_Names[home_num] << std::endl;
	for (int i = 0; i < Teams[home_num].size(); i++) {
		Teams[home_num][i].print_basic();
	}
	for (int i = 0; i < Num_Side; i++) {
		std::cout << "Who is in position " << i + 1 << "? Enter their number:\t";
		std::string number_str;
		std::getline(std::cin, number_str);
		int number = std::stoi(number_str);
		for (int p = 0; p < Teams[home_num].size(); p++) {
			if (Teams[home_num][p].get_Player_Number() == number) {
				if (number < 10) {
					Home_Lineup[i] = "0" + number_str;
				}
				else {
					Home_Lineup[i] = number_str;
				}
			}
		}
	}
	std::cout << "Here is the Roster for " << Team_Names[away_num] << std::endl;
	for (int i = 0; i < Teams[away_num].size(); i++) {
		Teams[away_num][i].print_basic();
	}
	for (int i = 0; i < Num_Side; i++) {
		std::cout << "Who is in position " << i + 1 << "? Enter their number:\t";
		std::string number_str;
		std::getline(std::cin, number_str);
		int number = std::stoi(number_str);
		for (int p = 0; p < Teams[away_num].size(); p++) {
			if (Teams[away_num][p].get_Player_Number() == number) {
				if (number < 10) {
					Away_Lineup[i] = "0" + number_str;
				}
				else {
					Away_Lineup[i] = number_str;
				}
				
			}
		}
	}
}

void Visual_Court() {

	std::cout << " ____________________ " << std::endl;
	std::cout << "|      |      |      |" << std::endl;
	std::cout << "|  " << Home_Lineup[0] << "  |  " << Home_Lineup[5] << "  |  " << Home_Lineup[4] << "  |" << std::endl;
	std::cout << "|------|------|------|\t" << home;
	if (!serving) { std::cout << "\tServing"; } std::cout << std::endl;
	std::cout << "|  " << Home_Lineup[1] << "  |  " << Home_Lineup[2] << "  |  " << Home_Lineup[3] << "  |"<< std::endl;
	std::cout << "======================" << "\t " << home << " "<<  home_score << "-" << away_score << " " <<away << std::endl;
	std::cout << "|  " << Away_Lineup[3] << "  |  " << Away_Lineup[2] << "  |  " << Away_Lineup[1] << "  |" << std::endl;
	std::cout << "|------|------|------|\t" << away;
	if (serving) { std::cout << "\tServing"; } std::cout << std::endl;
	std::cout << "|  " << Away_Lineup[4] << "  |  " << Away_Lineup[5] << "  |  " << Away_Lineup[0] << "  |" << std::endl;
	std::cout << "|______|______|______|" << std::endl;
}

void Point_Play() {
Checkpoint1:
	std::cout << "Was the Serve made? (Yes = 1, No = 0)" << std::endl;
	std::string serve_str;
	bool serve;
	try{
		std::getline(std::cin, serve_str);
		serve = std::stoi(serve_str);
	}
	catch (...) {
		std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
		goto Checkpoint1;
	}
	//HOME TEAM IS SERVING
	if (serving == 0) {
		if (serve) {
			for (int p = 0; p < Teams[home_num].size(); p++) {
				int a = std::stoi(Home_Lineup[1]);
				if (Teams[home_num][p].get_Player_Number() == a) {
					Teams[home_num][p].add_Game_Serves();
					Teams[home_num][p].add_Total_Serves();
					std::cout << Teams[home_num][p].get_Game_Serves() << std::endl;
				}
			}
			Point_Won_HS();
		}
			//GAME AFTER SERVE OCCURED
		else {
			Away_Team_Rotate();
			away_score++;
			for (int p = 0; p < Teams[home_num].size(); p++) {
				int a = std::stoi(Home_Lineup[1]);
				if (Teams[home_num][p].get_Player_Number() == a) {
					Teams[home_num][p].add_Game_Missed_Serves();
					Teams[home_num][p].add_Total_Missed_Serves();
					std::cout << Teams[home_num][p].get_Game_Serves() << std::endl;				
				}
			}
			serving = 1;
		}
	}
	//AWAY TEAM IS SERVING
	else if (serving == 1){
		if (serve) {
			for (int p = 0; p < Teams[away_num].size(); p++) {
				int a = std::stoi(Away_Lineup[1]);
				if (Teams[away_num][p].get_Player_Number() == a) {
					Teams[away_num][p].add_Game_Serves();
					Teams[away_num][p].add_Total_Serves();
					std::cout << Teams[away_num][p].get_Game_Serves() << std::endl;
				}
			}
			Point_Won_AS();
		}
		else {
			home_score++;
			serving = 0;
			Home_Team_Rotate();
			for (int p = 0; p < Teams[away_num].size(); p++) {
				int a = std::stoi(Away_Lineup[1]);
				if (Teams[away_num][p].get_Player_Number() == a) {
					Teams[away_num][p].add_Game_Missed_Serves();
					Teams[away_num][p].add_Total_Missed_Serves();
					std::cout << Teams[away_num][p].get_Game_Serves() << std::endl;
				}
			}
			
		}
	}

}

void Home_Team_Rotate()
{
	std::string temp1, temp2;
	temp1 = Home_Lineup[1];
	Home_Lineup[1] = Home_Lineup[0];
	temp2 = Home_Lineup[2];
	Home_Lineup[2] = temp1;
	temp1 = Home_Lineup[3];
	Home_Lineup[3] = temp2;
	temp2 = Home_Lineup[4];
	Home_Lineup[4] = temp1;
	temp1 = Home_Lineup[5];
	Home_Lineup[5] = temp2;
	Home_Lineup[0] = temp1;
}

void Away_Team_Rotate()
{
	std::string temp1, temp2;
	temp1 = Away_Lineup[1];
	Away_Lineup[1] = Away_Lineup[0];
	temp2 = Away_Lineup[2];
	Away_Lineup[2] = temp1;
	temp1 = Away_Lineup[3];
	Away_Lineup[3] = temp2;
	temp2 = Away_Lineup[4];
	Away_Lineup[4] = temp1;
	temp1 = Away_Lineup[5];
	Away_Lineup[5] = temp2;
	Away_Lineup[0] = temp1;
}

void Point_Won_HS() {
WhoWON:
	std::cout << "Did the Serving team win the point? (Yes = 1, No = 0)";
	std::string winner_str;
	bool winner;
	try {
		std::getline(std::cin, winner_str);
		winner = std::stoi(winner_str);
	}
	catch (...) {
		std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
		goto WhoWON;
	}
Kill_Or_Error1:
	if (winner) {
		home_score++;
		std::cout << "Was the point won by a Kill or an Error? (Kill = 1, Error = 0)" << std::endl;
		std::string KorE_str;
		bool KorE;
		try {
			std::getline(std::cin, KorE_str);
			KorE = std::stoi(KorE_str);
		}
		catch (...) {
			std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
			goto Kill_Or_Error1;
		}
	Kill1:
		if (KorE) {
			std::cout << "Enter the number of the player who had the kill.";
			std::string kill_str;
			int kill;
			try {
				std::getline(std::cin, kill_str);
				kill = std::stoi(kill_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto Kill1;
			}
			for (int p = 0; p < Teams[home_num].size(); p++) {
				if (Teams[home_num][p].get_Player_Number() == kill) {
					Teams[home_num][p].add_Game_Kills();
					Teams[home_num][p].add_Total_Kills();
				}
			}
			std::cout << "Enter the number of the player who had the assist.";
			std::string assist_str;
			int assist;
		Assist1:
			try {
				std::getline(std::cin, assist_str);
				assist = std::stoi(assist_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto Assist1;
			}
			for (int p = 0; p < Teams[home_num].size(); p++) {
				if (Teams[home_num][p].get_Player_Number() == assist) {
					Teams[home_num][p].add_Game_Assists();
					Teams[home_num][p].add_Total_Assists();
				}
			}
		}
		else {
		error1:
			std::cout << "(AWAY) Enter the number of the player who had the Error.";
			std::string error_str;
			int error;
			try {
				std::getline(std::cin, error_str);
				error = std::stoi(error_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto error1;
			}
			for (int p = 0; p < Teams[away_num].size(); p++) {
				if (Teams[away_num][p].get_Player_Number() == error) {
					Teams[away_num][p].add_Game_Hitting_Errors();
					Teams[away_num][p].add_Total_Hitting_Errors();
				}
			}
		}
	}
	else {
		away_score++;
		Away_Team_Rotate();
		serving = 1;
		std::cout << "Was the point won by a Kill or an Error? (Kill = 1, Error = 2)" << std::endl;
		std::string KorE_str;
		bool KorE;
		try {
			std::getline(std::cin, KorE_str);
			KorE = std::stoi(KorE_str);
		}
		catch (...) {
			std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
			goto Kill_Or_Error1;
		}
	Kill2:
		if (KorE) {
			std::cout << "Enter the number of the player who had the kill.";
			std::string kill_str;
			int kill;
			try {
				std::getline(std::cin, kill_str);
				kill = std::stoi(kill_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto Kill2;
			}
			for (int p = 0; p < Teams[away_num].size(); p++) {
				if (Teams[away_num][p].get_Player_Number() == kill) {
					Teams[away_num][p].add_Game_Kills();
					Teams[away_num][p].add_Total_Kills();
				}
			}
			std::cout << "Enter the number of the player who had the assist.";
			std::string assist_str;
			int assist;
		Assist2:
			try {
				std::getline(std::cin, assist_str);
				assist = std::stoi(assist_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto Assist2;
			}
			for (int p = 0; p < Teams[away_num].size(); p++) {
				if (Teams[away_num][p].get_Player_Number() == assist) {
					Teams[away_num][p].add_Game_Assists();
					Teams[away_num][p].add_Total_Assists();
				}
			}
		}
		else {
		error2:
			std::cout << "(Home) Enter the number of the player who had the Error.";
			std::string error_str;
			int error;
			try {
				std::getline(std::cin, error_str);
				error = std::stoi(error_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto error2;
			}
			for (int p = 0; p < Teams[home_num].size(); p++) {
				if (Teams[home_num][p].get_Player_Number() == error) {
					Teams[home_num][p].add_Game_Missed_Serves();
					Teams[home_num][p].add_Total_Hitting_Errors();
				}
			}
		}
	}
}

void Point_Won_AS() {
WhoWON:
	std::cout << "Did the Serving team win the point? (Yes = 1, No = 0)";
	std::string winner_str;
	bool winner;
	try {
		std::getline(std::cin, winner_str);
		winner = std::stoi(winner_str);
	}
	catch (...) {
		std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
		goto WhoWON;
	}
Kill_Or_Error1:
	if (winner) {
		away_score++;
		std::cout << "Was the point won by a Kill or an Error? (Kill = 1, Error = 0)" << std::endl;
		std::string KorE_str;
		bool KorE;
		try {
			std::getline(std::cin, KorE_str);
			KorE = std::stoi(KorE_str);
		}
		catch (...) {
			std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
			goto Kill_Or_Error1;
		}
	Kill1:
		if (KorE) {
			std::cout << "Enter the number of the player who had the kill.";
			std::string kill_str;
			int kill;
			try {
				std::getline(std::cin, kill_str);
				kill = std::stoi(kill_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto Kill1;
			}
			for (int p = 0; p < Teams[away_num].size(); p++) {
				if (Teams[away_num][p].get_Player_Number() == kill) {
					Teams[away_num][p].add_Game_Kills();
					Teams[away_num][p].add_Total_Kills();
				}
			}
			std::cout << "Enter the number of the player who had the assist.";
			std::string assist_str;
			int assist;
		Assist1:
			try {
				std::getline(std::cin, assist_str);
				assist = std::stoi(assist_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto Assist1;
			}
			for (int p = 0; p < Teams[away_num].size(); p++) {
				if (Teams[away_num][p].get_Player_Number() == assist) {
					Teams[away_num][p].add_Game_Assists();
					Teams[away_num][p].add_Total_Assists();
				}
			}
		}
		else {
		error1:
			std::cout << "(Home) Enter the number of the player who had the Error.";
			std::string error_str;
			int error;
			try {
				std::getline(std::cin, error_str);
				error = std::stoi(error_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto error1;
			}
			for (int p = 0; p < Teams[home_num].size(); p++) {
				if (Teams[home_num][p].get_Player_Number() == error) {
					Teams[home_num][p].add_Game_Hitting_Errors();
					Teams[home_num][p].add_Total_Hitting_Errors();
				}
			}
		}
	}
	else {
		home_score++;
		Home_Team_Rotate();
		serving = 0;
		std::cout << "Was the point won by a Kill or an Error? (Kill = 1, Error = 2)" << std::endl;
		std::string KorE_str;
		bool KorE;
		try {
			std::getline(std::cin, KorE_str);
			KorE = std::stoi(KorE_str);
		}
		catch (...) {
			std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
			goto Kill_Or_Error1;
		}
	Kill2:
		if (KorE) {
			std::cout << "Enter the number of the player who had the kill.";
			std::string kill_str;
			int kill;
			try {
				std::getline(std::cin, kill_str);
				kill = std::stoi(kill_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto Kill2;
			}
			for (int p = 0; p < Teams[home_num].size(); p++) {
				if (Teams[home_num][p].get_Player_Number() == kill) {
					Teams[home_num][p].add_Game_Kills();
					Teams[home_num][p].add_Total_Kills();
				}
			}
			std::cout << "Enter the number of the player who had the assist.";
			std::string assist_str;
			int assist;
		Assist2:
			try {
				std::getline(std::cin, assist_str);
				assist = std::stoi(assist_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto Assist2;
			}
			for (int p = 0; p < Teams[home_num].size(); p++) {
				if (Teams[home_num][p].get_Player_Number() == assist) {
					Teams[home_num][p].add_Game_Assists();
					Teams[home_num][p].add_Total_Assists();
				}
			}
		}
		else {
		error2:
			std::cout << "(Away) Enter the number of the player who had the Error.";
			std::string error_str;
			int error;
			try {
				std::getline(std::cin, error_str);
				error = std::stoi(error_str);
			}
			catch (...) {
				std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
				goto error2;
			}
			for (int p = 0; p < Teams[away_num].size(); p++) {
				if (Teams[away_num][p].get_Player_Number() == error) {
					Teams[away_num][p].add_Game_Missed_Serves();
					Teams[away_num][p].add_Total_Hitting_Errors();
				}
			}
		}
	}
}