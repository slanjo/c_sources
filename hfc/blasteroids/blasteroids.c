//This code is used to handle the core of the game.
//It listens for keypresses, runs a time, 
//keeps track of other spaceships, rocks, and blasts,
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/system.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
int main(){

//initialize allegro system and setup bare essentials required for the program 
if (!al_init()){
    printf("Couldn't initialize allegro\n");
    return 1;
}
//because keyboard input is not mandatory, we must initialize the keyboard
if (!al_install_keyboard()){
    printf("Couldn't initialize allegro\n");
    return 1;
}
//to make sure consistent speed we require a timer and an event queue
ALLEGRO_TIMER* timer = al_create_timer(1.0 /30.00);
if (!timer){
    printf("Couldn't initialize timer\n");
    return 1;
}
ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
if (!queue){
    printf("Couldn't initialize queue\n");
    return 1;
}



}


