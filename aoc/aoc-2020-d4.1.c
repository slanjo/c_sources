//test
//Sun May 23 07:25:00 UTC 2021
//Find the three entries into expens report that sum to 
//2020 and then multiply the three numbers together
//input format: 16-17 w: wwwhwwwwwwwwwwwwq
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define YEAR 2020
int countPassports(char[]);

bool TestForBlankLine(const char * ); 
typedef struct metaPassport{ 
    int lineCounter; //how many lines in a file
    int longestLine; //how many characters in the longest line
    int blankLine;   //how many blank lines in the file
}mPassport; 

void loadPassports(char *, int, int, int);
void countLines(char[], struct metaPassport*);

typedef struct passport {
    char byr;
    char iyr;
    char eyr;
    char hgt;
    char hcl;
    char ecl;
    char pid;
    char cid[];  
}passRcrd; 

int main(){
    struct metaPassport *pmPassport = (struct metaPassport *) malloc (sizeof (struct metaPassport));
    pmPassport->longestLine = 0; 
    pmPassport->lineCounter = 0;
    int arrSize = 0; 
    int result = 0;
    countLines("/home/admin/Programming/c_sources/aoc/d4-test-in.txt", pmPassport );
//    countLines("/home/admin/Programming/c_sources/aoc/d4-in.txt", pmPassport );
//    printf("%i\n", arrSize = countLines("C:\\Users\\slaan\\source\\c_sources\\aoc\\d4-test-in.txt"));
    const int LINE_LENGTH = pmPassport->longestLine;
    const int LINE_COUNT = pmPassport->lineCounter;
    const int PASSPORT_COUNT = pmPassport->blankLine;
    printf("\nLine count: %i\nLongest Line: %i\nNumber of passports: %d\n",\
           pmPassport->lineCounter,  pmPassport->longestLine, pmPassport->blankLine);
    loadPassports("/home/admin/Programming/c_sources/aoc/d4-test-in.txt", LINE_LENGTH,\
                  PASSPORT_COUNT, LINE_COUNT);
}

bool TestForBlankLine(const char * line) {
//blank line is the "passport separator" - counting blank lines will tell us
//how many passports we have. 
    int i;
    for (i = 0; line[i] != '\0'; i++){
        if (!isspace(line[i]))
                return false;
        return true;
        }
}

void loadPassports(char in_data[], int lineLength, int numPasspts,int lnCount){
    FILE *fps; 
    int  numLines = 0;
    size_t lnLen;
    char *line;
    char *curLine;
    char *lnArr[lnCount];
    size_t bufsize = lineLength;
//    char line[lineLength]; 
    fps = fopen(in_data, "r");
    if(fps == NULL){
        printf("error opening the file %s\n", in_data);
        exit(1);
    }
//create an array to hold the passport record 
    line = (char *) malloc(lineLength * sizeof(char));
    while ((lnLen = getline(&line, &bufsize, fps)) > 0){
       if ( numLines >= lnCount || ((curLine = (char *)  malloc (lnLen * sizeof (char))) == NULL)){
            printf("Error, exiting\n");
            return -1;
        }
        else {
            line[lnLen - 1] = '\0';
            strcpy(curLine, line);
            lnArr[numLines++] = curLine;
        }
        printf("\nlnLen = %i\n", lnLen);
 
    }
    printf("\n lnArr %s\n", lnArr[8]);
//    printf("******** %s **********\n", line); 
//    printf("******* %s **********\n", lnArr);
//%20[^\n]
    fclose(fps);
//    free(line);
}

//ssize_t getline (char **lineptr, size_t *n, FILE *stream);
/* countLines:
  -Count lines in the file - not sure why
  -calculate the longest line length to be able to use it to dynamically create
   a string array for the given line.
  -calculate the total number of passports in the file - used in the loop
*/ 

void countLines(char s[], struct metaPassport *sPassport){ 
    FILE *fps; 
    int c = 0; 
    int n = 0;
    fps = fopen(s, "r");
    if(fps == NULL){
        printf("error opening the file %s\n", s);
        exit(1);
    }
    while ((c = (fgetc(fps))) != EOF){
        if (c == '\n'){
            ++(sPassport->lineCounter);
            if ( n > sPassport->longestLine)
                sPassport->longestLine = n++;
            n = 0;
        }
        else 
            n++;
    }
    fseek ( fps, 0, SEEK_SET); //  set the file pointer "fps" to the beginning of the file:\
                                 OR rewind back to the begining of the file
    char pLine[sPassport->longestLine];
    printf("\n******\n");
    sPassport->blankLine++;
    while (fgets( pLine, sPassport->longestLine, fps) != NULL){
        printf("%s", pLine);
        if isspace(pLine[0])
            ++(sPassport->blankLine);
    }
    printf("\n******\n");
    fclose(fps);
}
