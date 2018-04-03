#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include "Aretes.h"
#include <string>

class Graphe
{
    public:
        Graphe();
        virtual ~Graphe();

        ///Getter/Setter
        int &getordre();
        std::vector<Aretes> &getaretes();
        std::string &getnom();
        int &getnbaretes();

        ///Fonctions
        void recuperation();
        void sauvegarde();


    private:
        std::string m_nom;
        int m_ordre;
        std::vector<Aretes> m_aretes;
        int m_nbaretes;

};

#endif // GRAPHE_H
