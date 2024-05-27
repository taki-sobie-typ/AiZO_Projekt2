#include <iostream>
#include "header/MainMenu.h"


int main() {
    MainMenu menu;
    char choiceMenu;

    do {
        menu.startMenu();
        std::cout << "Do you want to continue? (y/n): ";
        std::cin >> choiceMenu;

        std::cout << "\n=------------=\n";
    } while (choiceMenu == 'y' || choiceMenu == 'Y');

    return 0;
}
