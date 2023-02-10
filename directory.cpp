#include "directory.hpp"

Commandterm::Commandterm(std::ofstream* fileToWrite) : DMV_FILE(fileToWrite){
    mainMenu();
}

Commandterm::~Commandterm(){
std::cout << "deconstructor called" << std::endl;
DMV_FILE->close();
delete DMV_FILE;

}

void Commandterm::mainMenu(){
std::cout << tableCreated << std::endl;
std::cout << foreignTableCreated << std::endl;
char choice;
bool check = true;
while (check ==true)
{
std::cout << "What would you like to do? \n (A) Create a table (B) Alter an existing table (C) Print table and close program " << std::endl;
std::cin >> choice;

switch (choice)
{
case 'A':
    setTable();
    break;
case 'B':
    alterTable();
case 'C':
    DMV_FILE->close();
    check = false;
default:
    break;
}
}

}

void Commandterm::setTable(){

    if(tableCreated == false || foreignTableCreated == false){
    std::cout << "What would you like to call this table?" << std::endl;
    
    if(tableCreated == false){

        std::cin >> Commandterm::tableName;
        std::stringstream table1;
        table1 << "CREATE TABLE " << Commandterm::tableName << ";";
        *DMV_FILE << table1.str();
        tableCreated = true;
        std::cout << tableCreated << std::endl;
        std::cout << foreignTableCreated << std::endl;
        mainMenu();

    }else if(foreignTableCreated == false)
        std::cin >> foreignTable;
        std::stringstream table2;
        table2 << "CREATE TABLE " << Commandterm::foreignTable << ";";
        *DMV_FILE << table2.str();
        foreignTableCreated = true;
        mainMenu();
    }

    else{std::cout << "table limit reached." << std::endl;}
}

void Commandterm::subAlterTable(std::string& tableAddy){


    char choice1;
    char choice2;
    char type;
    int length;
    std::string keyName;
    std::stringstream modification;

    std::cout << "How would you like to alter the table? \n" << "(A) Add Primary Key\n (B) Add INT\n (C) Add VARCHAR\n (D) Add Foreign Key\n (E) DROP Column\n" << std::endl;
    std::cin >> choice1;
    switch (choice1)
{
    case 'A':
        std::cout << "Adding primary key...\n";
        if (Commandterm::primaryKeyCheck == false){

            std::cout << "Is this a Primary Key of type INT or VARCHAR? Press A for INT and B for VARCHAR" << std::endl;

            std::cin>>choice2;

            switch (choice2)
            {
            case 'A': // add primary key addition
              { 
                std::cout << "What is the name of the Primary Key INT you'd like to add?" << std::endl;
                std::cin >> keyName;
                std::cout << "Length of the INT?" << std::endl;
                std::cin >> length;
                modification << "ALTER TABLE " << tableAddy << " ADD " << keyName << " INT(" << length << ");" << std::endl;
                *DMV_FILE << modification.str();
                Commandterm::primaryKeyCheck = true;
                modification.clear();
              }
                break;

            case 'B':
            {
                std::stringstream B;
                std::cout << "What is the name of VARCHAR you'd like to add?"<< std::endl;
                std::cin >> keyName;
                std::cout << "Length of the VARCAR?" << std::endl;
                std::cin >> length;
                modification << "ALTER TABLE " << tableAddy << " ADD " << keyName << " VARCHAR(" << length << ");" << std::endl;
                *DMV_FILE << modification.str();
                Commandterm::primaryKeyCheck = true;
                modification.clear();
            }
                break;
                
            default:
                std::cout << "invalid entry" << std::endl;
                break;
            }

        } else {std::cout << "Primary Key already established" << std::endl;}



        break;
    case 'B':

                std::cout << "Adding INT...\n";
                std::cout << "What is the name of the INT you'd like to add?" << std::endl;
                std::cin >> keyName;
                std::cout << "Length of the INT?" << std::endl;
                std::cin >> length;
                modification << "ALTER TABLE " << tableAddy << " ADD " << keyName << " INT(" << length << ");" << std::endl;
                *DMV_FILE << modification.str();
                modification.clear();
        break;

    case 'C':
                std::cout << "Adding VARCHAR...\n";
                std::cout << "What is the name of the VARCHAR you'd like to add?" << std::endl;
                std::cin >> keyName;
                std::cout << "Length of the VARCHAR?" << std::endl;
                std::cin >> length;
                modification << "ALTER TABLE " << tableAddy << " ADD " << keyName << " VARCHAR(" << length << ");" << std::endl;
                *DMV_FILE << modification.str();
                modification.clear();
        break;
    case 'D':
        std::cout << "Adding foreign key...\n";
                if (Commandterm::foreignKeyCheck == false){

            std::cout << "Is this a FOREIGN Key of type INT or VARCHAR? Press A for INT and B for VARCHAR" << std::endl;
            switch (choice2)
            {
            case 'A': // add FOREIGN key addition
                std::cout << "What is the name of the FOREIGN KEY INT you'd like to add?" << std::endl;
                std::cin >> keyName;
                std::cout << "Length of the INT?" << std::endl;
                std::cin >> length;
                modification << "ALTER TABLE "<< tableAddy << " ADD " << keyName << " INT(" << length << ");" << std::endl;
                *DMV_FILE << modification.str();
                modification.clear();
                Commandterm::foreignKeyCheck = true;
                break;
            case 'B':
                std::cout << "What is the name of the FOREIGN KEY VARCHAR you'd like to add?"<< std::endl;
                std::cin >> keyName;
                std::cout << "Length of the VARCAR?" << std::endl;
                std::cin >> length;
                modification << "ALTER TABLE " << tableAddy << " ADD " << keyName << " VARCHAR(" << length << ");" << std::endl;
                *DMV_FILE << modification.str();
                modification.clear();
                Commandterm::foreignKeyCheck = true;
                break;
            default:
                std::cout << "invalid entry" << std::endl;
                break;
            }

        } else {std::cout << "Foreign Key already established" << std::endl; mainMenu();}
        break;

    case 'E':
        std::cout << "Dropping column...\n";
        std::cout << "What column would you like to drop?" << "(A)" <<Commandterm::tableName << " or " << "(B)" <<Commandterm::foreignTable << std::endl;
        std::cin >>choice2;
        switch (choice2)
        { // figure out how to do this...
        case 'A':
            break;
        case 'B':
            break;
        
        default:
            break;
        }
        break;
    default:
        std::cout << "Invalid choice.\n";
        break;
}
}


