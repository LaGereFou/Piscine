#include "../include/Sommet.h"
#include <allegro.h>

Sommet::Sommet()
{
    //ctor
}

Sommet::~Sommet()
{
    //dtor
}

std::string &Sommet::getnom()
{
    return m_nom;
}

int &Sommet::getx()
{
    return m_x;
}

int &Sommet::gety()
{
    return m_y;
}
