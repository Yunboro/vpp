#ifndef HOCHLAGER_H
#define HOCHLAGER_H

#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

template <class T>
class Kiste {
    public:
        T inhalt;
        Kiste* next;
};

template <class T>
class HochLager {
    private:
        std::map<std::string, Kiste<T>*> platz;
    public:
        //Artikel P in Schublade einlagern
        HochLager();

        HochLager(const HochLager& rhs) = delete;
        HochLager& operator=(const HochLager& rhs) = delete;

        void operator+=(T p);
        T operator-=(T p);
        size_t getAnzahl(T p) const;
        double getMaxPreis() const;
        void printInventarAufsteigendNachPreis(std::ostream& os) const;
        ~HochLager();
};

#endif // HOCHLAGER_H