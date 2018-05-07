#include "warrior.h"
//Constructor
Warrior::Warrior(void):Card("Warrior", 3, 200, 150){
};
//Virtual Render
string Warrior::render(int line){
    
	switch(line){
        case 0: return ".___________.";
        case 1: return "|Warrior    |";
        case 2: return "|=(W{=====- |";
        case 3: return "| ||(.--.)  |";
        case 4: return "| |\\_|**|_  |";
        case 5: return "| \\_'`--'_) |";
        case 6: return "|  200/150  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
