#include "produktmitpreishistory.h"

static size_t ProduktMitPreisHistory::counter = 0;

static size_t ProduktMitPreisHistory::getCounter() const {
    return counter;
}

ProduktMitPreisHistory(std::string n, double p) : Produkt(n, p), npreise(0) {
    preise_alt = new double[N_PREISE_ALT];
}

void ProduktMitPreisHistory::setPreis(double p) {
    if(npreise < N_PREISE_ALT) {
        preise_alt[++npreise] = getPreis();
        setPreis(p);
    }
    {
        
    } // namespace name
    )
        void output(std::ostream& os) const;
        ProduktMitPreisHistory(const ProduktMitPreisHistory& rhs);
        ProduktMitPreisHistory& operator=(const ProduktMitPreisHistory& rhs);
        ~ProduktMitPreisHistory();