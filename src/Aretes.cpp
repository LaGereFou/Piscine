#include <iostream>
#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/Aretes.h"

Aretes::Aretes()
{
    //ctor
}
Aretes::~Aretes()
{
    //dtor
}
Sommet &Aretes::gets1()
{
    return m_s1;
}

Sommet &Aretes::gets2()
{
    return m_s2;
}

int &Aretes::getpoids()
{
    return m_poids;
}
