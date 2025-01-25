#include "werkstueck.h"

Werkstueck::Werkstueck(double xPos, double yPos, double h, double w) : Komponente(xPos, yPos), height(h), width{w}, pathIsOptimized{false} {}

double Werkstueck::getHeight() const {
    return height;
}

double Werkstueck::getWidth() const {
    return width;
}

void Werkstueck::add(IKomponente* k) {
    //if(k != nullptr && k->getParent() != nullptr)
    //{
        k->setParent(this);
        komponenten.push_back(k);
        pathIsOptimized = false;
    //}
}

void Werkstueck::remove(IKomponente const* k) {
    if(k!= nullptr)
    {
        auto it_k = komponenten.begin();
        while(it_k != komponenten.end())
        {
            if(*it_k == k)
            {
                (*it_k)->setParent(nullptr);
                komponenten.erase(it_k);
                break;
            }
            ++it_k;
        }
    }
}

/*IKomponente const *Werkstueck::getChild(int i) const {
    for (auto element: komponenten) {
        if (i == 0) {
            return element;
        }
        i--;
    }
    return nullptr;
}*/

IKomponente const* Werkstueck::getChild(int i) const {
    auto it = komponenten.begin();
    for(int j = 0; j < i && it != komponenten.end(); ++j)
    {
        ++it;
    }
    return it != komponenten.end() ? *it : nullptr;
}

double Werkstueck::calcPathLength() const {
    double path = 0.0;
    Iterator it = komponenten.begin();
    Iterator before = it;
    path += this->distance(*it);

    while(it != komponenten.end()) {
        path += (*before)->distance(*it);
        before = it;
        ++it;
    }

    path += this->distance(*before);
    return path;
}

double Werkstueck::calcTotalPath() const {
    double totalPath = calcPathLength();
    Iterator it = komponenten.begin();

    while(it != komponenten.end()) {
        totalPath += (*it)->calcTotalPath();
        ++it;
    }
    return totalPath;
}

Iterator Werkstueck::getNearest(IKomponente const* pk) const {
    Iterator nearest = komponenten.begin();
    double minDistance = INFINITY;
    Iterator it = komponenten.begin();
    while(it != komponenten.end()) {
        double distance = (*it)->distance(pk);
        if (distance < minDistance) {
            minDistance = distance;
            nearest = it;
        }
        ++it;
    }
    return nearest;
}

// Solve approximately the Traveling salesman Problem (TSP) using a
// nearest neighbour strategy:
// round trip starts at the linking point of the Werkstueck.
// then go always to the nearest neighbour among the components
// that are not already on the new path
void Werkstueck::optimizePath() {
    if (!pathIsOptimized && komponenten.size() > 0) {
        // first call optimizePath for all Components,
        // which are of type Werkstueck recursively
        Iterator it = komponenten.begin();
        while (it != komponenten.end()) {
            Werkstueck* w = dynamic_cast<Werkstueck*>(*it);
            if (w != nullptr) {
                w->optimizePath();
            }
            ++it;
        }
        // Now determine a nearest neighbour-sorting
        // of all components
        DeList componentsSorted;
        IKomponente* pcurrent = this;
        Iterator nearest = getNearest(pcurrent);
        componentsSorted.push_back(*nearest);
        pcurrent = *nearest;
        komponenten.erase(nearest);
        while (komponenten.size() > 0) {
            nearest = getNearest(pcurrent);
            componentsSorted.push_back(*nearest);
            pcurrent = *nearest;
            komponenten.erase(nearest);
        }
        komponenten = componentsSorted;
        pathIsOptimized = true;
    }
}

void Werkstueck::output(std::ostream& os) const {

    std::string pad = "";
    IKomponente const* parent = this->getParent();
    while(parent != nullptr)
    {
        pad += "  ";
        parent = parent->getParent();
    }

    os << pad << "Werkstueck:" << std::endl;
    os << pad << "Verankerung: ";
       Komponente::output(os);
    os << std::endl;
    os << pad << "height: " << height << ", width: " << width << std::endl;
    os << pad << "Komponenten:" << std::endl;
    
    Iterator it = komponenten.begin();
    while(it != komponenten.end())
    {
        if (dynamic_cast<Werkstueck *>(*it) == nullptr)
        {
            os << pad;
        }
        os << *(*it);
        if (dynamic_cast<Werkstueck *>(*it) == nullptr)
        {
            os << std::endl;
        }
        ++it;
    }
}

Werkstueck::~Werkstueck() {}