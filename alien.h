#ifndef ALIEN_H
#define ALIEN_H

#include <iostream>
#include "card.h"

using namespace std;

class Alien : public Card {
    private:
    
    public:
    
    Alien(void);
    virtual string render(int);
};

#endif
