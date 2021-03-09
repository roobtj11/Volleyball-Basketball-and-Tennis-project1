#include "Volleyball_Class.h"
#include <iostream>

V_Players::V_Players(std::string Player_Name, int Player_Number, std::string Position, 
	int Total_Kills, int Game_Kills, int Total_Hitting_Errors, int Game_Hitting_Errors, int Total_Assists, 
	int Game_Assists, int Total_Serves, int Game_Serves, int Total_Missed_Serves, int Game_Missed_Serves){
	this->Player_Name = Player_Name;
	this->Player_Number = Player_Number;
	this->Position = Position;
	this->Total_Kills = Total_Kills;
	this->Game_Kills = Game_Kills;
	this->Total_Hitting_Errors = Total_Hitting_Errors;
	this->Game_Hitting_Errors = Game_Hitting_Errors;
	this->Total_Assists = Total_Assists;
	this->Game_Assists = Game_Assists;
	this->Total_Serves = Total_Serves;
	this->Game_Serves = Game_Serves;
	this->Total_Missed_Serves = Total_Missed_Serves;
	this->Game_Missed_Serves = Game_Missed_Serves;
}
void V_Players::print_basic() {
	std::cout << Player_Name 
		<< "\t"
		<< Player_Number
		<< "\t"
		<< Position
		<< std::endl;
}
void V_Players::print_full () {
	std::cout << Player_Name
		<< "\t"
		<< Player_Number
		<< "\t"
		<< Position
		<< "\n\nTotal Kills:\t" <<Total_Kills
		<< "\nGame Kills:\t"  <<Game_Kills
		<< "\nTotal Hitting Errors:\t" <<Total_Hitting_Errors
		<< "\nGame Hitting Errors:\t"<<Game_Hitting_Errors
		<< "\nTotal Assists:\t"<<Total_Assists
		<< "\nGame Assists:\t"<<Game_Assists
		<< "\nTotal Serves:\t"<<Total_Serves
		<< "\nGame Serves:\t"<<Game_Serves
		<< "\nTotal Missed Serves:\t" <<Total_Missed_Serves
		<< "\nGame Missed Serves:\t"<<Game_Missed_Serves
		<< std::endl << std::endl << std::endl;
}

std::string V_Players::get_Player_Name()
{
	return Player_Name;
}

int V_Players::get_Player_Number()
{
	return Player_Number;
}

std::string V_Players::Get_Position()
{
	return Position;
}
int V_Players::get_Total_Kills() {
	return Total_Kills;
}
int V_Players::get_Game_Kills() {
	return Game_Kills;
}
int V_Players::get_Total_Hitting_Errors() {
	return Total_Hitting_Errors;
}
int V_Players::get_Game_Hitting_Errors() {
	return Game_Hitting_Errors;
}
int V_Players::get_Total_Assists() {
	return Total_Assists;
}
int V_Players::get_Game_Assists() {
	return Game_Assists;
}
int V_Players::get_Total_Serves() {
	return Total_Serves;
}
int V_Players::get_Game_Serves() {
	return Game_Serves;
}
int V_Players::get_Total_Missed_Serves() {
	return Total_Missed_Serves;
}
int V_Players::get_Game_Missed_Serves() {
	return Game_Missed_Serves;
}

void V_Players::add_Total_Kills()
{
	this->Total_Kills = this->Total_Kills++;
}

void V_Players::add_Game_Kills()
{
	this->Game_Kills = this->Game_Kills++;
}

void V_Players::add_Total_Hitting_Errors()
{
	this->Total_Hitting_Errors = this->Total_Hitting_Errors++;
}

void V_Players::add_Game_Hitting_Errors()
{
	this->Game_Hitting_Errors = this->Game_Hitting_Errors++;
}

void V_Players::add_Total_Assists()
{
	this->Total_Assists = this->Total_Assists++;
}

void V_Players::add_Game_Assists()
{
	this->Game_Assists = this->Game_Assists++;
}

void V_Players::add_Total_Serves()
{
	this->Total_Serves = this->Total_Serves++;
}

void V_Players::add_Game_Serves()
{
	this->Game_Serves = this->Game_Serves++;
}

void V_Players::add_Total_Missed_Serves()
{
	this->Total_Missed_Serves = this->Total_Missed_Serves++;
}

void V_Players::add_Game_Missed_Serves()
{
	this->Game_Missed_Serves = this->Game_Missed_Serves++;
}