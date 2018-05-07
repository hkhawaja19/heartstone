#include "bat.h"
//Constructor
Bat::Bat(void):Card("Bat", 1, 50, 50){
};
//Virtual Render
string Bat::render(int line){
    
	switch(line){
        case 0: return ".___________.";
        case 1: return "|Bat        |";
        case 2: return "|    mm     |";
        case 3: return "| /^(  )^\\|";
        case 4: return "| \\,(..),/|";
        case 5: return "|    V~~V   |";
        case 6: return "|   50/50 |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
