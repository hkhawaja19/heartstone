#include "dragon.h"
//Constructor
Dragon::Dragon(void):Card("Dragon", 3, 250, 150){
};
//Virtual Render
string Dragon::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Dragon     |";
        case 2: return "|           |";
        case 3: return "|   /\\_/\\	|";
        case 4: return "|  \\|6 6|/ |";
        case 5: return "| \\\\<'>// |";
        case 6: return "|   250/150 |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}


