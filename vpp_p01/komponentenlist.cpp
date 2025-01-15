#include "komponentenlist.h"

KomponentenList::KomponentenList() : counter{0}, first{nullptr} {}

KomponentenElement* KomponentenList::begin() const { return first; }
KomponentenElement* KomponentenList::end() const { return getElement(counter); }

KomponentenElement* KomponentenList::getElement(int pos) const
{   
    if(pos < 0 || pos >= counter) return nullptr;

    KomponentenElement* current = first;
    
    for(int i = 0; i < pos; ++i)
    {
        current = current->next;
    }
    return current;
}

int KomponentenList::size() const { return counter; }

Komponente const* KomponentenList::at(int pos) const
{ 
    if(pos < 0 || pos >= counter) return nullptr;
    KomponentenElement* current = getElement(pos);
    return current->k;
}

int KomponentenList::erase(int pos)
{
    if(pos < 0 || pos >= counter || counter == 0) return -1;
    KomponentenElement* to_delete = getElement(pos);

    if(pos == 0) {
        // Setze first auf das zweite Element
        first = to_delete->next;
        // Falls nicht das letzte Element gelöscht wird, setze den Vorgänger des neuen ersten Elements auf nullptr
        if(first != nullptr) {
            first->prev = nullptr;
        }
    } else {
        to_delete->prev->next = to_delete->next;
        if(to_delete->next != nullptr) {
            to_delete->next->prev = to_delete->prev;
        }
    }

    delete to_delete;
    --counter;
    return 0;
}