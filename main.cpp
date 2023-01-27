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
std::string temp;

// Loaded variables (material density)
const double pla = 1.24;
const double abS = 1.04;
const double petg = 1.27;


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
    std::cout << "==========CSO Printer Calculator V0.7==========" << std::endl << std::endl;
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

    wFile << fil.size() << std::endl;

    for (int i = 0; i < fil.size(); i++) {
        wFile << fil[i].brand << std::endl;
        wFile << fil[i].type << std::endl;
        wFile << fil[i].cost << std:: endl;
        wFile << fil[i].weight << std::endl;
    }
    wFile.close();

    std::cout << "Config saved!\nPress 'Enter' to continue";
    std::cin.ignore(INT_MAX, '\n');
    std::cin.get();

}

void configLoad() {
    header();
    std::ifstream rFile;
    rFile.open("config.dat");
    int vecSize = 0;

    rFile >> vecSize;


    while (vecSize != 0) {
        rFile >> hold.brand;
        rFile >> hold.type;
        rFile >> hold.cost;
        rFile >> hold.weight;

        fil.push_back(hold);
        vecSize--;
        }
    rFile.close();
    std::cout << "Config loaded!\nPress 'Enter' to continue";
    std::cin.get();
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
        std::cin.ignore(INT_MAX, '\n');
        std::cin.get();
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
    configSave();
}

void viewFil() {
    header();

    for (int k = 0; k < fil.size(); k++) {
    std::cout << "--Filament " << k + 1 << "--" << std::endl;
    std::cout << "Brand: " << fil[k].brand << std::endl;
    std::cout << "Filament Type: " << fil[k].type << std::endl;
    std::cout << "Spool Cost: $" << fil[k].cost << std::endl;
    std::cout << "Spool weight: " << fil[k].weight << " kg" << std::endl << std::endl; 
    }

    std::cout << "Press 'Enter' to continue";
    std::cin.ignore(INT_MAX, '\n');
    std::cin.get();
}

int main() {
    //Housekeeping (variables, etc)
    int choice = 0;
    int temp = 0;

    //Start of program
    header();
    configCheck();
    while (choice != -1) {
    header();
    std::cout << "---MAIN MENU---" << std::endl;
    std::cout << "1) View filaments on file" << std::endl;
    std::cout << "2) Add filament to file" << std::endl;
    std::cout << "3) Price calculator" << std::endl;
    std::cout << "4) Remove filament" << std::endl;
    std::cout << "0) Exit Program" << std::endl << std::endl;
    std::cout << "Enter Choice Number: ";
    std::cin >> choice;

    if (std::cin.fail()) { //catch if user enters another other than an int
        std::cin.clear();
        std::cout << "Please only enter numbers, not other characters!\nPress 'Enter' to continue";
            std::cin.ignore(INT_MAX, '\n');
            std::cin.get();
    } else {

    switch (choice) {
        case 1:
            viewFil();
            break;
        case 2:
            addFil();
            break;
        case 3:

            break;
        case 4:
            viewFil();
            std::cout << "Enter filament to remove (number): ";
            std::cin >> temp;
            if (temp == 1) {
                fil.erase(fil.begin());
            } else {

            fil.erase(fil.begin() + (temp - 1));
            }

            break;
        case 0:
            return 0;
            break;
        default:
            std::cout << "Choice not found, try again!\nPress 'Enter' to continue";
            std::cin.ignore(INT_MAX, '\n');
            std::cin.get();
            break;
    }
    }
    }

    return 0;
}