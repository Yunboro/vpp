#ifndef IPRODUKT_H
#define IPRODUKT_H

#include <iostream>
#include <string>

class IProdukt
{
    public:
        virtual std::string getName() const = 0;
        virtual double getPreis() const = 0;
        virtual void setPreis(double p) = 0;
        virtual void output(std::ostream& os) const = 0;
        
        virtual ~IProdukt();
};

#endif //IPRODUKT_H