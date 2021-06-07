//Wed Jun  2 12:33:35 UTC 2021
//Starting at the top-left corner of d3.txt follow the slope of "right 3" and
//"down 1". Output the number of trees we encounter. (tree = #, O = open square)
//
//
//

enum rew { zero=0, rew7=7, rew8=8, rew9 = 9, rew10 = 10, rew11 = 11};
#include <stdio.h>
#include <string.h>
int count_chr(char[]);
char *create_array(char[], int, char[]);
int main(){
    int k=1, tree_count=0, rs=3, r3d1 = 13,  i = 0, cp_offset = 0;
    int CHARS = 0;
    char file_name[] = "/home/admin/Programming/c_sources/aoc/test.txt";
 //   char *char_in; //pointer to string that contains the whole input file 
    printf("# of characters in the input file: %i\n", CHARS = count_chr(file_name));
    char letter[CHARS];
    char *char_in = create_array(letter, CHARS, file_name);
    char *cp = char_in;
    char *np = char_in; 
    char *lb = cp;
    char *rb = cp + 11;
    char *check_end = lb;
    printf("%s\n", char_in);
    printf("Number of characters in one line %i\n", rew11);
    printf("1st cp=%c 2nd cp=%c 3rd cp=%c 4th cp=%c LAST=%c\n\n", *(cp), *(cp+1), *(cp+2), *(cp+3), *(cp+(121)));
    lb = lb + 11;
    rb = lb + 10;
    np = cp + 11 + rs;
    while (*check_end != '\0'){
            if ((*np) == '#'){
                tree_count++;
            }
 
        printf("\n\nINSIDE WHILE %i TIME  lb= %c rb= %c cp= %c np= %c \n", k, *(lb), *(rb), *(cp), *(np));
        if ((rb - np) < 3){
            printf("RWD CONDITION MET    lb= %c rb= %c cp= %c np= %c \n", *(lb), *(rb), *(cp), *(np));
//            if ((*np) == '#'){
//                tree_count++;
//            }
            cp_offset = rb - np;
            np = lb + 2 - cp_offset + 11;
//            np = np + 11;
            rb+=11;
            lb+=11;
 //           if ((*np) == '#'){
 //               tree_count++;
 //           }
            printf("AFTER RWND OPERATION lb= %c rb= %c cp= %c np= %c \n", *(lb), *(rb), *(cp), *(np));
        }
        else {
            printf("NORMAL CONDITION MET lb= %c rb= %c cp= %c np= %c \n", *(lb), *(rb), *(cp), *(np));
//            if ((*np) == '#'){
//                tree_count++;
//            }
            lb+=11;
            rb+=11;
            np = np + 11 + rs;
            printf("NORMAL CONDITION NP  lb= %c rb= %c cp= %c np= %c \n", *(lb), *(rb), *(cp), *(np));
            }
        check_end = lb;
        cp = np;
       k++; 
       }
    printf("\nNumber of characters in the file: %i\n", CHARS);
    printf("Number of trees on the slope: %i\n---------\n", tree_count);
}
int count_chr(char sp[]){
//---Count the number of characters in the input files to determine the size of the array
    FILE *fps;
    int c=0,n=0, i=0;
    fps = fopen(sp, "r");
    if(fps == NULL){
         printf("error opening the file %s\n", sp);
         return 0;
    }
    while ((c = (fgetc(fps))) != EOF){
        (c == '\n')? :++n; 
    }
    fclose(fps);
    return n;
}
char *create_array(char s[], int x, char fp[]){
    FILE *fps;
    fps = fopen(fp, "r");
     if(fps == NULL){
         printf("error opening the file %s\n", s);
    }
    char c;
    int i, k = 0;
    for (i = 0; i < x; i++){ 
        ((c = fgetc(fps)) == '\n') ? i-- : (s[i] = c);
    }
    s[i] = '\0';
    fclose(fps);
    return s;
}