void Commandterm::alterTable(){
char choice;
std::cout << "alter table called" << std::endl;

std::cout << tableCreated << std::endl;
std::cout << foreignTableCreated << std::endl;


 if (tableCreated == true && foreignTableCreated == false){
    std::cout << "funciton called, table name : " << tableName << std::endl;
    subAlterTable(tableName);

 }else if (tableCreated == true && foreignTableCreated == true){

    std::cout << "Which table would you like to alter? \n (A) " << tableName << " \n(B) " << foreignTable << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 'A':
        subAlterTable(tableName);
        break;
    case 'B':
        subAlterTable(foreignTable);
    default:
        std::cout << "invalid entry" << std::endl;
        break;
    }   
}

else{std::cout << "No table created" << std::endl; mainMenu();}
}



std::ofstream* openFile(const std::string& filename) {
    std::ifstream readfile(filename);
    if (readfile.good()) {
        char choice;
        std::cout << "File " << filename << " already exists." << std::endl;
        readfile.close();
        std::cout << "Enter 'D' if you would like to Delete the contents of this file, Enter 'A' if you would like to append the existing file with new data" << std::endl;
        std::cin >> choice;

        if (choice == 'D') {
            std::ofstream* replaceDMV = new std::ofstream(filename, std::ofstream::out | std::ofstream::trunc);
            std::cout << "The contents of " << filename << " have been deleted." << std::endl;
            return replaceDMV;
        } else if (choice == 'A') {
            std::ofstream* appendDMV = new std::ofstream(filename, std::ofstream::app);
            return appendDMV;
        } else {
            std::cout << "invalid entry" << std::endl;
            return nullptr;
        }
    } else {
        std::ofstream* newfile = new std::ofstream(filename);
        std::cout << "File: " << filename << " has been created!" << std::endl;
        return newfile;
    }
}