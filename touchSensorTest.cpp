#include <iostream>
#include "ev3dev.h"

int main(void) {
    ev3dev::touch_sensor button;

    while(true) {
        if(button.is_pressed()) std::cout << "Pressed!" << std::endl;
        else std::cout << "Not Pressed!" << std::endl;
    }
}