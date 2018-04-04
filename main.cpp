#include <iostream>
#include <fstream>
#include "include/Graphe.h"
#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


using namespace std;

void graphe_1();
void graphe_2();
void graphe_3();
void menu();
void init_allegro();
void tracerarete(BITMAP *fond, BITMAP *sommet1, BITMAP *sommet2);
void tracergraphe(BITMAP *fond);



int main()
{
Graphe a;
a.recuperation();

    //initialisation allegro
    init_allegro();

    /** Il y aura du hasard
    srand(time(NULL));**/



    menu();// Appel du menu


    return 0;

}
END_OF_MAIN();

void init_allegro()
{
    // Lancer allegro et le mode graphique
    allegro_init();
    install_keyboard();
    install_mouse();
    install_timer();
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);

    // Lancer une fonction temps
    /* LOCK_VARIABLE(timer_s);
     LOCK_VARIABLE(timer_m);
     LOCK_FUNCTION(faire_timer);
     install_int_ex(faire_timer, SECS_TO_TIMER(1));*/

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

}

/// MENU DU JEU
void menu()
{
    int a,b,c=0, d;// coordonnées de souris et getpixel
    int rouge = makecol(255, 0, 0), vert = makecol(0,255,0), bleu = makecol(0,0,255);
    MIDI*music;// Musique du générique
    //declaration des variables
    BITMAP*menus;// Page menu
    BITMAP*collisionmenus;// Page de collision menu
    BITMAP*buffer;// Buffer


    //chargement image music
    menus=load_bitmap("Menu_image.bmp",NULL);
    if (!menus)
    {
        allegro_message("Problème menus");
    }
    collisionmenus=load_bitmap("Menu_collision.bmp",NULL);
    if (!collisionmenus)
    {
        allegro_message("Problème collisionmenus");
    }

    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    if (!buffer)
    {
        allegro_message("Problème création bitmap");
    }


    music=load_midi("Johnny.mid");

    if (!music)
    {
        allegro_message("Problème musique");
    }

    d = play_midi(music,1);

    show_mouse(screen);


    while(!key[KEY_ESC])
    {
        blit(menus,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        //récupération des données de la souris
        if(mouse_b&1)
        {
            b = mouse_x;
            a = mouse_y;
            c = getpixel(collisionmenus,a,b);
        }


        //choix du menus
        if( a > 115 && a < 370 && b > 230 && b <300 )
        {
            clear_bitmap(screen);
            graphe_1();
            c = makecol(0,0,0);
            a = 0;
            b = 0;
        }
        else if( a > 115 && a < 370 && b > 185 && b < 385)
        {
            clear_bitmap(screen);
            graphe_2();
            a = 0;
            b = 0;

        }
        else if( a > 115 && a < 370  && b > 410 && b < 475)
        {
            clear_bitmap(screen);
            graphe_3();
            a = 0;
            b = 0;

        }


    }

    clear_bitmap(buffer);



}

void Chargements_AnimauxSavanes()
{
    BITMAP* Animal;
    BITMAP* Animaux_collison;
    int a = makecol(255,0,0),
    b = makecol(0,255,0),
    c = makecol(0,0,255),
    d = makecol(255,255,0),
    e = makecol(0,255,255),
    f = makecol(255,0,255),
    g = makecol(255,128,128),
    h = makecol(128,128,128),
    i = makecol(255,128,0),
    j = makecol(0,128,64),
    k = makecol(128,64,0),
    l = makecol(0,128,192),
    m = makecol(128,0,64),
    n = makecol(128,128,0);
    int x,y,choix;

    Animaux_collison = load_bitmap("Images/Animaux_savane_collision.bmp", NULL);
    if(!Animaux_collison)
    {
        allegro_message("Problème Animaux collision");
    }

    x = mouse_x;
    y = mouse_y;
    std::string nom;
    choix = getpixel(Animaux_collison,x,y);


 /*   if(choix==a)
    {
        nom = "Babouin";
    }
        break;
    case b :
        nom = "Buffle";
        break;
    case c :
        nom = "Eléphant";
        break;
    case d :
        nom = "Fourmi";
        break;
    case e :
        nom = "Vegetaux";
        break;

    case f :
        nom = "Gazelle";
        break;
    case g :
        nom = "Gnou";
        break;
    case h :
        nom = "Guepard";
        break;
    case i :
        nom = "Hippopotame";
        break;

    case j :
        nom = "Hyene";
        break;
    case k :
        nom = "Leopard";
        break;
    case l :
        nom = "Lion";
        break;
    case m :
        nom = "phacochère";
        break;
    case n :
        nom = "zebre";
        break;
    default :
        nom = "STOP";
    }



    //initialisation des bitmaps
    if( nom != "STOP")
    {
    Animal = load_bitmap("Images/" + nom + ".bmp", NULL);
    if(!Phacochere)
    {
        allegro_message("Problème animal");
    }
    }*/


}

void graphe_1()
{
    Graphe a;
    a.recuperation();
    int x = 0, y = 0;
    bool test = false;

    BITMAP* buffer;
    BITMAP* savane;
    BITMAP* Menu_sommets;



    //initialisation des bitmaps
    savane = load_bitmap("Images/Savane.bmp", NULL);
    if(!savane)
    {
        allegro_message("Problème Savane");
    }

    Menu_sommets = load_bitmap("Ajout_sommets.bmp", NULL);
    if(!savane)
    {
        allegro_message("Problème menu sommets");
    }

    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    if(!buffer)
    {
        allegro_message("Problème Buffer_Savane");

    }

    show_mouse(screen);

    while( test != true && !key[KEY_ESC])
    {

        //Affichage fond de graphe
        blit(savane, buffer, 0,0,0,0, SCREEN_W, SCREEN_H);
        blit(buffer,screen, 0,0,0,0, SCREEN_W, SCREEN_H);

        a.tracergraphe(savane);


        if(mouse_b&1)
        {
            x = mouse_x;
            y = mouse_y;
            std::cout << "x = "<< x <<std::endl;
            std::cout << "y = "<< y <<std::endl;
        }

        if( x > 710 && y < 55)
        {

            test =  true;
        }


    }



    //affichage graphe sur console
    std::cout << a.getnom()<< std::endl;
    std::cout <<   a.getnbaretes() << std::endl;


    for(int i = 0; i < a.getnbaretes(); i++)
    {


        std::cout << " Voici l'arete " << i + 1 <<std::endl<<std::endl;
        std::cout <<   a.getaretes()[i].gets1().getnom()<< "  ";
        std::cout <<   a.getaretes()[i].gets1().getx()<< "  ";
        std::cout <<   a.getaretes()[i].gets1().gety()<< std::endl;
        std::cout <<   a.getaretes()[i].gets2().getnom() << "  ";
        std::cout <<   a.getaretes()[i].gets2().getx()<< "  ";
        std::cout <<   a.getaretes()[i].gets2().gety()<< std::endl<<std::endl;

    }


    clear_bitmap(screen);
}


void graphe_2()
{
    std::cout << "graphe 2" << std::endl;
}

void graphe_3()
{
    std::cout << "graphe 3" << std::endl;
}




