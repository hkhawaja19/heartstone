#ifndef PENGUIN_H
#define PENGUIN_H

#include <iostream>
#include "card.h"

using namespace std;

class Penguin : public Card {
    private:
    
    public:
    
    Penguin(void);
    virtual string render(int);
};

#endif
