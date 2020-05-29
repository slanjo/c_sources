#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct variable {

    int type;

    union {
        int i;
        float f;
        char *s;
    }data;
};

void print_variable(struct variable *v){
    switch(v->type){
        case 0:
            printf("%d\n", v->data.i);
            break;
        case 1:
            printf("%f\n", v->data.f);
            break;
        case 2:
            printf("%s\n", v->data.s);
            break;
    }




}

int main(){
    struct variable v;
    v.type = 0;
    v.data.i = 8;

    print_variable(&v);



	return 0;

}
