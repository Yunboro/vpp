#include "produktmitpreishistory.h"

size_t ProduktMitPreisHistory::counter = 0;

size_t ProduktMitPreisHistory::getCounter() {
    return counter;
}

ProduktMitPreisHistory::ProduktMitPreisHistory(std::string n, double p) : Produkt(n, p), npreise(0) {
    preise_alt = new double[N_PREISE_ALT];
}

void ProduktMitPreisHistory::setPreis(double p) {
    if (npreise < N_PREISE_ALT) {
        preise_alt[npreise] = Produkt::getPreis();
        ++npreise;
    } 
    else {
        for (size_t i = 1; i < N_PREISE_ALT; ++i) {
            preise_alt[i - 1] = preise_alt[i];
        }
        preise_alt[N_PREISE_ALT - 1] = Produkt::getPreis();
    }
    Produkt::setPreis(p);
}

void ProduktMitPreisHistory::output(std::ostream& os) const {
    os << "Name: " << std::setw(10) << std::left << Produkt::getName()
       << ", Preis: " << std::fixed << std::setprecision(2) << std::right << std::setw(9) << Produkt::getPreis()
       << "\nPreis History:\n";
    for (size_t i = 0; i < npreise; ++i) {
        os << preise_alt[i] << "\n";
    }
}

ProduktMitPreisHistory::ProduktMitPreisHistory(const ProduktMitPreisHistory& rhs) : Produkt(rhs), npreise(rhs.npreise) {
    preise_alt = new double[N_PREISE_ALT];
    for (size_t i = 0; i < npreise; ++i) {
        preise_alt[i] = rhs.preise_alt[i];
    }
}

ProduktMitPreisHistory& ProduktMitPreisHistory::operator=(const ProduktMitPreisHistory& rhs) {
    if (this != &rhs) {
        Produkt::operator=(rhs);
        npreise = rhs.npreise;
        delete[] preise_alt;
        preise_alt = new double[N_PREISE_ALT];
        for (size_t i = 0; i < npreise; ++i) {
            preise_alt[i] = rhs.preise_alt[i];
        }
    }
    return *this;
}
        
ProduktMitPreisHistory::~ProduktMitPreisHistory() {
    delete[] preise_alt;
}