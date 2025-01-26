#ifndef SERIALIZER_H
#define SERIALIZER_H
#include "IKomponente.h"

class Serializer
{
    IKomponente const& ik;
public:
    Serializer(IKomponente const& root)
        : ik(root) {}
    void writeToJson(const char* fname) const;

    virtual ~Serializer() {}
};

#endif // SERIALIZER_H
