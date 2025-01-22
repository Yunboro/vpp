//------------------------------------------------------------------
// %v20250117Main.cpp
// Copyright 17.01.2025
// Author: KJR
//------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <functional>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;


// 1) Funktions-Template dass Elemente eines STL-Containers Typ-Parameter C
//    in 5 Spalten mit Breite 12 und 3 Nachkommastellen ausgibt
//    Unterschied C::iterator und C::const_iterator
template <class C>
void druckeTabelle(typename C::const_iterator b,
                   typename C::const_iterator e){
    cout << std::fixed << std::setprecision(3);
    int i = 0;
    while(b != e){
        cout << std::setw(12) << *b;
        ++b;
        ++i;
        if (i % 5 == 0){
            cout << endl;
        }
    }
}


// 2) In main: tis als STL-Container std::vector mit 20 double Elementen, die
// alle 0 sind, anlegen und als Tabelle ausdrucken
// Vorsicht vor Sequenz-Konstruktor (std::initializer_list)

// 3) Gitter-Generator Gitter als Generator (Funktor/Funktionsobjekt ohne Parameter)
// mit Start-Zeitpunkt start und Abtast-Periode dt_ (Abtastfrequenz f_s = 1/dt) 
// mutable erklaeren
class Gitter{
private:
    double dt;
    mutable double t;
 public:
    Gitter(double start, double dt_) : dt{dt_}, t{start}  {}
    double operator()() const {
        double erg = t;
        t += dt;
        return erg;
    }    
};

// 4) in main befuellen von tis mit Gitter, dt_ = 0.5, start = 0
//    Verwendung von std::generate
//    und Gitter als Tabelle ausgeben

// 5) Funktion hoeherer Ordnung abtasten erstellen, die die Funktion f
//    auf Gitter, das im STL-Container vom Typ C gespeichert ist, abtastet
//    Erinnerung: es gibt in C++ 4 Moeglichkeiten f zu uebergeben:
//           a) normale Funktion / Funktions-Pointer
//           b) Funktions-Objekt/Funktor
//           c) std::function
//           d) Lambda-Ausdruck
//   Trick: Funktionstemplate mit weiteren Typ-Parameter F fuer f
template <class C, class F>
C abtasten(typename C::const_iterator b,
           typename C::const_iterator e, F f) {
    C erg;
     while(b != e){
        erg.push_back(f(*b));
         ++b; 
     }
     return erg;
}


// 6) "normale" Funktion saege erstellen, die auf (-infty, infty) definiert ist
//    und ein Saegezahn-Signal mit Periode n darstellt
//    Tipp f(t) = n * (t/n - floor(t/n))
//    zum ueben statt floor Cast verwenden
double saege(double t){
    int n = 4;
    double y = n * (t/n - static_cast<int>(t/n));
    return y;
}

// 7) in main saege als Funktions-Pointer an abtasten uebergeben
//    Ergebnis als Tabelle ausgeben

// 8) saege als Funktor Saege (n wird im Konstruktor initialisiert) erstellen
//    in main diesen in main an abtasten uebergeben
//    und Ergebnisse als Tabelle ausgeben 

// saege als Funktor
class Saege{
    int n;
public:
    explicit Saege(int n_) : n{n_}{
    }
    double operator()(double t){
        double y = n * (t/n - static_cast<int>(t/n));
        return y;
    }
    
};


// 9) abtasten erhaelt die abzutastende Funktion als std::function
//    in main uebergeben, Ergebnis als Tabelle ausgeben
//    Initialisieren mit "normaler" Funktion saege oder
//    mit Funktor vom Typ Saege

// 10) abtasten erhaelt die abzutastende Funktion als Lambda-Ausdruck
//    in main uebergeben, Ergebnis als Tabelle ausgeben
//     n wird ueber Erfassungsliste uebergeben

// 11) in main, Funktor Gitter als lambda-Ausdruck an std::generate
//     uebergeben, anwenden und als Tabelle ausgeben
//     mutable bei Lambda erklaeren

int main() {
    
    // 2)
    std::vector<double> tis(20, 0.0);
    druckeTabelle<std::vector<double>>(tis.cbegin(), tis.cend());
    cout << endl;
    
    /*
    // 4)
    Gitter gi{0.0, 0.5};
    std::generate(tis.begin(), tis.end(), gi);
    */
    // 11)
    double dt = 0.5;
    double t = 0.0;
    std::generate(tis.begin(), tis.end(), [&t, dt]() mutable {
        double erg = t;
        t += dt;
        return erg;
    });
    druckeTabelle<std::vector<double>>(tis.cbegin(), tis.cend());
    cout << endl;
    
    /*
    // 7)
    double (*fp)(double) = saege;
    auto sig1 = abtasten<std::vector<double>>(tis.begin(), tis.end(), fp);
    druckeTabelle<std::vector<double>>(sig1.cbegin(), sig1.cend());
    */
    
    /*
    // 8) mit Funktor und 9) mit std::function 
    Saege saege2{4};
    //std::function<double(double)> fc = saege2;
    std::function<double(double)> fc = saege;
    auto sig1 = abtasten<std::vector<double>>(tis.begin(), tis.end(), fc);
    druckeTabelle<std::vector<double>>(sig1.cbegin(), sig1.cend());
    */
    
    /*
    // 10) Lambda Ausdruck
    int n = 4;
    auto sig1 = abtasten<std::vector<double>>(tis.begin(),
                                              tis.end(),
        // Lambda Ausdruck
        [n](double t){
    // ueber Erfassungs-Lsite anstelle von int n = 4;
    double y = n * (t/n - static_cast<int>(t/n));
    return y;});                                      
          
    druckeTabelle<std::vector<double>>(sig1.cbegin(), sig1.cend());
    */
    
    return 0;
}
