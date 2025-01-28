#include "hochlager.h"
#include "produkt.h"

//da map Elemente von std::pair speichert
//kann man first und second verwenden

template <class T>
HochLager<T>::HochLager() {
    // Leere Implementierung, da std::map sich selbst korrekt initialisiert
}

template <class T>
void HochLager<T>::operator+=(T p) {
    //Finde std::pair mit Schlüssel p.getName()
    auto it = platz.find(p.getName());
    //Schlüssel existiert noch nicht
    if(it == platz.end()) {
        //neues Schlüssel-Wert-Paar anlegen
        platz[p.getName()] = new Kiste<T>{p, nullptr};
        //platz.insert(std::make_pair(p.getName(), new Kiste<T>{p, nullptr}));
    }
    else
    {
        //Schlüssel vorhanden, Kiste am Ende der Kistenliste einfügen
        //Kiste<T>* current = it->second;
        auto* current = it->second;
        while(current->next != nullptr) {
            current = current->next;
        }
        current->next = new Kiste<T>{p, nullptr};
    }
}

template <class T>
//Übergabeparameter nur für den Namen des Produktes/Schlüssels
T HochLager<T>::operator-=(T p) {
    auto it = platz.find(p.getName());
    if(it == platz.end()) {
        throw std::runtime_error("Inhalt kann nicht geloescht werden");
    }
    else
    {
        //Pointer auf erste Kiste, welche ausgegeben werden soll
        //Kiste<T>* current = it->second;
        auto* current = it->second;
        //Prüfen, ob erstes Element vorhanden
        if(current != nullptr) {
            T removedProduct = current->inhalt;
            it->second = current->next;
            delete current;
            return removedProduct;
        }
        else
        {
            throw std::runtime_error("Inhalt kann nicht geloescht werden");
        }
    }
}

template <class T>
size_t HochLager<T>::getAnzahl(T p) const {
    auto anzahl = 0;
    auto it = platz.find(p.getName());
    if(it != platz.end()) {
        auto* current = it->second;
        while(current != nullptr) {
            ++anzahl;
            current = current->next;
        }
        //zu frühe Ausgabe hat zu Fehlern geführt, memory corruption
        return anzahl;
    }
    return anzahl;
}

template <class T>
double HochLager<T>::getMaxPreis() const {
    double maxPreis = 0.0;
    for (auto item : platz) {
        auto* it = item.second;
        while(it != nullptr) {
                if(it->inhalt.getPreis() > maxPreis) {
                    maxPreis = it->inhalt.getPreis();
                }
            it = it->next;
        }
    }
    return maxPreis;
}

template <class T>
void HochLager<T>::printInventarAufsteigendNachPreis(std::ostream& os) const {
    std::vector<T> produkte;
    std::map<std::string, int> produktAnzahl;

    // Alle Produkte aus der Map in den Vektor einfügen und die Anzahl zählen
    for (auto pair : platz) {
        auto* it = pair.second;
        produktAnzahl[pair.first] = 0;
        //int counter = 0;
        while (it != nullptr) {
            produktAnzahl[pair.first]++;
            //++counter;
            it = it->next;
        }
        
        //produktAnzahl[pair.first] = counter;
        if (pair.second != nullptr) {
            produkte.push_back(pair.second->inhalt);
        }
    }

    // Produkte nach Preis sortieren
    // Lambda Ausdruck, der zwei Produkte vergleicht
    // In dem Fall Datentyp von Klasse Prdukt
    // std::function<bool(const T&, const T&)> compareprice
    auto compareprice = [](const T& a, const T& b){ return a.getPreis() < b.getPreis(); };
 
    //Anfang und Ende des Vektors, Lambda Ausdruck
    std::sort(produkte.begin(), produkte.end(), compareprice);

    // Sortierte Produkte ausgeben
    for (const auto& produkt : produkte) {
        os << produkt
           << " :" << std::setw(4) << std::right << produktAnzahl[produkt.getName()] << std::endl;
    }
}

template <class T>
HochLager<T>::~HochLager() {
    // Leere Implementierung, da std::map sich selbst korrekt freigibt
    // jedoch braucht man diese für die Kiste<T>* Elemente
    for(auto pair : platz) {
        auto* it = pair.second;
        while(it != nullptr) {
            auto* post = it->next;
            delete it;
            it = post;
        }
    }
    platz.clear();
}

// Explicit instantiation for the Produkt class
template class HochLager<Produkt>;