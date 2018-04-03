#ifndef ARETES_H
#define ARETES_H

#include "Sommet.h"


class Aretes
{
    public:
        Aretes();
        virtual ~Aretes();

        Sommet &gets1();
        Sommet &gets2();
        int &getpoids();

    private:
        Sommet m_s1;
        Sommet m_s2;
        int m_poids;
};

#endif // ARETES_H
