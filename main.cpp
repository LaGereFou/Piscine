#include <iostream>
#include "Graphe.h"
#include "Aretes.h"
#include "Sommet.h"
#include <vector>
#include <string>

int main()
{
    std::vector<Aretes> test;
    Graphe a;
    int cmp = 1;
    a.recuperation();
    std::cout << a.getnom()<< std::endl;
    std::cout <<   a.getnbaretes() << std::endl;
    for (int i =0; i< a.getnbaretes(); i++)
    {
        std::cout << " Voici l'arete " << cmp <<std::endl<<std::endl;
        std::cout <<   a.getaretes()[i].gets1().getnom()<< "  ";
        std::cout <<   a.getaretes()[i].gets1().getx()<< "  ";
        std::cout <<   a.getaretes()[i].gets1().gety()<< std::endl;
        std::cout <<   a.getaretes()[i].gets2().getnom() << "  ";
        std::cout <<   a.getaretes()[i].gets2().getx()<< "  ";
        std::cout <<   a.getaretes()[i].gets2().gety()<< std::endl<<std::endl;

        cmp++;

    }
    a.sauvegarde();


    return 0;
}
