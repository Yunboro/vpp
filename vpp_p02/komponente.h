#ifndef KOMPONENTE_H
#define KOMPONENTE_H

#include "ikomponente.h"
#include <cmath>

class Komponente : public IKomponente {
    private:
        double x;
        double y;
        IKomponente const* parent;

    public:
        Komponente(double xPos, double yPos);
        
        double calcTotalPath() const override;
        double getX() const override;
        double getY() const override;
        double getXAbsolute() const override;
        double getYAbsolute() const override;
        double distance(IKomponente const* k) const override;
        IKomponente const* getParent() const override;
        //normales override, da nicht const in IKomponente
        void setParent(IKomponente const* p) override;
        void output(std::ostream& os) const override;

        virtual ~Komponente();
};

#endif //KOMPONENTE_H