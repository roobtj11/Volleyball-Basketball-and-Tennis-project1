const int Num_Per_Roster = 12;
const int Num_Per_Side = 6;

int main();
void Get_Teams(std::string&, std::string&);
void get_vball_rosters(std::string, std::string, std::string Volleyball_Home_Names[], std::string Volleyball_Home_Numbers[], std::string Volleyball_Home_Positions[], std::string Volleyball_Away_Names[], std::string Volleyball_away_Numbers[], std::string Volleyball_Away_Positions[]);
void vball_visual(std::string Home_Lineup[], std::string Away_Lineup[]);
void read_data_from_file(std::string filename, std::string Names[], std::string Numbers[], std::string Positions[]);
void On_Court(std::string, std::string Names[], std::string Numbers[], std::string Positions[], std::string Lineup[]);
void Starting_Lineups(std::string, std::string, std::string Home_Names[], std::string Home_Numbers[], std::string Home_Positions[], std::string Away_Names[], std::string Away_Numbers[], std::string Away_Positions[], std::string Home_Lineup[], std::string Away_Lineup[]);

void Live_Volleyball_Game();