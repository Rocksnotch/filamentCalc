#include <iostream>
#include <stdlib.h>
#include <fstream>

// Unloaded variables
std::string spoolBrand = "";
std::string spoolType = "";
double spoolCost = 0.0;
int spoolWeight = 0;

// Loaded variables
const double pla = 1.24;
const double abs = 1.04;


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
        double cost;    

    };

int main() {
    header();
    configCheck();


    return 0;
}