#ifndef WERKSTUECK_H
#define WERKSTUECK_H

#include "komponente.h"
#include "delist.h"
#include "iterator.h"

class Werkstueck : public Komponente
{
    private:
        double height, width;
        bool pathIsOptimized;
        DeList komponenten;
        Iterator getNearest(IKomponente const* pk) const;
    public:
        Werkstueck(double xPos = 0.0, double yPos = 0.0, double h = 1, double w = 1);
        double getHeight() const;
        double getWidth() const;
        void add(IKomponente* k);
        void remove(IKomponente const* k);
        IKomponente const* getChild(int i) const;
        double calcTotalPath() const override;
        double calcPathLength() const;
        void optimizePath();
        void output(std::ostream& os) const override;
        ~Werkstueck();
};
#endif // WERKSTUECK_H