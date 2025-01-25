#ifndef DELIST_H
#define DELIST_H

#include "ikomponentenelement.h"
#include "iterator.h"

class DeList {
    private:
        int counter;
        IKomponentenElement* first;
        IKomponentenElement* getElement(Iterator it) const;
    public:
        DeList();
        
        DeList(DeList const& rhs);
        DeList& operator=(DeList const& rhs);
        void clear();
        int size() const;
        Iterator erase(Iterator pos);
        void push_back(IKomponente* k);
        Iterator end() const;
        Iterator begin() const;

        ~DeList();
};

#endif //DELIST_H