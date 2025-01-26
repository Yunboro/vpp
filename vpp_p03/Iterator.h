#ifndef ITERATOR_H
#define ITERATOR_H
#include "IKomponente.h"
#include "telement.h"

template <class T>
class Iterator
{
    TElement<T>* curr;
public:
    Iterator(TElement<T>* currPos = nullptr)
        :curr(currPos) {}

    //Nächstes Element Operator (++)
    Iterator& operator++()
    {
        if(curr != nullptr)
        {
            curr = curr->next;
        }
        return *this;
    }

    //Vergleichsoperator
    bool operator!=(Iterator const& it) const
    {
        return this->curr != it.curr;
    }
    //Vergleichsoperator
    bool operator==(Iterator const& it) const
    {
        return this->curr == it.curr;
    }
    //Dereferenzierungsoperator
    T& operator*() const
    {
        return curr->k;
    }

    virtual ~Iterator() {}

};

#endif // ITERATOR_H
