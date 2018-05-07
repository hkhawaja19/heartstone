#ifndef ROCK_H
#define ROCK_H

#include <iostream>
#include "card.h"

using namespace std;

class Rock : public Card {
    private:
    
    public:
    
    Rock(void);
    virtual string render(int);
};

#endif
