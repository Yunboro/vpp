#ifndef FRAESUNG_H
#define FRAESUNG_H
#include <Bohrung.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

class Fraesung : public Bohrung
{
//private:
    double length;
    double angle;
public:
    Fraesung(double x, double y, double diam, double l, double a = 0.0)
        :Bohrung(x, y, diam), length(l), angle(a) /*length(l>0 ? l : 0.0)*/
    {
        if(length > 0)
        {
            length = l;
        }
        else
        {
            length = 0;
        }
    }
    //Deklaration von TotalPath
    double calcTotalPath() const override;

    //Getter für Length & Angle
    double getLength() const {return length;}
    double getAngle() const {return angle;}

    //Ausgabe Methode
    void output(std::ostream &os) const override
    {
        os << "Fraesung mit Start: ";
        Komponente::output(os);
        os << " und Endpunkt: (" << getEndX() << ", " << getEndY() << ")"
           << ", Durchmesser: " << getDiameter();
        /*os << "\n" << "Laenge: " << getLength()
           << " Winkel: " << getAngle();*/
        //os << endl;
    }

    //Getter für EndX|Y
    //cos(angle) * Length + X|Y
    double getEndX() const;
    double getEndY() const;
    QJsonObject toJson() const override;
    //Dekonstruktor
    virtual ~Fraesung() override {}
};
#endif // FRAESUNG_H
