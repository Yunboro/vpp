#ifndef PRODUKTMITPREISHISTORY_H
#define PRODUKTMITPREISHISTORY_H

#include "produkt.h"

class ProduktMitPreisHistory : public Produkt {
    private:
        static const size_t N_PREISE_ALT = 5;
        //Anzahl der Objekte vom Typ ProduktMitPreisHistory
        static size_t counter;
        size_t npreise;
        double* preise_alt;

    public:
        //static-Methoden können nicht const sein
        static size_t getCounter();
        ProduktMitPreisHistory(std::string n, double p);
        void setPreis(double p) override;
        void output(std::ostream& os) const override;
        ProduktMitPreisHistory(const ProduktMitPreisHistory& rhs);
        ProduktMitPreisHistory& operator=(const ProduktMitPreisHistory& rhs);
        ~ProduktMitPreisHistory();
};

#endif //PRODUKTMITPREISHISTORY_H

