#include "Graphe.h"
#include <vector>
#include "Aretes.h"
#include <fstream>
#include <iostream>
#include <string>

Graphe::Graphe()
:m_nom("president")
{
    //ctor
}

Graphe::~Graphe()
{
    //dtor
}

int &Graphe::getordre()
{
    return m_ordre;
}

std::vector<Aretes> &Graphe::getaretes()
{
    return m_aretes;
}

std::string &Graphe::getnom()
{
    return m_nom;
}

void Graphe::sauvegarde()
{
    std::ifstream fichier(m_nom + ".txt");

    if(!fichier)
    {
        std::cerr << "Impossible d'ouvrir " << m_nom << std::endl;
    }

}

void Graphe::recuperation()
{
    std::ifstream fichier("president.txt");

    if(!fichier)
    {
        std::cerr << "Impossible d'ouvrir president.txt";
    }

}
