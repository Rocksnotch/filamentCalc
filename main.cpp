#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

// Unloaded variables
std::string spoolBrand = "";
std::string spoolType = "";
double spoolCost = 0.0;
double spoolWeight = 0;

// Loaded variables
const double pla = 1.24;


void clear_screen()
{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

void header() {
    clear_screen();
    std::cout << "==========CSO Printer Calculator V0.1==========" << std::endl << std::endl;
}

void configCheck() {
    std::fstream cFile;
    cFile.open("config.dat");

    if (cFile)
    {
        std::cout << "Config found, loading config file." << std::endl;
    } else {
        std::cout << "Config not found, creating config file..." << std::endl;
        std::fstream wFile;
        wFile.open("config.dat",std::fstream::out);
        wFile << "";
        cFile.close();
        wFile.close();
        std::cout << "Done!\nPress 'Enter' to continue";
        std::cin.get();
        header();
    }
}

struct filament {
        
        std::string brand;
        std::string type;
        double cost;    
        double weight;

    } hold;

// Vector Setup
std::vector<filament> fil;

void configSave() {
    header();
    std::cout << "Saving config..." << std::endl;
    std::ofstream wFile;
    wFile.open("config.dat");

    int vecSize = 0;
    vecSize = fil.size();

    for (auto& a : fil) {
        wFile << a.brand << std::endl;
        wFile << a.type << std::endl;
        wFile << a.cost << std::endl;
        wFile << a.weight << std::endl;
    }

    wFile.close();
    std::cout << "Config saved!\nPress 'Enter' to continue" << std::endl;
    std::cin.get();
    header();
}

void configLoad() {
    header();
    std::cout << "Loading config..." << std::endl;
    std::ifstream rFile;
    rFile.open("config.dat");

    while (!rFile.eof()) {
        std::getline(rFile, hold.brand);
        std::getline(rFile, hold.type);
        rFile >> hold.cost;
        rFile >> hold.weight;

        fil.push_back(hold);        
    }

    rFile.close();
    std::cout << "Config loaded!\nPress 'Enter' to continue" << std::endl;
    std::cin.get();
    header();
}

int main() {
    header();
    configCheck();
/*
    struct filament test;
    test.brand = "testBrand";
    test.type = "pla";
    test.cost = 29.99;
    test.weight = 15;

    fil.push_back(test);
*/

    configLoad();

    std::cout << fil[0].brand << std::endl;
    std::cout << fil[0].type << std::endl;
    std::cout << fil[0].cost << std::endl;
    std::cout << fil[0].weight << std::endl;

    return 0;
}