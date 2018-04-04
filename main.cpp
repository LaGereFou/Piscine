#include <iostream>
#include "include/Graphe.h"
#include <allegro.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;
void menu(BITMAP*buffer,BITMAP*main,BITMAP*menus,BITMAP*collisionmenus,BITMAP*regles);
int main()
{
    //declaration des variables
    int s,h,d;// Coordonnées mouse et variable play musique
    BITMAP*menus;// Page menu
    BITMAP*collisionmenus;// Page de collision menu
    BITMAP*main;// Curseur sangoku
    BITMAP*buffer;// Buffer
    MIDI*music;// Musique du générique
    int bleu,vert,rouge;// Couleurs pour getpixels
    BITMAP *regles;// Page avec les règles du jeu


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


    //boucle de jeu
    while(!(getpixel(collisionmenus,s,h)==rouge))
    {
        if(mouse_b&1)
        {
            s=mouse_x;
            h=mouse_y;
        }

        menu(buffer,main,menus,collisionmenus,regles);// Appel du menu


    }
    return 0;

} END_OF_MAIN();

/// MENU DU JEU
void menu(BITMAP*buffer,BITMAP*main,BITMAP*menus,BITMAP*collisionmenus,BITMAP*regles)
{

    blit(menus,buffer,0,0,0,0,SCREEN_W,SCREEN_H);
    int a,b,c;// coordonnées de souris et getpixel

    draw_sprite(buffer,main,mouse_x-25,mouse_y-30);


    if(mouse_b&1)
    {
        a=mouse_x;
        b=mouse_y;
        c=getpixel(collisionmenus,a,b);
    }

    //choix du menus
    switch(c)
    {
    case 255:

        clear_bitmap(buffer);

        break;

    case 65680:

        break;






    }

    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    clear_bitmap(buffer);


}
