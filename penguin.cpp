#include "penguin.h"
//Constructor
Penguin::Penguin(void):Card("Penguin", 2, 100, 50){
};
//Virtual Render
string Penguin::render(int line){
    
	switch(line){
        case 0: return ".___________.";
        case 1: return "|Penguin    |";
        case 2: return "|   ___     |";
        case 3: return "|  (  ->    |";
        case 4: return "|  /) \\     |";
        case 5: return "|   - -     |";
        case 6: return "|  100/50   |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
