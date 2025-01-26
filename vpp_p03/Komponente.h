#ifndef KOMPONENTE_H
#define KOMPONENTE_H
#include <iostream>
#include <QJsonDocument>
#include "IKomponente.h"

class Komponente : public IKomponente
{
//private:
    double x, y;
    IKomponente const* parent;
public:
    //Konstruktor
    Komponente(double xPos = 0.0, double yPos = 0.0)
        : x(xPos), y(yPos), parent(nullptr) {}

    double calcTotalPath() const override;
    //Getter Methode definition
    double getX() const override {return x;}
    double getY() const override {return y;}
    double getXAbsolute() const override;
    double getYAbsolute() const override;
    //
    double distance(IKomponente const *k) const override;
    IKomponente const* getParent() const override;
    void setParent(IKomponente const *p) override;
    QJsonObject toJson() const override;
    virtual void output(std::ostream& os) const override;
    virtual ~Komponente() override {}
};

#endif // KOMPONENTE_H
