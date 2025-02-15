#include "fraesung.h"
#include <cmath>

Fraesung::Fraesung(double x_, double y_, double diam, double l, double a): Bohrung(x_, y_, diam), length(l), angle(a) {
    if(length <= 0) length = 0.0;
}

double Fraesung::calcTotalPath() const {
    return 2 * getLength();
}

double Fraesung::getLength() const { return length; }
double Fraesung::getAngle() const { return angle; }
double Fraesung::getEndX() const { return getX() + length * cos(angle); }
double Fraesung::getEndY() const { return getY() + length * sin(angle); }
void Fraesung::output(std::ostream& os) const
{
    os << "Fraesung mit Start: ";
    Komponente::output(os);
    os << " und Endpunkt: (" << getEndX() << ", " << getEndY() << "), Durchmesser: " << getDiameter();
}
Fraesung::~Fraesung() {}