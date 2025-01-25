#ifndef ITERATOR_H
#define ITERATOR_H

#include "ikomponentenelement.h"

class Iterator {
    private:
        IKomponentenElement* curr;

    public:
        explicit Iterator(IKomponentenElement* begin = nullptr);

        Iterator& operator++();
        bool operator!=(Iterator const& it) const;
        bool operator==(Iterator const& it) const;
        IKomponente* operator*() const;
        ~Iterator();
};


#endif //ITERATOR_H