#ifndef TELEMENT_H
#define TELEMENT_H
#include "IKomponente.h"

template<class T>
struct TElement
{
    T k;
    TElement* before;
    TElement* next;
};
#endif // TELEMENT_H
