//Thu Jun 10 14:11:14 UTC 2021
//This program expands on the 2020 D3 Part 1 AoC puzzle. 
//Starting at the top-left corner of d3-in.txt follow the slope of "right 3" and
//"down 1". Output the number of trees we encounter. (tree = #, O = open square)
//If we flatten the input file into a single dimension arrah, the above move can also be viewed as 
//new position+=input line length + lateral move amount (or np = np + 31 + rs)
//So, to solve this puzzle we assumed that a "pattern reapeats to the right many times" 
//can be simulated by rewinding our position to a calculated offset near the beinning 
//of the current line. We then continue our regular count of "np = np + 31 + rs"
//
///

#include <stdio.h>
#include <string.h>
int count_chr(char[]);
int run_slope(char *, char *, char *, char *, char *, int, int, int); 
char *create_array(char[], int, char[]);//convert the input file into an array
int main(){
    int k=1, tree_count=0, rs=3, i = 0, j = 0, cp_offset = 0;//rs = right step - how many cells we move to the right .0
    int CHARS = 0;
    char file_name[] = "/home/admin/Programming/c_sources/aoc/d3-in.txt";
//    char file_name[] = "/home/admin/Programming/c_sources/aoc/test.txt";
    printf("# of characters in the input file: %i\n", CHARS = count_chr(file_name));
    char letter[CHARS]; //allocate memoryfor array to store input file to 
    char *char_in = create_array(letter, CHARS, file_name);//return a pointer to char array with CHARS number of elements. 
    char *cp = char_in;//pointer to the first char in the string array
    char *np = char_in;//"next position to be checked for a tree 
    char *lb = cp;//left border - first character in any one row
    char *rb = cp + 31;//right border - last character in any one row
    char *check_end = lb;//stop loop
    int two_line = 1; //moving = right 1 down 2
    int solution[5];
    int RS[] = {1, 3, 5, 7, 1}; 
    for  (j = 0; j < 4; j++){
        solution[j] = run_slope(lb, rb, np, check_end, cp, RS[j], cp_offset, two_line);
        printf("RS = %i: \n", RS[j]);
    }
    two_line = 2;
    solution[4] = run_slope(lb, rb, np, check_end, cp, RS[j], cp_offset, two_line);

    printf("The correct answer is: %li\n", solution[0] * solution[1] * solution[2] * solution[3] * solution[4]); 
}

int run_slope(char *lb, char *rb, char *np,  char *check_end, char *cp,  int rs, int cp_offset, int two_line ) {
    int k = 0;
    lb = lb + 31 * two_line;
    if (two_line == 2){
        rb = lb + 61;
        np = lb + rs;
    }
    else {
        rb = lb + 30 * two_line;
        np = cp + 31 * two_line + rs;
    }
    int tree_count = 0;
    while (*check_end != '\0'){
        //check if we have ran into a tree
            if ((*np) == '#'){
                tree_count++;
            }
            //check if we can lateraly move THREE units without crossing the right boundary in which case\
            //we'd have to rewind back by using cp_offset and np = lb + 2 - cp_offset + 31
        if ((rb - np) < rs){
            cp_offset = rb - np;
            if (two_line == 2){
//                printf("cp_offset = %i\n", cp_offset);
                np = lb - cp_offset + 31;//rewind back a bit so we can continue counting simulation 
                lb+=62;
                rb = lb + 30;
            }
            else {
            np = lb + rs - 1 - cp_offset + 31 * two_line;//rewind back a bit so we can continue counting simulation 
            rb+=(31*two_line);
            lb+=(31*two_line);
            }
        }
        else {
            lb+=(31*two_line);
            rb+=(31*two_line);
            np = np + 31*two_line + rs;
            }
        check_end = lb;
//        printf("%c", *lb);
        cp = np;
       k++; 
       }
    printf("Number of trees on the slope with RS =%i: %i\n---------\n", rs, tree_count);
    return tree_count;
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
