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
    printf("Couldn't initialize keyboard\n");
    return 1;
}
//to make sure consistent speed we require a timer and an event queue
ALLEGRO_TIMER* timer = al_create_timer(1.0 /30.00);
if (!timer){
    printf("Couldn't initialize timer\n");
    return 1;
}
//create a queue for input events
ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
if (!queue){
    printf("Couldn't initialize queue\n");
    return 1;
}
//then we draw a window 640 by 480
ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
if (!disp){
    printf("Couldn't initialize display");
    return 1;
}
//use build in pixel font
ALLEGRO_FONT* font = al_create_builtin_font();
if (!font){
    printf("Couldn't initialize font");
    return 1;
}


al_register_event_source(queue, al_get_keyboard_event_source());
al_register_event_source(queue, al_get_display_event_source(disp));
al_register_event_source(queue, al_get_timer_event_source(timer));

bool done = true;
bool redraw = true;
ALLEGRO_EVENT event;
//start the game timer
al_start_timer(timer);
//Game Loop - loops continuously
while(1){
    al_wait_for_event(queue, &event);
//advance a frame if the timer fired an event
    switch(event.type){
        case ALLEGRO_EVENT_TIMER: 
        //game logic goes hire.
        redraw = true;
        break;
        case ALLEGRO_EVENT_KEY_DOWN:
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
    }

    if(event.type == ALLEGRO_EVENT_TIMER)
        redraw = true;
//else close the window if the user pressed a key or clicked the "x" button on the window
    else if((event.type == ALLEGRO_EVENT_KEY_DOWN) || (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE))
        break;
//if the we haven't rendered since last "advance-frame" and if no other events - we RENDER a new frame
    if (redraw && al_event_queue_is_empty(queue)) {
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Hello Danny!");
        al_flip_display();
        redraw = false;
    }
}
al_destroy_font(font);
al_destroy_display(disp);
al_destroy_timer(timer);
al_destroy_event_queue(queue);
return 0;
}

