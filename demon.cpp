#include "demon.h"
//Constructor
Demon::Demon(void):Card("Demon", 2, 150, 75){
};
//Virtual Render
string Demon::render(int line){
    
	switch(line){
        case 0: return ".___________.";
        case 1: return "|Demon      |";
        case 2: return "|   (_ )  |";
        case 3: return "||||'',) ^|";
        case 4: return "|  \\/, \\( |";
        case 5: return "|   cXc_/_) |";
        case 6: return "|   150/75  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
