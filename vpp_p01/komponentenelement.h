#ifndef KOMPONENTENELEMENT_H
#define KOMPONENTENELEMENT_H
#include "komponente.h"

struct KomponenteElement
{
    Komponente k;
    KomponenteElement* before;
    KomponenteElement* next;
};

endif //KOMPONENTENELEMENT_H