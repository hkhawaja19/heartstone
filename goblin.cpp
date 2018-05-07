#include "goblin.h"
//Constructor
Goblin::Goblin(void):Card("Goblin", 1, 50, 50){
};
//Virtual Render
string Goblin::render(int line){
    
    switch(line){
        case 0: return ".___________.";
        case 1: return "|Goblin     |";
        case 2: return "|   ^___^   |";
        case 3: return "|  ( . . )  |";
        case 4: return "|     v     |";
        case 5: return "|           |";
        case 6: return "|  	50/50   |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
