#ifndef KOMPONENTENLIST_H
#define KOMPONENTENLIST_H

#include "komponentenelement.h"

class KomponentenList
{   
    private:
        int counter;
        KomponentenElement* first;
        KomponentenElement* getElement(int pos) const;
    
    public:
        KomponentenList();
        int size() const;
        Komponente const* at(int pos) const;
        int erase(int pos);
        void push_back(Komponente k);
        KomponentenElement* end() const;
        KomponentenElement* begin() const;
        ~KomponentenList();
};

#endif //KOMPONENTENLIST_H