//qsort program HFC page 326
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int width;
    int height;
} rectangle;

//int qsort(void *array, size_t length, size_t item_size, int (*compar)(const void *, const void*));
int compar_scores(const void *, const void *);
int compar_scores_desc(const void *, const void *);
int compar_areas(const void *, const void *);
int compar_names(const void *, const void *);
int compar_areas_desc(const void *, const void *);
int compar_names_desc(const void *, const void *);

int main(){
    int scores[] = {543,323,32,554,11,3,112};
    int i;
    qsort(scores, 7, sizeof(int), compar_areas_desc);
    puts("These are the scores in order:");
    for (i = 0; i < 7; i++){
            printf("score = %i\n", scores[i]);
                    }
    char *names[] = {"Karen","Mark","Brett","Molly"};
    qsort(names, 4, sizeof(char*), compar_names);
    puts("These are the names in order:");
    for (i = 0; i < 4; i++){
        printf("%s\n", names[i]);
        }
                    



	return 0;
}

int compar_scores(const void *pt1, const void *pt2){
    int a = *(int*)pt1;
    int b = *(int*)pt2;
    return a - b;
}
int compar_scores_desc(const void *pt1, const void *pt2){
    int a = *(int*)pt1;
    int b = *(int*)pt2;
    return b - a;
}
int compar_areas(const void *pt1, const void *pt2){
    rectangle *ra = (rectangle*)pt1; 
    rectangle *rb = (rectangle *)pt2; 
    int area_a = ra->height * ra->width;
    int area_b = rb->height * rb->width;
    return area_a - area_b;
}
int compar_areas_desc(const void *pt1, const void *pt2){
    return compar_areas(pt2, pt1);
}
int compar_names(const void *pt1, const void *pt2){
    char ** word_1 = (char**)pt1; //A string is a pointer to a char, so the pointers you're given are pointers to pointers.
    char ** word_2 = (char**)pt2;
    return strcmp(*word_1,*word_2); //We need to use the * operator to find the actual strings. 
}
int compar_names_desc(const void *pt1, const void *pt2){
    return strcmp(pt1, pt2);
}
