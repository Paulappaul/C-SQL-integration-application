#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::ofstream* openFile(const std::string& filename);

class Commandterm {

public:

Commandterm(std::ofstream* fileToWrite);
~Commandterm();

void mainMenu();
void setTable();
void alterTable();
void subAlterTable(std::string& tableAddy);


private:
bool tableCreated = false;
bool foreignTableCreated = false;
bool primaryKeyCheck = false;
bool foreignKeyCheck = false;
std::string tableName; 
std::string foreignTable; 
std::ofstream* DMV_FILE;


};

