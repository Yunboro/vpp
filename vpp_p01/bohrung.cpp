#include "bohrung.h"

Bohrung::Bohrung(double x_, double y_, double diam) : Komponente(x_, y_), diameter(diam) {}

double Bohrung::getDiameter() const { return diameter; }

void Bohrung::output(std::ostream& os) const
{
    os << "Bohrung: ";
    Komponente::output(os); //seperater Aufruf der output Funktion der Basisklasse
    os << ", Durchmesser: " << diameter << std::endl;
}

Bohrung::~Bohrung() {}