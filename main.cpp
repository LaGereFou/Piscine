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
void menu();
void init_allegro();



int main()
{


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
        if( c == rouge )
        {
            clear_bitmap(screen);
            graphe_1();
            c = makecol(0,0,0);
        }
        else if( c == vert)
        {
            std::cout << " Deuxieme graphe" << std::endl;
            clear_bitmap(screen);
        }
        else if( c == vert)
        {
            std::cout << " troisieme graphe" << std::endl;
            clear_bitmap(screen);
        }


    }

    clear_bitmap(buffer);



}

void graphe_1()
{
    Graphe a;
    a.recuperation();
    int x = 0, y = 0;
    bool test = false;

    BITMAP* buffer;
    BITMAP* savane;

    //initialisation des bitmaps
    savane = load_bitmap("Images/Savane.bmp", NULL);
    if(!savane)
    {
        allegro_message("Problème Savane");
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


        if(mouse_b&1)
        {
            x = mouse_x;
            y = mouse_y;
            std::cout << "x = "<< x <<std::endl;
            std::cout << "y = "<< y <<std::endl;
        }

        if( x > 710 && y < 55)
        {
                        std::cout << "okk"<< std::endl;

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
