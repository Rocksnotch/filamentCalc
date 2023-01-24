#include <iostream>
#include <stdlib.h>
#include <fstream>


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
        cFile << "";
        std::cout << "Done!\nPress 'Enter' to continue";
        std::cin.get();
        header();
    }
    
}

int main() {
    header();
    configCheck();


    return 0;
}