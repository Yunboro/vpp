#include "Komponente.h"
#include <cmath>

void Komponente::output(std::ostream& os) const
{
    os << "(" << x << ", " << y << ")" ;
}

void Komponente::setParent(const IKomponente *p)
{
    parent = p;
}

IKomponente const* Komponente::getParent() const
{
    return parent;
}

double Komponente::calcTotalPath() const
{
    return 0.0;
}

double Komponente::getXAbsolute() const
{
    double X = x;
    if(parent != nullptr)
    {
        X = x + parent->getXAbsolute();
    }
    return X;
}

double Komponente::getYAbsolute() const
{
    double Y = y;
    if(parent != nullptr)
    {
        Y = y + parent->getYAbsolute();
    }
    return Y;
}

double Komponente::distance(const IKomponente *k) const
{
    double dX, dY;
    dX = getXAbsolute() - k->getXAbsolute();
    dY = getYAbsolute() - k->getYAbsolute();
    return (sqrt(dX*dX + dY*dY));
}

QJsonObject Komponente::toJson() const
{
    bool hasParent = false;
    if (getParent()!=nullptr)
    {
        hasParent=true;
    }
    QJsonObject result;

    result["type"] = "Komponente";
    result["hasParent"] = hasParent;
    result["x"] = x;
    result["y"] = y;
    return result;
}
