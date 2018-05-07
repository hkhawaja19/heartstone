#ifndef EYE_H
#define EYE_H

#include <iostream>
#include "card.h"

using namespace std;

class Eye : public Card {
    private:
    
    public:
    
    Eye(void);
    virtual string render(int);
};

#endif
