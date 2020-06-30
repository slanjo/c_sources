//This code is used to manage a spaceship
#include <allegro5/allegro.h>
#include <allegro5/drawing.h>
typedef struct {
    float sx;
    float sy;
    float heading;
    float speed;
    int gone;
    ALLEGRO_COLOR color;
} Spaceship;
void draw_ship(Spaceship * s);

int main(){
    Spaceship *s;
    draw_ship(s);


}


    
    
    
void draw_ship(Spaceship* s){
    ALLEGRO_TRANSFORM transform;
    al_identity_transform(&transform);
    al_rotate_transform(&transform, DEGREES(s->heading));
    al_translate_transform(&transform, s->sx, s->sy);
    al_use_transform(&transform);
    al_draw_line(-8, 9, 0, -11, s->color, 3.0f);
    al_draw_line(0, -11, 8, 9, s->color, 3.0f);
    al_draw_line(-6, 4, -1, 4, s->color, 3.0f);
    al_draw_line(6, 4, 1, 4, s->color, 3.0f);

}
