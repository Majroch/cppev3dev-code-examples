#include <iostream>
#include "ev3dev.h"
#include <unistd.h>

/**
  * Returns:
  * U - Up
  * D - Down
  * L - Left
  * R - Right
  * B - Back
  * E - Enter
  */
char getch() {
    ev3dev::button up(ev3dev::button::up);
    ev3dev::button down(ev3dev::button::down);
    ev3dev::button left(ev3dev::button::left);
    ev3dev::button right(ev3dev::button::right);
    ev3dev::button back(ev3dev::button::back);
    ev3dev::button enter(ev3dev::button::enter);
    while(true) {
        if(up.pressed()) return 'U';
        if(down.pressed()) return 'D';
        if(left.pressed()) return 'L';
        if(right.pressed()) return 'R';
        if(back.pressed()) return 'B';
        if(enter.pressed()) return 'E';
    }
}

void clear() {
    system("clear");
}

int main(void) {
    int selected = 0;
    while(true) {
        std::cout << "-----------------------------" << std::endl;
        std::cout << "|           MENU            |" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        if(selected == 0) std::cout << "Option 0" << " <<" << std::endl;
        else std::cout << "Option 0" << std::endl;

        if(selected == 1) std::cout << "Option 1" << " <<" << std::endl;
        else std::cout << "Option 1" << std::endl;

        if(selected == 2) std::cout << "Option 2" << " <<" << std::endl;
        else std::cout << "Option 2" << std::endl;

        // LOGIC

        switch(getch()) {
            case 'U':
                if(selected <= 0) selected = 2;
                else selected--;
                break;
            case 'D':
                if(selected >= 2) selected = 0;
                else selected++;
                break;
            case 'B':
                return 0;
                break;
        }

        sleep(1);
        clear();
    }
}