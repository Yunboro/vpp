#ifndef BOHRUNG_H
#define BOHRUNG_H
#include "komponente.h"

class Bohrung : public Komponente
{
    private:
        double diameter;

    public:
        Bohrung(double x_ = 0.0, double y_ = 0.0, double diam = 6.0);
        double getDiameter() const;
        virtual void output(std::ostream& os) const override;
        ~Bohrung();
        //nochmal virtual unnötig, da es in der Basisklasse schon virtual ist
        //override gibt an, dass es eine Funktion in der Basisklasse gibt (Redundanz), nur in Header nötig
};

#endif //BOHRUNG_H