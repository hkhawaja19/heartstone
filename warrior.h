#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include "card.h"

using namespace std;

class Warrior : public Card {
    private:
    
    public:
    
    Warrior(void);
    virtual string render(int);
};

#endif
