#ifndef PHONEIX_H
#define PHONEIX_H

#include <iostream>
#include "card.h"

using namespace std;

class Phoneix : public Card {
    private:
    
    public:
    
    Phoneix(void);
    virtual string render(int);
};

#endif
