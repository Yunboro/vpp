#ifndef KOMPONENTENELEMENT_H
#define KOMPONENTENELEMENT_H
#include "komponente.h"
#include <iostream>

struct KomponentenElement
{
    Komponente* k;
    KomponentenElement* before;
    KomponentenElement* next;
};

#endif //KOMPONENTENELEMENT_H