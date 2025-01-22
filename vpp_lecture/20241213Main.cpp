//------------------------------------------------------------------
// 20241213Main.cpp
// Copyright 13.12.2024
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "buch.h"

using std::cout;
using std::endl;

// 1) Arbeiten mit ofstream schreiben und append
void bspOFStrem() {
    std::string fname = "jaeger.txt";
    std::ofstream out{fname, std::ios::out};
    if (!out.is_open()){
        throw std::runtime_error("Datei "
                                 + fname + " kann nicht geoeffnet werden");
    }
    for(int i = 10; i > 0; --i){
        out << i << " Jaegerlein" << endl;
    }
    
    cout << fname + " erstellt" << endl;
    out.close();
    
    // Append
    out.open(fname, std::ios::out | std::ios::app);
    for(int i = 10; i > 0; --i){
        out << i << " Jaegerlein" << endl;
    }
    
    cout << fname + " append" << endl;
    // Wird im Destruktor geschlossen
}

// 2) 2) Arbeiten mit ifstream formatiert
void bspIFStream(){
    
    std::string fname = "jaeger.txt";
    std::ifstream in{fname, std::ios::in};
    if (!in.is_open()){
        throw std::runtime_error("Datei "
                                 + fname
                                 + " kann nicht geoeffnet werden");
    }
    
    int i;
    std::string wort;
    
    while(in) {
        in >> i >> wort;
        if(in.good()){
            cout << i << wort << endl;
        } else if (in.eof()){
            break;
        } else if(in.fail()){
            in.clear();
            std::string muell;
            in >> muell;
            cout << "Error: ungueltiges Zeichen: " + muell << endl;
        }
    }
    in.close();
    
}

// 3) Typ-Definitionen
// alt mit typedef
//typedef std::vector<Buch> TBib;

// neu mit using
using TBib = std::vector<Buch>;

// Prototyp
Buch extractBuch(const std::string& zeile);

// 4) Zeilenweises Lesen csv-Datei csWithRating.txt
void readBib(TBib& bib){
    std::string fname = "csWithRating.txt";
    std::ifstream in{fname, std::ios::in};
    if (!in.is_open()){
        throw std::runtime_error("Datei "
                                 + fname
                                 + " kann nicht geoeffnet werden");
    }
    std::string zeile;
    while (std::getline(in, zeile)) {
        if (in.good()){
            //extractBuch(const std::string& zeile);
            bib.push_back(extractBuch(zeile));
            //cout << zeile << endl;
        } else if (in.eof()){
            break;
        }
    }
    
    
}

// 5) Arbeiten mit std::string
//    Eingabe-Zeile in Bestandteile zerlegen
Buch extractBuch(const std::string& zeile) {
    size_t p1, p2, p3;
    p1 = zeile.find(';');
    if (p1 == std::string::npos){
        throw std::runtime_error("p1 nicht gefunden");
    }
    p2 = zeile.find(';', p1+1);
    if (p2 == std::string::npos){
        throw std::runtime_error("p2 nicht gefunden");
    }
    p3 = zeile.find(';', p2+1);
    if (p3 == std::string::npos){
        throw std::runtime_error("p1 nicht gefunden");
    }
    
    std::string autor, titel;
    size_t jahr, bew;
    // laenge = p1 - 1 - 0 + 1 = p1
    autor = zeile.substr(0, p1);
    // laenge = p2-1 - (p1+1) + 1 = p2-p1-1
    titel = zeile.substr(p1+1, p2 - p1 -1);
    // laenge = ...
    jahr = static_cast<size_t>(std::atoi(
        zeile.substr(p2+1, p3 - p2 - 1).c_str()));
    // laenge = zeile.size() - 1 - (p3 + 1) + 1 = 
    bew = static_cast<size_t>(std::atoi(
        zeile.substr(p3+1, zeile.size() - p3 -1).c_str()));
    //cout << autor << ", "
    //     << titel << ", "
    //     << jahr << ", " << bew << endl;
    Buch b{autor, titel, jahr, bew};
    return b;
}


// 6) Ausgabe aller Autoren (2 Moeglichkeiten)
// void druckeAutoren(const TBib& bib)

// 7) Ausgabe aller Autoren ohne Mehrfachnennungen
void druckeAutorenOhneMehrfachnennung(const TBib& bib){
    // verwende set
    std::set<std::string> myset;
    for(auto it = bib.begin(); it != bib.end(); ++it){
        myset.insert((*it).getAutor());
    }
    for (const auto& e: myset){
        cout << e << endl;
    }    
}

// 8) Speicherung in map nach Erscheinungsjahr
std::map<size_t, TBib> erstelleBibNachJahr(const TBib& bib){
    std::map<size_t, TBib> erg;
    for (const auto& e: bib){
        erg[e.getJahr()].push_back(e);
    }
    return erg;
}

// Funktion als Comparator
bool greater(const Buch& a, const Buch& b){
    return a.getBewertung() > b.getBewertung();
}

int main() {
    
    //bspOFStrem();
    //bspIFStream();
    TBib bib;
    readBib(bib);
    //for(const auto& e:bib){
    //    cout << e.getAutor() << endl;
    //}
    // druckeAutorenOhneMehrfachnennung(bib);
    
    // 9) Ausgabe fuer alle Jahre Anzahl der Buecher
    //    mittels bereichsb. Schleife und std::pair
    std::map<size_t, TBib> bibNachJahr =
        erstelleBibNachJahr(bib);
    //for(const auto& paar: bibNachJahr){
    //    cout << paar.first << " : " << paar.second.size() << endl;
    //}
 
    // 10) Sortieren nach fallender Bewertung fuer Jahr 2015
    
    // a) Mit Funktions-Pointer
    bool (*fp)(const Buch&, const Buch&) = greater;
    std::sort(bibNachJahr[2015].begin(), bibNachJahr[2015].end(),
              fp);
    for(const auto& e: bibNachJahr[2015]){
        e.output(cout);
    }
    
    // b) Mit Funktions-Objekt (Funktor)
    
    // c) Lambda-Ausdruck
    
    // d) Objekt von Typ std::function aus <functional>
    //    kann alle 3 obige Typen speichern
    return 0;
}
