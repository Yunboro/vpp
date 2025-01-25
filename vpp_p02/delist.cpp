#include "delist.h"

DeList::DeList() : counter(0), first(nullptr) {}

IKomponentenElement* DeList::getElement(Iterator it) const {
    auto* elem = first;
    while(elem != nullptr) {
        if(elem->k == *it) {
            return elem;
        }
        elem = elem->next;
    }
    return nullptr;
}

DeList::DeList(DeList const& rhs) : counter{rhs.size()}, first {nullptr} {
    auto it = rhs.begin();
    while(it != rhs.end()) {
        push_back(*it);
        ++it;
    }
}

DeList& DeList::operator=(DeList const& rhs) {
    if(this != &rhs)
    {
        clear();
        Iterator it = rhs.begin();
        while(it != rhs.end()) {
            push_back(*it);
            ++it;
        }
    }
    return *this;
}

void DeList::clear() {
    auto* elem = first;
    while(elem != nullptr) {
        auto* tmp = elem;
        elem = elem->next;
        delete tmp;
    }
    counter = 0;
    first = nullptr;
}

int DeList::size() const {
    return counter;
}

Iterator DeList::erase(Iterator pos) {
    auto* tmp = getElement(pos);
    Iterator erg;
    if (tmp == nullptr) {
        return erg;
    }
    erg = ++pos;    
    if (tmp == first) {
        first = tmp->next;
    } 
    else if (tmp->next == nullptr)
    {
        auto* prev = tmp->before;
        prev->next = nullptr;
    }
    else
    {
        auto* prev = tmp->before;
        auto* post = tmp->next;
        prev->next = post;
        post->before = prev;
        
    }
    delete tmp;
    --counter;
    return erg;
    //Use of memory after free
    //return Iterator(tmp->next);
}

void DeList::push_back(IKomponente* k) {
    auto* elem_to_add = new IKomponentenElement;
    elem_to_add->k = k;
    elem_to_add->next = nullptr;
    elem_to_add->before = nullptr;

    if(counter == 0) {
        first = elem_to_add;
    }
    else {
        auto* last_elem = first;
        while(last_elem->next != nullptr) {
            last_elem = last_elem->next;
        }
        last_elem->next = elem_to_add;
        elem_to_add->before = last_elem;
    }
    ++counter;
}

Iterator DeList::end() const {
    return Iterator(nullptr);
}

Iterator DeList::begin() const {
    return Iterator(first);
}

DeList::~DeList() {
    clear();
}