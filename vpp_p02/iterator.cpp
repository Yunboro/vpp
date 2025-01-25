#include "iterator.h"

Iterator::Iterator(IKomponentenElement* begin) : curr{begin} {}

Iterator& Iterator::operator++() {
    if(curr != nullptr) {
        curr = curr->next;
    }
    return *this;
}

bool Iterator::operator!=(Iterator const& it) const{
    return this->curr != it.curr;
    //return !operator==(it);
    //Aufruf der == Methode und negiere diese
}

bool Iterator::operator==(Iterator const& it) const{
    return this->curr == it.curr;
}

IKomponente* Iterator::operator*() const{
    if(curr == nullptr) {
        return nullptr;
    }
    return curr->k;
}

Iterator::~Iterator() {
    //delete curr;
}