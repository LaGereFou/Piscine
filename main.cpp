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
void menu(BITMAP*buffer,BITMAP*menus,BITMAP*collisionmenus);
int main()
{
    //declaration des variables
    int s,h,d;// Coordonnées mouse et variable play musique
    BITMAP*menus;// Page menu
    BITMAP*collisionmenus;// Page de collision menu
    BITMAP*buffer;// Buffer
    MIDI*music;// Musique du générique
    int bleu,vert,rouge;// Couleurs pour getpixels


    // Il y aura du hasard
    srand(time(NULL));

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
    d=play_midi(music,1);

    show_mouse(screen);
    //chargement image
    blit(menus,buffer,0,0,0,0,SCREEN_W,SCREEN_H);

    rouge=makecol(255,0,0);
    vert=makecol(0,255,0);
    bleu=makecol(0,0,255);


        menu(buffer,menus,collisionmenus);// Appel du menu




    return 0;

} END_OF_MAIN();

/// MENU DU JEU
void menu(BITMAP*buffer,BITMAP*menus,BITMAP*collisionmenus)
{
    int a,b,c=0;// coordonnées de souris et getpixel
    int onetime = 0;


    blit(menus,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
    if(mouse_b&1 )
    {
        a=mouse_x;
        b=mouse_y;
        c=getpixel(collisionmenus,a,b);
    }

    //choix du menus


    if( c == makecol(255,0,0) && onetime==0 )
    {
        clear_bitmap(buffer);
        graphe_1();
        onetime=1;
    }
    else if( c == makecol(0,255,0) && onetime==0 )
    {
        std::cout << " Deuxieme graphe" << std::endl;
        onetime=1;
    }
    else if( c == makecol(0,0,255) && onetime==0)
    {
        std::cout << " troisieme graphe" << std::endl;
        onetime=1;
    }

    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    clear_bitmap(buffer);


}

void graphe_1()
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

}
