#include "a04.h"
#include <iostream>
#include <vector>
#include <algorithm>

void a04() {
    Collatz c10{10};

    // Erstellen eines STL-Containers vec
    // vom Typ std::vector mit 30 int-Werten,
    // alle mit 0 initialisiert
    std::vector<int> vec(30, 0);

    // Ausgabe des Vektors zur Überprüfung
    std::cout << "Vektor gefuellt mit der Collatz-Folge:" << std::endl;
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Füllen des Vektors mit der Collatz-Folge
    std::generate(vec.begin(), vec.end(), c10);
    
    // Ausgabe des Vektors mit einer bereichsbasierten Schleife
    std::cout << "Bereichsbasierte Schleife:" << std::endl;
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Ausgabe des Vektors mit einem Iterator
    std::cout << "Iterator:" << std::endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Erstellen Sie ein neues Generator-Objekt cfunk vom Typ Collatz mit Startwert 100
    Collatz cfunk(100);

    // Erstellen Sie ein Prädikat pc vom Typ PCollatz
    PCollatz pc;

    // Rufen Sie das Funktions-Template laenge()
    // mit cfunk und pc, benutzen Generator verändert cfunk
    int result = laenge(cfunk, pc);
    std::cout << "Laenge der Collatz-Folge: " << result << std::endl;

    // Definieren Sie eine Variable fc vom Typ TFC und initialisieren Sie sie mit dem Prädikat pc
    TFC fc = [&pc](int n) { return pc(n); };
    //----
    // Erstellen Sie ein neues Generator-Objekt cfunk2 vom Typ Collatz mit Startwert 100
    Collatz cfunk2(100);

    // Rufen Sie erneut das Funktions-Template laenge() auf
    result = laenge(cfunk2, pc);
    std::cout << "Laenge der Collatz-Folge (mit neuem Generator): " << result << std::endl;
    //----
    // Laenge mit lambda-Ausdruck
    Collatz clam(100);

    result = laenge(clam, [](int n) { return n!=1; });
    std::cout << "Laenge der Collatz-Folge (mit Lambda): " << result << std::endl;

    Collatz clam2{100};
    TFP fc2 = [](int n) { return n!=1; };
    result = laenge(clam2, fc2);
    std::cout << "Laenge der Collatz-Folge (mit Funktor): " << result << std::endl;


}