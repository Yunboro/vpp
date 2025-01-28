#ifndef A04_H
#define A04_H

#include <functional>

// Definition des neuen Typs TFC
using TFC = std::function<bool(int)>;
//typedef std::function<bool(int)> TFC;
using TFP = bool (*)(int);

//Erste Ü-Param is Generator, zweite ist Prädikat
template <class G, class P>
int laenge(G& g, P p) {
    //Rufe g() auf, bis p(g()) == false, dann break
    int length = 0;
    while(true) {
        auto val = g();
        //wenn false, dann break
        if(!p(val)) {
            break;
        }
        length++;
    }
    return length;
}

class PCollatz {
    public:
        bool operator()(int n) {
            return n != 1;
        }
};

class Collatz {
private:
    int n;
    bool firstCall = true;

public:
    // Konstruktor, der den Anfangswert start setzt
    Collatz(int start) : n(start) {}

    // Überladener Aufruf-Operator, der die Collatz-Folge generiert
    int operator()() {
        if(firstCall) {
            firstCall = false;
        }
        else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        return n;
    }
};

void a04();

#endif // A04_H