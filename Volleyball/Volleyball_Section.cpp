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
std::string serving;

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
	get_serving();
	std::cout << serving;


	get_lineups(home_num, Home_Lineup);
	get_lineups(away_num, Away_Lineup);
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

void get_serving()
{
	std::cout << "Who is serving first?" << std::endl;
	std::getline(std::cin, serving);
	if (home == serving || away == serving) {
		return;
	}
	else {
		std::cout << "ERROR! Enter one of the Team Names!" << std::endl;
		get_serving();
	}
}

void get_lineups(int team_num, std::string lineup[]) {
	std::cout << "Here is the Roster for " << Team_Names[team_num] << std::endl;
	for (int i = 0; i < Teams[team_num].size(); i++) {
		Teams[team_num][i].print_basic();
	}
	for (int i = 0; i < Num_Side; i++) {
		std::cout << "Who is in position " << i + 1 << "? Enter their number:\t";
		std::string number_str;
		std::getline(std::cin, number_str);
		int number = std::stoi(number_str);
		for (int p = 0; p < Teams[team_num].size(); p++) {
			if (Teams[team_num][p].get_Player_Number() == number) {
				if (number < 10) {
					lineup[i] = "0" + number_str;
				}
				else {
					lineup[i] = number_str;
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
	if (serving == home) { std::cout << "\tServing"; } std::cout << std::endl;
	std::cout << "|  " << Home_Lineup[1] << "  |  " << Home_Lineup[2] << "  |  " << Home_Lineup[3] << "  |"<< std::endl;
	std::cout << "======================" << "\t " << home << " "<<  home_score << "-" << away_score << " " <<away << std::endl;
	std::cout << "|  " << Away_Lineup[3] << "  |  " << Away_Lineup[2] << "  |  " << Away_Lineup[1] << "  |" << std::endl;
	std::cout << "|------|------|------|\t" << away;
	if (serving == away) { std::cout << "\tServing"; } std::cout << std::endl;
	std::cout << "|  " << Away_Lineup[4] << "  |  " << Away_Lineup[5] << "  |  " << Away_Lineup[0] << "  |" << std::endl;
	std::cout << "|______|______|______|" << std::endl;
}

bool get_serve() {
	std::cout << "Was the Serve made? (Yes = 1, No = 0)" << std::endl;
	std::string serve_str;
	bool serve;
	std::getline(std::cin, serve_str);
	try {
		serve = std::stoi(serve_str);
		if (serve != 1 || serve != 0) {
			Point_Play();
		}
	}
	catch (...) {
		std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
		Point_Play();
	}
	return serve;
}

void serve_event(int team_num, std::string Team_Lineup[],bool serve) {
	if (serve) {
		for (int p = 0; p < Teams[team_num].size(); p++) {
			int a = std::stoi(Team_Lineup[1]);
			if (Teams[team_num][p].get_Player_Number() == a) {
				Teams[team_num][p].add_Game_Serves();
				Teams[team_num][p].add_Total_Serves();
				std::cout << Teams[team_num][p].get_Game_Serves() << std::endl;
			}
		}
		Point_Winner();
	}
	else {
		for (int p = 0; p < Teams[team_num].size(); p++) {
			int a = std::stoi(Team_Lineup[1]);
			if (Teams[team_num][p].get_Player_Number() == a) {
				Teams[team_num][p].add_Game_Missed_Serves();
				Teams[team_num][p].add_Total_Missed_Serves();
				std::cout << Teams[team_num][p].get_Game_Serves() << std::endl;
			}
		}
		if (serving == home) {
			Team_Rotate(Away_Lineup);
			away_score++;
			serving = away;
		}
		else if (serving == away) {
			Team_Rotate(Home_Lineup);
			away_score++;
			serving == home;
		}	
	}
}

void Point_Play() {
	bool serve = get_serve();
	if (serving == home) {
		serve_event(home_num, Home_Lineup, serve);
	}
	else if (serving == away) {
		serve_event(away_num, Away_Lineup, serve);
	}
}

void Team_Rotate(std::string lineup[])
{
	std::string temp1, temp2;
	temp1 = lineup[1];
	lineup[1] = lineup[0];
	temp2 = lineup[2];
	lineup[2] = temp1;
	temp1 = lineup[3];
	lineup[3] = temp2;
	temp2 = lineup[4];
	lineup[4] = temp1;
	temp1 = lineup[5];
	lineup[5] = temp2;
	lineup[0] = temp1;
}

void killer(std::string Winner, int Winner_Num, std::string winning_lineup[]) {
	std::cout << "Enter the number of the player who had the kill.";
	std::string kill_str;
	int kill;
	try
	{
		std::getline(std::cin, kill_str);
		kill = std::stoi(kill_str);
	}
	catch (...)
	{
		std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
		killer(Winner, Winner_Num, winning_lineup);
	}
	std::cout << "Enter the number of the player who had the assist.";
	std::string assist_str;
	int assist;
	try
	{
		std::getline(std::cin, assist_str);
		assist = std::stoi(assist_str);
	}
	catch (...)
	{
		std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
		killer(Winner, Winner_Num, winning_lineup);
	}


	if (kill_str != winning_lineup[0] && kill_str != winning_lineup[1] && kill_str != winning_lineup[2] && kill_str != winning_lineup[3] && kill_str != winning_lineup[4] && kill_str != winning_lineup[5]) {
		std::cout << "The hitter is not on the court!" << std::endl;
		killer(Winner, Winner_Num, winning_lineup);
	}
	else {
		for (int p = 0; p < Teams[Winner_Num].size(); p++) {
			if (Teams[Winner_Num][p].get_Player_Number() == kill) {
				Teams[Winner_Num][p].add_Game_Kills();
				Teams[Winner_Num][p].add_Total_Kills();
			}
		}
	}
	if (assist_str != winning_lineup[0] && assist_str != winning_lineup[1] && assist_str != winning_lineup[2] && assist_str != winning_lineup[3] && assist_str != winning_lineup[4] && assist_str != winning_lineup[5]) {
		std::cout << "The setter is not on the court!" << std::endl;
		killer(Winner, Winner_Num, winning_lineup);
	}
	else {
		for (int p = 0; p < Teams[home_num].size(); p++) {
			if (Teams[Winner_Num][p].get_Player_Number() == assist) {
				Teams[Winner_Num][p].add_Game_Assists();
				Teams[Winner_Num][p].add_Total_Assists();
			}
		}
	}
}

void error_maker(std::string Loser, int Loser_num, std::string losing_lineup[]) {
	std::cout << "(AWAY) Enter the number of the player who had the Error.";
	std::string error_str;
	int error;
	try {
		std::getline(std::cin, error_str);
		error = std::stoi(error_str);
	}
	catch (...) {
		std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
		error_maker(Loser, Loser_num, losing_lineup);
	}
	if (error_str != losing_lineup[0] && error_str != losing_lineup[1] && error_str != losing_lineup[2] && error_str != losing_lineup[3] && error_str != losing_lineup[4] && error_str != losing_lineup[5]) {
		std::cout << "That person is not on the court!" << std::endl;
		error_maker(Loser, Loser_num, losing_lineup);
	for (int p = 0; p < Teams[Loser_num].size(); p++) {
		if (Teams[Loser_num][p].get_Player_Number() == error) {
			Teams[Loser_num][p].add_Game_Hitting_Errors();
			Teams[Loser_num][p].add_Total_Hitting_Errors();
		}
	}
}

	void kill_or_error(std::string Winner, int Winner_Num,std::string winning_lineup[], std::string Loser, int Loser_num, std::string losing_lineup[]){
		std::cout << "Was the point won by a Kill or an Error? (Kill = 1, Error = 0)" << std::endl;
		std::string KorE_str;
		bool KorE;
		try {
			std::cin >> KorE;
		}
		catch (...) {
			std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
			kill_or_error(Winner, Winner_Num, winning_lineup, Loser, Loser_num, losing_lineup);
		}
		if (KorE) {
			killer(Winner, Winner_Num, winning_lineup);
		}
		else {
			error_maker(Loser, Loser_num, losing_lineup);
		}
}

void Point_Winner() {
	std::cout << "Did the Serving team win the point? (Yes = 1, No = 0)";
	bool winner;
	try{
		std::cin >> winner;
	}
	catch (...) {
		std::cout << "ERROR PLEASE ENTER AN ACCEPTED VALUE!" << std::endl;
		Point_Winner();
	}
	if (serving == home) {
		if (winner) {
			kill_or_error(home, home_num,Home_Lineup, away, away_num,Away_Lineup);
			home_score++;
		}
		else {
			kill_or_error(away,away_num, Away_Lineup, home,home_num, Home_Lineup);
			away_score++;
			Team_Rotate(Away_Lineup);
			serving = away;
		}
	}
	else {
		if (winner) {
			kill_or_error(away, away_num, Away_Lineup, home, home_num, Home_Lineup);
			away_score++;
		}
		else {
			kill_or_error(home, home_num, Home_Lineup, away, away_num, Away_Lineup);
			home_score++;
			Team_Rotate(Home_Lineup);
			serving = home;
		}
	}
}
