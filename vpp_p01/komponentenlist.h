#ifndef KOMPONENTENLIST_H
#define KOMPONENTENLIST_H

#include "komponente.h"

class KomponentenList
{   
    private:
        int counter;
        KomponentenElement* first;
        KomponentenElement* getElement(int pos) const;
    
    public:
        KomponentenListe();
        int size() const;
        int Komponente const* at(int pos) const;
        int erase(int pos);
        void push_back(Komponente k);
        ~KomponentenListe();

#endif //KOMPONENTENLIST_H