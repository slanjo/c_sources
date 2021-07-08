//Sun May 23 07:25:00 UTC 2021
//Wed Jul  7 11:49:51 UTC 2021
//Find the three entries into expens report that sum to 
//2020 and then multiply the three numbers together
//input format: 16-17 w: wwwhwwwwwwwwwwwwq
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
 
typedef struct metaPassport{ 
    int lineCounter; //how many lines in a file
    int longestLine; //how many characters in the longest line
    int blankLine;   //how many blank lines in the file
}mPassport; 

int countGoodPassport(char *, int, int, int, char* []);
int loadPassports(char *, int, int, int, char* []);
void countLines(char[], struct metaPassport*);
int countPassports(char[]);
int processPassport(char *[], int, int, int);

const char * passport[] = { "byr" , "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};  

int main(){
    struct metaPassport *pmPassport = (struct metaPassport *) malloc (sizeof (struct metaPassport));
    pmPassport->longestLine = 0; 
    pmPassport->lineCounter = 0;
    int arrSize = 0; 
    int result = 0;
//    countLines("/home/admin/Programming/c_sources/aoc/d4-test-in.txt", pmPassport );
   countLines("/home/admin/Programming/c_sources/aoc/d4-in.txt", pmPassport );
//    printf("%i\n", arrSize = countLines("C:\\Users\\slaan\\source\\c_sources\\aoc\\d4-test-in.txt"));
    const int LINE_LENGTH = pmPassport->longestLine;
    const int LINE_COUNT = pmPassport->lineCounter;
    const int PASSPORT_COUNT = pmPassport->blankLine;
    char *lnArr[LINE_COUNT];
    char *lnArr1[LINE_COUNT];
    printf("\nLine count: %i\nLongest Line: %i\nNumber of passports: %d\n",\
           pmPassport->lineCounter,  pmPassport->longestLine, pmPassport->blankLine);
//    loadPassports("/home/admin/Programming/c_sources/aoc/d4-test-in.txt", LINE_LENGTH,\
                  PASSPORT_COUNT, LINE_COUNT, lnArr);
    loadPassports("/home/admin/Programming/c_sources/aoc/d4-in.txt", LINE_LENGTH,\
                  PASSPORT_COUNT, LINE_COUNT, lnArr);
//    countGoodPassport("/home/admin/Programming/c_sources/aoc/d4-test-in.txt", LINE_LENGTH,\
                  PASSPORT_COUNT, LINE_COUNT, lnArr);
//    printf("Good Passports: %i\n********", countGoodPassport("/home/admin/Programming/c_sources/aoc/\
                d4-in.txt", LINE_LENGTH,\
                PASSPORT_COUNT, LINE_COUNT, lnArr));
}

int loadPassports(char in_data[], int lineLength, int numPasspts,int lnCount, char *linePTR[] ){
    FILE *fps; 
    int  numLines = 0;
    size_t lnLen = 0;
    char *line;
    char *curLine;
    size_t bufsize = lineLength;
    fps = fopen(in_data, "r");
    if(fps == NULL){
        printf("error opening the file %s\n", in_data);
        exit(1);
    }
//create an array to hold the passport record 
//    line = (char *) malloc(lineLength * sizeof(char));
    line = (char *) malloc(bufsize* sizeof(char));
    while ((lnLen = getline(&line, &bufsize, fps)) > 0){
        printf("\nlnLen = %i\n", lnLen);
        if ( numLines >= lnCount || ((curLine = (char *)  malloc (lnLen * sizeof (char))) == NULL)){
//        if ( numLines >= lnCount || ((curLine = (char *)  malloc (lnLen )) == NULL)){
            printf("\n****Error, exiting****\n");
            return -1;
        }
        else {
            //line[lnLen - 1] = '\0'; //remove the blank line
            //line[lnLen] = '\0';
            strcpy(curLine, line);
            linePTR[numLines++] = curLine;
        }
        printf("\nlnLen = %i\n", lnLen);
 
    }
//%20[^\n]
    fclose(fps);
    return numLines;
//    free(line);
}

int countGoodPassport(char in_data[], int lineLength, int numPasspts,int lnCount, char *linePTR[] ){
    FILE *fps; 
    int  numLines = 0;
    size_t lnLen;
    int addGoodPassport, numFieldsInPass, byr , iyr, eyr, hgt, hcl, ecl, pid, cid;
    numFieldsInPass = addGoodPassport = byr = iyr = eyr = hgt = hcl = ecl = pid = cid = 0;
    int i, j, k = 0;
    char *line;
    char *curLine;
    size_t bufsize = lineLength;
    fps = fopen(in_data, "r");
    if(fps == NULL){
        printf("error opening the file %s\n", in_data);
        exit(1);
    }
//create an array to hold the passport record 
    line = (char *) malloc(lineLength * sizeof(char));
    while ((lnLen = getline(&line, &bufsize, fps)) > 0){
        printf("\nlnLen = %i\n", lnLen);
        if ( numLines >= lnCount || ((curLine = (char *)  malloc (lnLen * sizeof (char))) == NULL)){
//        if ( numLines >= lnCount || ((curLine = (char *)  malloc (lnLen )) == NULL)){
            printf("\n****Finished processin, exiting****\n");
            return -1;
        }
        else {
            //line[lnLen - 1] = '\0'; //remove the blank line
            //line[lnLen] = '\0';
            strcpy(curLine, line);
            if (isspace(linePTR[numLines][0])){
                //RESET ALL FIELD COUNTERS
                if (((numFieldsInPass >= 7) && (cid == 0)) || numFieldsInPass == 8 ){
                    printf("Good Passports = %i\n", ++addGoodPassport);
                }
                numFieldsInPass = byr = iyr = eyr = hgt = hcl = ecl = pid = cid = 0;
            }
            else { 
                for (i = 0; i < 8; i++){
                    if (strstr(linePTR[numLines], passport[i])){
                        printf("Found: %s\n", passport[i]);
                        if (passport[i] == "byr"){
                           byr++; 
                        }
                        else if (passport[i] =="iyr")
                            iyr++;
                        else if (passport[i] =="eyr")
                            eyr++;
                        else if (passport[i] =="hgt")
                            hgt++;                      
                        else if (passport[i] =="hcl")
                            hcl++;
                        else if (passport[i] =="ecl")
                            ecl++;
                        else if (passport[i] =="pid")
                            pid++;
                        else if (passport[i] =="cid")
                            cid++;
                        else
                            ;
                        }
                        //ADD ALL PASSPORT ITEM
                    }
                    printf("Total number of fields in the passport = %i\n", numFieldsInPass = byr +\
                            iyr + eyr + hgt + hcl + ecl + pid + cid);
                    
                }
            }
            linePTR[numLines++] = curLine;
        }
    }
//    printf(" countGoodPassports = %i\n", countGoodPassports);
/*
    for (i = 0; line[i] != '\0'; i++){
        if (!isspace((line[i])))
                return false;
        return true;
        }
*/



//ssize_t getline (char **lineptr, size_t *n, FILE *stream);
/* countLines:
  -Count lines in the file - not sure why
  -calculate the longest line length to be able to use it to dynamically create
   a string array for the given line.
  -calculate the total number of passports in the file - used in the loop
  blank line is the "passport separator" - counting blank lines will tell us
  how many passports we have. 
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
                                 rewind back to the begining of the file
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
