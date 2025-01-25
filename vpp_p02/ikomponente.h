#ifndef IKOMPONENTE_H
#define IKOMPONENTE_H

#include <iostream>

//Alle gemeinsamen Methoden und Attribute der Komponenten
//werden hier ausgelagert
//dient als Interface/Schnittstelle für die Komponenten

class IKomponente {
    public:
        virtual double calcTotalPath() const = 0;
        virtual double getXAbsolute() const = 0;
        virtual double getYAbsolute() const = 0;
        virtual double getX() const = 0;
        virtual double getY() const = 0;
        virtual double distance(IKomponente const* k) const = 0;
        virtual IKomponente const* getParent() const = 0;
        //Einzige Ausnahme setParent(), verändert ja was anderes also kein const-correctness
        virtual void setParent(IKomponente const* p) = 0;
        virtual void output(std::ostream& os) const = 0;
        virtual ~IKomponente();
};

inline std::ostream& operator<<(std::ostream& os, IKomponente const& ik) {
    ik.output(os);
    return os;
}

#endif //IKOMPONENTE_H