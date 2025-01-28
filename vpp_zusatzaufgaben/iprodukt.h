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

inline std::ostream& operator<<(std::ostream& os, const IProdukt& ip) {
    ip.output(os);
    return os;
}

#endif //IPRODUKT_H