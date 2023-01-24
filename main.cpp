#include <iostream>
#include <stdlib.h>

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
    std::cout << "==========CSO Printer Calculator V0.1==========" << std::endl << std::endl << std::endl;
}

int main() {
    header();
    return 0;
}