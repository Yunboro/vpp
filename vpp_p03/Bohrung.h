#ifndef BOHRUNG_H
#define BOHRUNG_H
#include "Komponente.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <cmath>
#include <iostream>
using std::endl;

class Bohrung : public Komponente
{
    double diameter;
public:
    Bohrung(double x_ = 0.0, double y_= 0.0, double diam = 6.0)
        : Komponente(x_, y_), diameter(diam)//diameter(diam > 0 ? diam : 6.0){}
    {
        if (diameter > 0.0)
        {
            diameter = diam;
        }
        else
        {
            diameter = 6.0;
        }
    }
    //Getter Methode für Diameter
    double getDiameter() const {return diameter;}

    void output(std::ostream &os) const override
    {
        os << "Bohrung: ";
        Komponente::output(os);
        os << ", Durchmesser: " << diameter;
    }

    QJsonObject toJson() const override;

    //Destruktor von Bohrung
    ~Bohrung () override {}
};
#endif // BOHRUNG_H
