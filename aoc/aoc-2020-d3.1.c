//Wed Jun  2 12:33:35 UTC 2021
//Starting at the top-left corner of d3.txt follow the slope of "right 3" and
//"down 1". Output the number of trees we encounter. (tree = #, O = open square)
//If we flatten the input file into a single dimension arrah, the above move can also be viewed as 
//new position+=input line length + lateral move amount
//So, to solve this puzzle we assumed that a "pattern reapeats to the right many times" 
//can be simulated by rewinding our position to a calculated offset near the beinning 
//of the current line. We then continue our regular count of "np = np + 31 + rs"
//
//

enum rew { zero=0, rew7=7, rew8=8, rew9 = 9, rew10 = 10, rew31 = 31};
#include <stdio.h>
#include <string.h>
int count_chr(char[]);
char *create_array(char[], int, char[]);//convert the input file into an array
int main(){
    int k=1, tree_count=0, rs=3, r3d1 = 34,  i = 0, cp_offset = 0;
    int CHARS = 0;
    char file_name[] = "/home/admin/Programming/c_sources/aoc/d3-in.txt";
    printf("# of characters in the input file: %i\n", CHARS = count_chr(file_name));
    char letter[CHARS]; //allocate memoryfor array to store input file to 
    char *char_in = create_array(letter, CHARS, file_name);//return a pointer to char array with CHARS number of elements. 
    char *cp = char_in;//pointer to the first char in the string array
    char *np = char_in;//"next position to be checked for a tree 
    char *lb = cp;//left border - first character in any one row
    char *rb = cp + 31;//right border - last character in any one row
    char *check_end = lb;//stop loop
//    printf("%s\n", char_in);
    printf("Number of characters in one line %i\n", rew31);
 //   printf("1st cp=%c 2nd cp=%c 3rd cp=%c 4th cp=%c LAST=%c\n\n", *(cp), *(cp+1), *(cp+2), *(cp+3), *(cp+(121)));
    lb = lb + 31;
    rb = lb + 30;
    np = cp + 31 + rs;
    while (*check_end != '\0'){
        //check if we have ran into a tree
            if ((*np) == '#'){
                tree_count++;
            }
//        printf("\n\nINSIDE WHILE %i TIME  lb= %c rb= %c cp= %c np= %c \n", k, *(lb), *(rb), *(cp), *(np));
            //check if we can lateraly move THREE units without crossing the right boundary in which case\
            //we'd have to rewind back by using cp_offset and np = lb + 2 - cp_offset + 31
        if ((rb - np) < 3){
//            printf("RWD CONDITION MET    lb= %c rb= %c cp= %c np= %c \n", *(lb), *(rb), *(cp), *(np));
            //
            cp_offset = rb - np;
            np = lb + 2 - cp_offset + 31;//rewinde back so we can continue counting
            rb+=31;
            lb+=31;
//            printf("AFTER RWND OPERATION lb= %c rb= %c cp= %c np= %c \n", *(lb), *(rb), *(cp), *(np));
        }
        else {
//            printf("NORMAL CONDITION MET lb= %c rb= %c cp= %c np= %c \n", *(lb), *(rb), *(cp), *(np));
            lb+=31;
            rb+=31;
            np = np + 31 + rs;
//            printf("NORMAL CONDITION NP  lb= %c rb= %c cp= %c np= %c \n", *(lb), *(rb), *(cp), *(np));
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
//populate the array from an input file "fp"
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
