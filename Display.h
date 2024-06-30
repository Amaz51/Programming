#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>

#define RED "\u001B[31m"
#define RESET "\u001B[0m"
#define GREEN "\u001B[32m"
#define YELLOW "\u001B[33m"
#define YELLOW_BRIGHT "\033[093m"
#define CYAN "\u001B[36m"
#define BLUE "\u001B[34m"
#define RESET "\u001B[0m"
#define PURPLE "\033[1;35m"
#define STOP_UNDERLINE "\u001B[24m"
#define UNDERLINE "\u001B[4m"

void startingdisplay() {
    std::cout << std::endl << std::endl;
    std::cout << BLUE << "        __________________________________________________________" << std::endl;
    std::cout << "       |" << CYAN << "     __           " << GREEN << "   __         " << RED << "______       " << YELLOW << "             " << BLUE << "|" << std::endl;
    std::cout << "       |" << CYAN << "    / /   __  __" << GREEN << "____/ /___     " << RED << "/ ____/___ _" << YELLOW << "____ ___  ___  " << BLUE << "|" << std::endl;
    std::cout << "       |" << CYAN << "   / /   / / / /" << GREEN << " __  / __ \\  " << RED << " / / __/ __ `/" << YELLOW << " __ `__ \\/ _ \\ " << BLUE << "|" << std::endl;
    std::cout << "       |" << CYAN << "  / /___/ /_/ /" << GREEN << " /_/ / /_/ /  " << RED << "/ /_/ / /_/ / " << YELLOW << "/ / / / /  __/ " << BLUE << "|" << std::endl;
    std::cout << "       |" << CYAN << " /_____/\\____/" << GREEN << "\\____/\\____/" << RED << "   \\____/\\__,_/" << YELLOW << "_/ /_/ /_/\\___/  " << BLUE << "|" << std::endl;
    std::cout << "       |__________________________________________________________|" << RESET << std::endl;
    std::cout << YELLOW << "                                                    " << UNDERLINE << "By Ehan & Amaz" << RESET << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << CYAN << "             Two players games : " << RESET << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << CYAN << "                              1.  " << YELLOW_BRIGHT << "     BASIC LUDO" << RESET << std::endl << std::endl;
    std::cout << CYAN << "                              2. " << YELLOW_BRIGHT << "      LUDO SPANISH VARIANT" << RESET << std::endl << std::endl;
    std::cout << CYAN << "                              3.   " << YELLOW_BRIGHT << "    INSTRUCTIONS" << RESET << std::endl << std::endl;
    std::cout << CYAN << "                              4.   " << YELLOW_BRIGHT << "    EXIT" << RESET << std::endl << std::endl << std::endl;

    std::cout << YELLOW << "         Press the buttons as mentioned for the display: " << RESET << std::endl << std::endl;
}
void instruction() {
    system("cls");
    std::cout << std::endl << std::endl << YELLOW << "            RULES FOR BASIC LUDO" << RESET << std::endl << std::endl;

    std::cout << GREEN << "  1:  " << RESET << "You get another roll once if you roll six" << std::endl;
    std::cout << GREEN << "  2:  " << RESET << "Both rolls(if 2) will be implemented on the same token" << std::endl;
    std::cout << GREEN << "  3:  " << RESET << "If you roll 6 any token inside can come out if possible" << std::endl;
    std::cout << GREEN << "  4:  " << RESET << "If you land on your opponent's token, it will return to home." << std::endl;
    std::cout << GREEN << "  5:  " << RESET << "Only 1 token can occupy any normal spot." << std::endl;
    std::cout << GREEN << "  6:  " << RESET << "For safe point, a maximum of two tokens can occupy it." << std::endl;
    std::cout << GREEN << "  7:  " << RESET << "If the two spots are occupied, no token can land at that spot." << std::endl;
    std::cout << GREEN << "  8:  " << RESET << "If all 4 tokens of any player reaches the end, the player wins." << std::endl << RESET;

    std::cout << std::endl << std::endl << YELLOW << "            RULES FOR PARCHISI" << RESET << std::endl << std::endl;

    std::cout << GREEN << "  1:  " << RESET << "If you roll 5 any token inside home will automatically come out if possible" << std::endl;
    std::cout << GREEN << "  2:  " << RESET << "If you land on your opponent's token, it will return to home." << std::endl;
    std::cout << GREEN << "  3:  " << RESET << "Two tokens (of same color) can come at the same spot for any normal spot." << std::endl;
    std::cout << GREEN << "  4:  " << RESET << "For safe point, a maximum of two tokens can occupy it." << std::endl;
    std::cout << GREEN << "  5:  " << RESET << "If the two spots are occupied, a blokade is formed and no token behind can cross or land at that spot." << std::endl;
    std::cout << GREEN << "  6:  " << RESET << "If you roll double, any blockade (if present) will be automatically broken." << std::endl;
    std::cout << GREEN << "  7:  " << RESET << "You will get another roll if you get doubles or bop opponent's token or your token reaches end." << std::endl;
    std::cout << GREEN << "  8:  " << RESET << "If all 4 tokens of any player reaches the end, the player wins." << std::endl;

    std::cout << std::endl << std::endl << RED << "Press any key to return back to main menu" << RESET;
    _getch();

}
