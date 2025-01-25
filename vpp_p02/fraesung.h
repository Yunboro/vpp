#ifndef FRAESUNG_H
#define FRAESUNG_H
#include "bohrung.h"

class Fraesung : public Bohrung
{
    private:
        double length, angle;

    public:
        Fraesung(double x_, double y_, double diam, double l, double a = 0.0);

        double calcTotalPath() const override;

        //Diese Attribute wurden erst mit der Fraesung eingeführt
        double getLength() const;
        double getAngle() const;
        double getEndX() const;
        double getEndY() const;
        
        void output(std::ostream& os) const override;

        ~Fraesung();
};

#endif //FRAESUNG_H