#ifndef SOMMET_H
#define SOMMET_H
#include <allegro.h>
#include <string>

class Sommet
{
    public:
        Sommet();
        virtual ~Sommet();

        std::string &getnom();
        int &getx();
        int &gety();

    protected:

    private:
        std::string m_nom;
        int m_x, m_y;
};

#endif // SOMMET_H
