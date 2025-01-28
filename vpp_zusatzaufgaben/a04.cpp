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
}