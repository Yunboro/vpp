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
    
    KomponentenElement* tmp = getElement(pos);

    if(pos == 0) {
        // Setze first auf das zweite Element
        first = tmp->next;
        // Falls nicht das letzte Element gelöscht wird, setze den Vorgänger des neuen ersten Elements auf nullptr
        if(first != nullptr) {
            first->before = nullptr;
        }
        //Falls es keine Elemente mehr gibt, wird automatisch immer ein nullptr zurückgegeben, da dies das einzige Element ist
    }else if(pos == counter - 1) {
        //vorletztes Element holen
        KomponentenElement* prev = tmp->before;
        prev->next = nullptr;
    }else {
        //Element vorher und nachher holen
        KomponentenElement* prev = tmp->before;
        KomponentenElement* post = tmp->next;
        prev->next = post;
        post->before = prev;
    }
    delete tmp;
    --counter;
    return pos;
}

void KomponentenList::push_back(Komponente* k)
{
    KomponentenElement* element_to_add = new KomponentenElement;
    element_to_add->k = k;
    element_to_add->before = nullptr;
    element_to_add->next = nullptr;
    if(counter == 0) {
        first = element_to_add;
    }
    else {
        element_to_add->before = getElement(counter - 1);
        getElement(counter - 1)->next = element_to_add;
    }
    counter++;
}

//gesamte verkette Liste löschen
KomponentenList::~KomponentenList()
{
    KomponentenElement* current = first;
    //Schleife über alle Elemente
    while(first != nullptr)
    {
        current = first->next;
        //erstes Element löschen
        delete first;
        first = current;
    }
    counter = 0;
}