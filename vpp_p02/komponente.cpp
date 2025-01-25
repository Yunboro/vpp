#include "komponente.h"

Komponente::Komponente(double xPos, double yPos) : x{xPos}, y{yPos}, parent{nullptr} {}

double Komponente::calcTotalPath() const {
    return 0.0;
}

double Komponente::getX() const {
    return x;
}

double Komponente::getY() const {
    return y;
}

double Komponente::getXAbsolute() const {
    double xAbs = getX();

    IKomponente const* p = getParent();
    if(parent != nullptr) {
        xAbs += p->getXAbsolute();
    }

    return xAbs;
}

double Komponente::getYAbsolute() const {
    double yAbs = getY();

    IKomponente const* p = getParent();
    if(parent != nullptr) {
        yAbs += p->getYAbsolute();
    }

    return yAbs;
}

double Komponente::distance(IKomponente const* k) const {
    if(k == nullptr) return 0.0;

    double xDiff = getXAbsolute() - k->getXAbsolute();
    double yDiff = getYAbsolute() - k->getYAbsolute();
    //zumindest ist hier die Reihenfolge in der Differenz egal, aufgrund der Quadrierung	
    return std::sqrt(xDiff*xDiff + yDiff*yDiff);
}

IKomponente const* Komponente::getParent() const {
    return parent;
}

void Komponente::setParent(IKomponente const* p) {
    parent = p;
}

void Komponente::output(std::ostream& os) const{
    os << "(" << getX() << ", " << getY() << ")";
}

Komponente::~Komponente() {}   