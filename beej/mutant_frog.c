#include <stdio.h>
#include <ctype.h>
#include <string.h>


struct mutantfrog {
int num_legs;
int num_eyes;
};
void build_beejs_frog(struct mutantfrog *f)
{
f->num_legs = 10;
f->num_eyes = 1;
}


int main(){



struct mutantfrog rudolph;
struct mutantfrog jude;

build_beejs_frog(&rudolph);
build_beejs_frog(&jude);
/* passing a pointer to the struct */
printf("leg count: %d\n", rudolph.num_legs); /* prints "10" */
printf("eye count: %d\n", rudolph.num_eyes); /* prints "1" */

printf("leg count: %d\n", jude.num_legs); /* prints "10" */
printf("eye count: %d\n", jude.num_eyes); /* prints "1" */




	return 0;

}
