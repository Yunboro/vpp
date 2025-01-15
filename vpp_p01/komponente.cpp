#include "komponente.h"
 

Komponente::Komponente(double xPos, double yPos) : x(xPos) , y(yPos) {}

double Komponente::getX() const { return x; }
double Komponente::getY() const { return y; }

void Komponente::output(std::ostream& os) const {
    os << "(" << x << "," << y <<")";
}

Komponente::~Komponente() {}