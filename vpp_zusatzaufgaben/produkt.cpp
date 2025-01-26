#include "produkt.h"

Produkt::Produkt(std::string n, double p) : name{n}, preis{p} {}

void Produkt::setName(std::string n) {
    name = n;
}

std::string Produkt::getName() const { return name; }

double Produkt::getPreis() const { return preis; }

void Produkt::setPreis(double p) { preis = p; }

void Produkt::output(std::ostream& os) const {
    os << "Name: " << std::setw(10) << std::left << name
       << ", Preis: " << std::fixed << std::setprecision(2) << std::right << std::setw(9) << preis ;
}

Produkt::~Produkt() {}