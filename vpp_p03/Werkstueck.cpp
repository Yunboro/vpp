#include "Werkstueck.h"


double Werkstueck::getHeight() const
{
    return height;
}

double Werkstueck::getWidth() const
{
    return width;
}

Iterator<IKomponente*> Werkstueck::getNearest(const IKomponente *pk) const
{
    Iterator<IKomponente*> a = components.begin();
    double d = pk->distance(*a);
    Iterator<IKomponente*> erg = a;
    ++a;
    while (a != components.end())
    {
        double tempD = pk->distance(*a);
        if (tempD < d)
        {
            d = tempD;
            erg = a;
        }
        ++a;
    }
    return erg;
}

void Werkstueck::add(IKomponente* k)
{
    k->setParent(this);
    components.push_back(k);
    pathIsOptimized = false;
}

void Werkstueck::remove(IKomponente const* k)
{
    Iterator<IKomponente*> it = components.begin();

    while(it != components.end())
    {
        if(k == *it)
        {
            // k->setParent(nullptr);
            (*it)->setParent(nullptr);
            components.erase(it);
            break;
        }
        ++it;
    }

    pathIsOptimized = false;
}

const IKomponente* Werkstueck::getChild(int i) const
{
    IKomponente* tmp = nullptr;
    if(i >= 0 && i < components.size())
    {
        Iterator<IKomponente*> it = components.begin();
        for(; i > 0 && it != components.end(); --i)
        {
            ++it;
        }
        tmp = *it;
    }
    return tmp;
}

double Werkstueck::calcTotalPath() const
{
    double erg = 0.0;
    Iterator<IKomponente*> it = components.begin();

    while(it != components.end())
    {
        erg += (*it)->calcTotalPath();
        ++it;
    }
    erg += this->calcPathLength();
    return erg;
}

double Werkstueck::calcPathLength() const
{
    double pathLength = 0.0;
    Iterator<IKomponente*> it = components.begin();
    Iterator<IKomponente*> before = it;
    if(it != components.end())
    {
        pathLength += this->distance(*it);
        ++it;
    }
    while(it != components.end())
    {
        pathLength += (*before)->distance(*it);
        before = it;
        ++it;
    }
    if(before != components.end())
    {
        pathLength += this->distance(*before);
    }
    return pathLength;
}

// Solve approximately the Traveling Sales Man Problem (TSP) using a
// nearses neighbour strategy:
// round trip starts at the linking point of the Werkstueck.
// then go always to the nearest neighbour among the components
// that are not already on the new path
void Werkstueck::optimizePath() {
    if (!pathIsOptimized && components.size() > 0)
    {
        // first call optimizePath for all Components,
        // which are of type Werkstueck recursively
        Iterator<IKomponente*> it = components.begin();
        while (it != components.end())
        {
            Werkstueck* w = dynamic_cast<Werkstueck*>(*it);
            if (w != nullptr)
            {
                w->optimizePath();
            }
        ++it;
        }
        // Now determine a nearest neighbour-sorting
        // of all components
        DeList<IKomponente*> componentsSortiert;
        IKomponente* pcurrent = this;
        Iterator<IKomponente*> nearest = getNearest(pcurrent);
        componentsSortiert.push_back(*nearest);
        pcurrent = *nearest;
        components.erase(nearest);
        while (components.size() > 0)
        {
            nearest = getNearest(pcurrent);
            componentsSortiert.push_back(*nearest);
            pcurrent = *nearest;
            components.erase(nearest);
        }
        components = componentsSortiert;
        pathIsOptimized = true;
    }
}

void Werkstueck::output(std::ostream& os) const
 {
     std::string blanks = "";
     const IKomponente* tParent = getParent();
     while(tParent != nullptr)
     {
         blanks += " ";
         tParent = tParent->getParent();
     }
     os << blanks << "Werkstueck:" << endl;
     os << blanks << "Verankerung: (" << getX();
     os << ", " << getY();
     os << ")" << endl;
     os << blanks << "heigh: " << height;
     os << ", width: " << width;
     os << endl;
     os << blanks << "Komponenten:" << endl;

     Iterator<IKomponente*> it = components.begin();
     while(it != components.end())
     {
         if(dynamic_cast<Werkstueck*>(*it) == nullptr)
         {
             os << blanks;
         }
         os << *(*it);
         if(dynamic_cast<Werkstueck*>(*it) == nullptr)
         {
             os << endl;
         }
         ++it;
     }
 }

QJsonObject Werkstueck::toJson() const
{

    QJsonArray temp;

    Iterator<IKomponente*> it;
    for(it = components.begin(); it!=components.end(); ++it)
    {
       temp.push_back((*it)->toJson());
    }

    QJsonObject result = Komponente::toJson();
    result["components"] = temp;
    result["height"] = height;
    result["width"] = width;
    result["pathIsOptimized"] = pathIsOptimized;
    result["type"] = "Werkstueck";

    return result;
}



































/////////////////////////////////////////////////////////////////////////
/*
void Werkstueck::output(std::ostream &os) const
{
    std::string leer = "";
    IKomponente const* eltern = this->getParent();

    while(eltern != nullptr)
    {
        leer += " ";
        eltern = eltern->getParent();
    }

    os << leer << "Werkstueck:" << std::endl;
    os << leer << "Verankerung: ";
    Komponente::output(os);
    os << std::endl;
    os << leer << "height: " << height << ", width: " << width << std::endl;
    os << leer << "Komponenten:" << std::endl;
    Iterator it = components.begin();
    while(it != components.end())
    {
        if(dynamic_cast<Werkstueck*>(*it) == nullptr)
        {
            os << leer;
        }
        os << *(*it);
        if(dynamic_cast<Werkstueck*>(*it) == nullptr)
        {
            os << std::endl;
        }
        ++it;
    }
}
*/
