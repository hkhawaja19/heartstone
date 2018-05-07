#ifndef DEMON_H
#define DEMON_H

#include <iostream>
#include "card.h"

using namespace std;

class Demon : public Card {
    private:
    
    public:
    
    Demon(void);
    virtual string render(int);
};

#endif
