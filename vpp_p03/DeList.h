#ifndef DELIST_H
#define DELIST_H
#include "Komponente.h"
#include "telement.h"
#include "IKomponente.h"
#include "Iterator.h"

template<class T>
class DeList
{
    int counter;
    TElement<T>* first;
    TElement<T>* getElement(Iterator<T> it) const;
public:
    DeList() :  counter(0), first(nullptr) {}

    //copy Konstruktor
    DeList(DeList const& rhs) :  counter(0), first(nullptr)
    {        
        Iterator<T> it = rhs.begin();

        while (it != rhs.end())
        {
            //Hinzuffügen der Komponente in der Liste
            this->push_back(*it);
            ++it;
        }
    }

    //Copy Zuweisungsoperator
    DeList& operator=(DeList const& rhs)
    {
        //if(this->first != rhs.first)
        if(this != &rhs)
        {
            //neustarten
            this->clear();
            Iterator<T> it = rhs.begin();

            while(it != rhs.end())
            {
                this->push_back(*it);
                ++it;
            }
        }
        return *this;
    }
    void clear();
    int size() const {return counter;}
    Iterator<T> erase(Iterator<T> pos);
    void push_back(T komp);
    Iterator<T> end() const {return Iterator<T>(nullptr);}
    Iterator<T> begin() const {return Iterator<T>(first);}
    virtual ~DeList() {clear();}

};

////////////////////////////////////////////////////////////////////////////////
template<class T>
TElement<T>* DeList<T>::getElement(Iterator<T> it) const
{
    TElement<T>* tmp = nullptr;

    if(first != nullptr && it != end())
    {
        tmp = first;

        while(tmp != nullptr)
        {
            //Iterator zeigt auf das aktuelle Komponente
            if(*it == tmp->k)
            {
                //rückgabe dieser Komponente (return *this),
                //beenden der while schleife
                break;
            }
            //tmp = nächstes Element (solange bis tmp[k] == *it)
            tmp = tmp->next;
        }
    }
    return tmp;
}
////////////////////////////////////////////////////////////////////////////////
template <class T>
void DeList<T>::clear()
{
    /*
    IKomponentenElement* delete_el = nullptr;
    while(delete_el != nullptr)
    {
        delete_el = first->next;
        delete first;
        first = delete_el;
    }
    counter=0;

    */
    Iterator<T> erstes = this->begin();
    while (counter >0)
    {
        //Iterator erstes = this->begin();
        //erase(erstes);
         erstes = erase(erstes);
    }
}
////////////////////////////////////////////////////////////////////////////////
template <class T>
Iterator<T> DeList<T>::erase(Iterator<T> pos)
{
    TElement<T>* actual = getElement(pos);
    TElement<T>* vorg = nullptr;
    TElement<T>* nachf = nullptr;
    Iterator<T> erg;
    if(actual !=nullptr)
    {
        vorg = actual->before;
        nachf = actual->next;

        if (nachf!=nullptr)
        {
            nachf->before=vorg;
        }

        if (vorg!=nullptr)
        {
            vorg->next=nachf;
        }
        else
        {
            first=nachf;
        }

        delete actual;
        --counter;
        erg = Iterator<T>(nachf);
    }

     return erg;
}

////////////////////////////////////////////////////////////////////////////////
template<class T>
void DeList<T>::push_back(T komp)
{
    TElement<T>* add_el = new TElement<T>;
    add_el->k = komp;
    add_el->before = nullptr;
    add_el->next = nullptr;

    //Wenn Liste Leer
    if(first == nullptr)
    {
        first = add_el;
    }
    else
    {
        TElement<T>* last = first;

        while(last->next != nullptr)
        {
            last = last->next;
        }
        last->next = add_el;
        add_el->before = last;
    }
    ++counter;
}
////////////////////////////////////////////////////////////////////////////////

























/*
Iterator DeList::erase(Iterator pos)
{
    Iterator it;
    IKomponentenElement* akt_el = getElement(pos);

    if(first != nullptr && akt_el != nullptr)
    {
        it = ++pos;
        if(akt_el == first)
        {
            first = akt_el->next;

            if(first != nullptr)
            {
                first->before = nullptr;
            }
        }
        if(akt_el->next != nullptr)
        {
            akt_el->next->before = akt_el->before;
        }
        if(akt_el->before != nullptr)
        {
            akt_el->before->next = akt_el->next;
        }

        delete akt_el;
        --counter;
    }
    return it;
}
///////////////////////////////////////////////////////////////
void DeList::clear()
{
    IKomponentenElement* delete_element = first;

    while(delete_element)
    {
        IKomponentenElement* next_element = delete_element->next;
        delete delete_element;
        delete_element = next_element;
    }
    counter = 0;
}
*/


#endif // DELIST_H
