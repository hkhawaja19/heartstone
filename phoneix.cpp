#include "phoneix.h"
//Constructor
Phoneix::Phoneix(void):Card("Phoneix", 3, 150, 100){
};
//Virtual Render
string Phoneix::render(int line){
    
	switch(line){
        case 0: return ".___________.";
        case 1: return "|Phoneix    |";
        case 2: return "|   / '>    |";
        case 3: return "|-'(   )'-._|";
        case 4: return "|.=-\\ /-=.	|";
        case 5: return "|  |/-\\|   |";
        case 6: return "|  150/100  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
