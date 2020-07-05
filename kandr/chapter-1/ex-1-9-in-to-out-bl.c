#include <stdio.h>

//exercise 1.9 page 20, replace one ore more blanks with a single blanks


int main()
{
    int nl, tb, bl, counter, bl_count;
    nl = tb = bl = counter = 0;
    while((counter = getchar()) != EOF){
        if (counter ==  ' '){
            ++bl;
            if ( bl >= 1){
                ++bl;
                putchar(' ');
            }
//            putchar(counter);
        }
        else 
           putchar(counter); 
}

}
