#ifndef WERKSTUECK_H
#define WERKSTUECK_H
#include "IKomponente.h"
#include "Komponente.h"
#include "Iterator.h"
#include "DeList.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <iostream>
/////
class Werkstueck : public Komponente
{
    double height, width;
    bool pathIsOptimized;
    DeList<IKomponente*> components;
    Iterator<IKomponente*> getNearest(IKomponente const* pk) const;
public:
    Werkstueck(double xPos = 0.0, double yPos = 0.0, double h = 1.0, double w = 1.0)
        : Komponente(xPos, yPos), height(h), width(w), pathIsOptimized(false) {}
    //Getter
    double getHeight() const;
    double getWidth() const;

    void add(IKomponente* k);
    void remove(IKomponente const* k);
    IKomponente const* getChild(int i) const;
    double calcTotalPath() const override;
    double calcPathLength() const;
    void optimizePath();
    QJsonObject toJson() const override;
    void output(std::ostream &os) const override;
    ~Werkstueck() override {}
};

#endif // WERKSTUECK_H
