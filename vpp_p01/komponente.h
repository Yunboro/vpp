#ifndef KOMPONENTE_H
#define KOMPONENTE_H

#include <iostream>

//Header nur Funktionsköpfe hineinschreiben

class Komponente
{
    private:
        double x, y;

    public:
        Komponente(double xPos = 0.0, double yPos = 0.0);
        //Komponente(double xPos = 0.0, double yPos = 0.0) : x{xPos} , y{yPos} {}
        //funktionieren geschweifte Klammern auch ?
        //Aufruf eines anderen Konstruktors mit geschweiften Klammern ist wohl möglich

        //const kann const aufrufen, jedoch const keine nicht-const Funktionen

        double getX() const; //Nur lesende Funktion, deswegen const
        double getY() const; 
        virtual void output(std::ostream& os) const;
        virtual ~Komponente();
};

//Überladen Schiebe-Operator als freie Funktion
inline std::ostream& operator<<(std::ostream& os, const Komponente& k)
{
    k.output(os);
    return os;
};

#endif //KOMPONENTE_H
//Übergabe des Objekts k an output Funktion.
//Übergabe als Parameter in Funktion verändert Original nicht
//Übergabe als Referenz kann das Original verändert werden
//Übergabe als const Referenz kann das Original nicht verändert werden