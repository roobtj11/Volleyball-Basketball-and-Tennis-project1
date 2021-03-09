#pragma once
int main();
void Basketball_Tournament();
void get_bball_rosters(std::string home, std::string away, std::string Home_Names[], std::string Basketball_Home_Numbers[], std::string Basketball_Home_Positions[], std::string Basketball_Away_Names[], std::string Basketball_away_Numbers[], std::string Basketball_Away_Positions[]);
void read_data_from_file_bball(std::string filename, std::string Names[], std::string Numbers[], std::string Positions[]);
void BBALL_bracket_generator(std::string BBALL_Participating_Teams[8]);