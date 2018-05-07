#include "eye.h"
//Constructor
Eye::Eye(void):Card("Eye", 2, 100, 75){
};
//Virtual Render
string Eye::render(int line){
    
	switch(line){
        case 0: return ".___________.";
        case 1: return "|RollingEye |";
        case 2: return "|  o        |";
        case 3: return "|  \\_/\\o  |";
        case 4: return "|  (◔_◔)  |";
        case 5: return "|           |";
        case 6: return "|   100/75  |";
        case 7: return "|___________|";
        default:
        		return " ";
    }
}
