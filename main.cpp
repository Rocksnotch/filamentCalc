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
    std::cout << "==========CSO Printer Calculator V0.5==========" << std::endl << std::endl;
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
    wFile.open("config.dat", std::ofstream::trunc);

    int vecLength = fil.size();

    for (int i = 0; i < vecLength; i++) {
        wFile << fil[i].brand << std::endl;
        wFile << fil[i].type << std::endl;
        wFile << fil[i].cost << std::endl;
        wFile << fil[i].weight << std::endl;
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
    int tempCount = 0;

    while (rFile.good()) {
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

void configCheck() {
    std::fstream cFile;
    cFile.open("config.dat");

    if (cFile)
    {
        std::cout << "Config found, loading config file." << std::endl;
        configLoad();
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

void addFil() {
    header();
    std::cout << "Enter company brand: ";
    std::cin >> spoolBrand;
    std::cout << "Enter spool type (pla, abs, etc): ";
    std::cin >> spoolType;
    std::cout << "Enter spool cost (dollars w/o symbol): ";
    std::cin >> spoolCost;
    std::cout << "Enter spool weight (kg): ";
    std::cin >> spoolWeight;

    hold.brand = spoolBrand;
    hold.type = spoolType;
    hold.cost = spoolCost;
    hold.weight = spoolWeight;

    fil.push_back(hold);
}

int main() {
    //housekeeping
    header();
    fil.clear();
    configLoad();
    std::cout << "Pre-size: " << fil.size() << std::endl;
    addFil();
    std::cout << "Post-size: " << fil.size() << std::endl;

    std::cout << fil[0].brand << std::endl;
    std::cout << fil[0].type << std::endl;
    std::cout << fil[0].cost << std::endl;
    std::cout << fil[0].weight << std::endl;

    return 0;
}