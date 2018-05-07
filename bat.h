#ifndef BAT_H
#define BAT_H

#include <iostream>
#include "card.h"

using namespace std;

class Bat : public Card {
    private:
    
    public:
    
    Bat(void);
    virtual string render(int);
};

#endif
