#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int main();
void Volleyball_Main();

class V_Players{
	std::string Player_Name;
	int Player_Number;
	std::string Position;
	int Total_Kills;
	int Game_Kills;
	int Total_Hitting_Errors;
	int Game_Hitting_Errors;
	int Total_Assists;
	int Game_Assists;
	int Total_Serves;
	int Game_Serves;
	int Total_Aces;
	int Game_Aces;
	int Total_Missed_Serves;
	int Game_Missed_Serves;
public:
	V_Players(std::string Player_Name, int Player_Number,
		std::string Position, int Total_Kills, int Game_Kills, int Total_Hitting_Errors,
		int Game_Hitting_Errors, int Total_Assists, int Game_Assists, int Total_Serves,
		int Game_Serves, int Total_Missed_Serves, int Game_Missed_Serves);

	void print_basic();
	void print_full();

	//Encapsulation
	//Getter & Setter
	//getter
	std::string get_Player_Name();
	int get_Player_Number();
	std::string Get_Position();
	int get_Total_Kills();
	int get_Game_Kills();
	int get_Total_Hitting_Errors();
	int get_Game_Hitting_Errors();
	int get_Total_Assists();
	int get_Game_Assists();
	int get_Total_Serves();
	int get_Game_Serves();

	int get_Total_Missed_Serves();
	int get_Game_Missed_Serves();
	
	void add_Total_Kills();
	void add_Game_Kills();
	void add_Total_Hitting_Errors();
	void add_Game_Hitting_Errors();
	void add_Total_Assists();
	void add_Game_Assists();
	void add_Total_Serves();
	void add_Game_Serves();

	void add_Total_Missed_Serves();
	void add_Game_Missed_Serves();
};


void Get_Rosters(std::string);

void bracket_generator(std::string Team_Names[]);

void Volleyball_Tournament(std::string Team_Names[], int Num_Teams);

void Get_Team_Names();

void Store_Team_Info();

void Start_Game();

void get_teams();

void get_serving();

void get_lineups(int, std::string Home_Lineup[]);

void Visual_Court();

void Point_Play();

void Team_Rotate(std::string lineup[]);

void kill_or_error(std::string, int, std::string winning_lineup[], std::string, int, std::string losing_lineup[]);

void killer(std::string Winner, int Winner_Num, std::string winning_lineup[]);

void Point_Winner();