#ifndef PRODUKT_H
#define PRODUKT_H

#include "iprodukt.h"
#include <iomanip>

class Produkt : public IProdukt {
    private:
        std::string name;
        double preis;
    public:
        Produkt(std::string n, double p);
        void setName(std::string n);
        std::string getName() const override;
        double getPreis() const override;
        void setPreis(double p) override;
        void output(std::ostream& os) const override;
        
        virtual ~Produkt();
};



#endif //PRODUKT_H