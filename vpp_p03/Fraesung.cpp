#include "Fraesung.h"

double Fraesung::getEndX() const
{
    return (cos(this->getAngle()) * this->getLength()) + this->getX();
}

double Fraesung::getEndY() const
{
    return (sin(this->getAngle())* this->getLength()) + this->getY();
}

double Fraesung::calcTotalPath() const
{
    return 2 * getLength();
}

QJsonObject Fraesung::toJson() const
{
    QJsonObject result = Komponente::toJson();
    result["angle"] = getAngle();
    result["diameter"] = getDiameter();
    result["length"] = getLength();
    result["x"] = getX();
    result["y"] = getY();
    result["type"] = "Fraesung";

    return result;
}
