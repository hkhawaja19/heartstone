#include "rock.h"
//Constructor
Rock::Rock(void):Card("Rock", 2, 100, 75){
};
//Virtual Render
string Rock::render(int line){
    
	switch(line){
        case 0: return ".___________.";
        case 1: return "|Rock       |";
        case 2: return "|     __    |";
        case 3: return "|   _/  \\	|";
        case 4: return "|  / ^ ^ \\	|";
        case 5: return "| |_______| |";
        case 6: return "|   100/75  |";
        case 7: return "|___________|";
        default:
            return " ";
    }
}
