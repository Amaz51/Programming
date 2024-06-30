#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Parchisi.h"
#include"Ludo.h"
#include"Display.h"



int main() {
    HWND wh = GetConsoleWindow();
    srand(static_cast<unsigned int>(time(0)));
    int pres;
    for (;;) {
        MoveWindow(wh, 300, 100, 600, 500, TRUE);
        startingdisplay();
        std::cin >> pres;
        switch (pres) {
        case 1: {
            Ludo myludo;
            break;
        }
        case 2: {
            Parchisi myLudo;
            break;
        }
        case 3: {
            MoveWindow(wh, 150, 100, 900, 500, TRUE);
            instruction();
            break;
        }
        case 4: {
            exit(0);
            break;
        }
        }
        system("CLS");
    }
}