#include "Bohrung.h"
#include <iostream>

using std::cout;
using std::endl;

QJsonObject Bohrung::toJson() const
{
    QJsonObject result = Komponente::toJson();
    result["diameter"] = diameter;
    result["type"] = "Bohrung";

    return result;
}

