#ifndef NOTARE_H
#define NOTARE_H

#include "Evaluare.h"

#include <iostream>
#include <string>
#include <vector>

class Notare
{
    std::vector<Evaluare> evaluari;
    int nota_finala = 0;

public:
    Notare(std::vector<Evaluare>, const float);

    std::vector<Evaluare> getEvals() const;
    float getNotaFinala() const;
    void calculNotaFinala();
};

#endif