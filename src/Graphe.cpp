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

    std::ifstream fichier(m_nom  + ".txt");

    Sommet s1, s2;
    Aretes b;
    unsigned int cmp = 1;



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

/*    fichier.close();

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

    }*/

}


void Graphe::tracerarete(BITMAP *fond, BITMAP *sommet1, BITMAP *sommet2)
{
    int x1, y1, x2, y2, i;
    x1=getaretes()[i].gets1().getx();
    y1=getaretes()[i].gets1().gety();
    x2=getaretes()[i].gets2().getx();
    y2=getaretes()[i].gets2().gety();
    blit(sommet1, fond, x1, y1, 0, 0, SCREEN_W, SCREEN_H);
    blit(sommet2, fond, x2, y2, 0, 0, SCREEN_W, SCREEN_H);
    fastline(fond,x1,y1,x2,y2,makecol(0,0,255));
    fastline(fond,x2-10,y2-11,x2,y2,makecol(0,0,255));
    fastline(fond,x2-10,y2+11,x2,y2,makecol(0,0,255));
}

void Graphe::tracergraphe()
{
    BITMAP *fond;
    BITMAP *sommet1;
    BITMAP *sommet2;
    std::string nom;
    int x, y;

    for(int i=0; i<getnbaretes(); i++)
    {
        nom = "images/" + getaretes()[i].gets1().getnom() + ".bmp" ;
        x = getaretes()[i].gets1().getx();
        y = getaretes()[i].gets1().gety();

        std::cout << nom << std::endl;
        sommet1 = load_bitmap(nom.c_str() , NULL);
        blit(sommet1, fond, 0 ,0,x,y, SCREEN_W, SCREEN_H);

        nom = "images/" + getaretes()[i].gets2().getnom() + ".bmp" ;
        std::cout << nom << std::endl;
        sommet2 = load_bitmap(nom.c_str() , NULL);
        blit(sommet2, fond, 0,0,x,y, SCREEN_W, SCREEN_H);

    }

    //blit()

    /**BITMAP*sommet1;
    std::string nom;
for(int i=0; i<a.getnbaretes(); i++)
    {
        nom = "images/" + a.getaretes()[i].gets1().getnom() + ".bmp" ;
                        std::cout << "coco" << std::endl;

        sommet1 = load_bitmap(nom.c_str() , NULL);
                std::cout << nom << std::endl;

        blit(sommet1, screen, 0,0,0,0, SCREEN_W, SCREEN_H);
        sommet1=load_bitmap((getaretes()[i].gets1().getnom() + ".bmp").c_str(),NULL);
        blit(sommet1, screen, getaretes()[i].gets1().getx(), getaretes()[i].gets1().gety(), 0 , 0 , SCREEN_W, SCREEN_H);
        sommet2=load_bitmap((getaretes()[i].gets2().getnom() + ".bmp").c_str(),NULL);
        tracerarete(fond,sommet1,sommet2);

    }**/
}
