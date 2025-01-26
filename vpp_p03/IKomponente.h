#ifndef IKOMPONENTE_H
#define IKOMPONENTE_H
#include <iostream>
#include <qjsonobject.h>

using std::cout;
using std::endl;

class IKomponente
{
public:
    virtual double calcTotalPath() const = 0;
    virtual double getXAbsolute() const = 0;
    virtual double getYAbsolute() const = 0;
    virtual double getX() const = 0;
    virtual double getY() const = 0;
    virtual double distance(IKomponente const *k) const = 0;
    virtual IKomponente const* getParent() const = 0;

    virtual QJsonObject toJson() const = 0;

    virtual void setParent(IKomponente const *p) = 0;
    virtual void output(std::ostream& os) const = 0;
    virtual ~IKomponente();
};

inline std::ostream& operator<<(std::ostream& os, const IKomponente& ik)
{
    ik.output(os);
    return os;
}

#endif // IKOMPONENTE_H
