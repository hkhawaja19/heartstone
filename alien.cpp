#include "alien.h"
//Constructor
Alien::Alien(void):Card("Alien", 3, 200, 100){
};
//Virtual Render
string Alien::render(int line){
    
	switch(line){
        case 0: return ".___________.";
        case 1: return "|Alien      |";
        case 2: return "|  o        |";
        case 3: return "|  \\ _ /\\o|";
        case 4: return "|   ( Oo)   |";
        case 5: return "|   (_=-)   |";
        case 6: return "|  200/100  |";
        case 7: return "|___________|";
        default:
        		return " ";
    }
}
