#include <iostream>
#include <fstream>
#include "../include/Graphe.h"
#include "../include/Aretes.h"
#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>

Graphe::Graphe()
:m_nom("savane")
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

int &Graphe::getnbaretes()
{
    return m_nbaretes;
}

void Graphe::sauvegarde()
{
    std::ofstream fichier(m_nom + ".txt", std::ios::trunc);

    if(!fichier)
    {
        std::cerr << "Impossible d'ouvrir " << m_nom << std::endl;
    }

    fichier << m_ordre << std::endl;
    fichier << m_nbaretes << std::endl;

    for(int i = 0; i < m_nbaretes;i++)
    {
        fichier << m_aretes[i].gets1().getnom()<< " ";
        fichier << m_aretes[i].gets1().getx()<< " ";
        fichier << m_aretes[i].gets1().gety()<< " ";
        fichier << m_aretes[i].gets2().getnom()<< " ";
        fichier << m_aretes[i].gets2().getx()<< " ";
        fichier << m_aretes[i].gets2().gety() << std::endl;

    }

    fichier.close();
}

void Graphe::recuperation()
{
<<<<<<< HEAD
    std::ifstream fichier(m_nom  + ".txt");
=======
    Sommet s1, s2;
    Aretes b;
    unsigned int cmp = 1;

    std::ifstream fichier(m_nom + ".txt");
>>>>>>> 9ecc2ed9e1a608b48b81998168922fb7a243d6fa

    if(!fichier)
    {
        std::cerr << "Impossible d'ouvrir president.txt";
    }

    ///Récupération graphe
    fichier >> m_ordre;
    fichier >> m_nbaretes;

    std::cout << getnbaretes();
    for(int i = 0; i < 11*m_nbaretes; i++)
    {
        fichier >> s1.getnom();
        fichier >> s1.getx();
        fichier >> s1.gety();
        fichier >> s2.getnom();
        fichier >> s2.getx();
        fichier >> s2.gety();
        b.gets1() = s1;
        b.gets2() = s2;
        m_aretes.push_back(b);


    }

    fichier.close();

    for (int i =0; i< 11*m_nbaretes; i++)
    {
        std::cout << " Voici l'arete " << cmp <<std::endl<<std::endl;
        std::cout <<   getaretes()[i].gets1().getnom()<< "  ";
        std::cout <<   getaretes()[i].gets1().getx()<< "  ";
        std::cout <<   getaretes()[i].gets1().gety()<< std::endl;
        std::cout <<   getaretes()[i].gets2().getnom() << "  ";
        std::cout <<   getaretes()[i].gets2().getx()<< "  ";
        std::cout <<   getaretes()[i].gets2().gety()<< std::endl<<std::endl;

        cmp++;

    }

}
