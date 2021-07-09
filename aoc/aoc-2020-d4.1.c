//Sun May 23 07:25:00 UTC 2021
//Wed Jul  7 11:49:51 UTC 2021
// Linux VERSION 
// find a valid passport from the input in d4-in.txt
// valid passport = a) a passport that has 7 expected fields and on missing field of cid
//                  b) a passport that has 8 expected fields
//Output the number of valid passports in the inputd file.
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
int processPassport(char *[], int, int, int);

const char * passport[] = { "byr" , "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};  

int main(){
    struct metaPassport *pmPassport = (struct metaPassport *) malloc (sizeof (struct metaPassport));
    pmPassport->longestLine = 0; 
    pmPassport->lineCounter = 0;
    pmPassport->blankLine = 0;
    int numOfGoodPassports = 0;  
    int arrSize = 0; 
    int result = 0;
//counLines function call: 
//Count the number of lines in the input file;
//Count the number of passport in the input file;
//Find the longest line in the file - used as input to malloc
//    countLines("/home/admin/Programming/c_sources/aoc/d4-test-in.txt", pmPassport );
    countLines("/home/admin/Programming/c_sources/aoc/d4-in.txt", pmPassport );
//    printf("%i\n", arrSize = countLines("C:\\Users\\slaan\\source\\c_sources\\aoc\\d4-test-in.txt"));
    const int LINE_LENGTH = pmPassport->longestLine;
    const int LINE_COUNT = pmPassport->lineCounter;
    const int PASSPORT_COUNT = pmPassport->blankLine;
    char *lnArr[LINE_COUNT];
    printf("\nLine count: %i\nLongest Line: %i\nNumber of passports: %d\n",\
           pmPassport->lineCounter,  pmPassport->longestLine, pmPassport->blankLine);
//    loadPassports("/home/admin/Programming/c_sources/aoc/d4-test-in.txt", LINE_LENGTH,\
                  PASSPORT_COUNT, LINE_COUNT, lnArr);
    loadPassports("/home/admin/Programming/c_sources/aoc/d4-in.txt", LINE_LENGTH,\
                  PASSPORT_COUNT, LINE_COUNT, lnArr);
//    free(lnArr);
//    numOfGoodPassports = countGoodPassport("/home/admin/Programming/c_sources/aoc/d4-test-in.txt",\
        LINE_LENGTH,PASSPORT_COUNT, LINE_COUNT, lnArr);
    numOfGoodPassports = countGoodPassport("/home/admin/Programming/c_sources/aoc/d4-in.txt",\
            LINE_LENGTH, PASSPORT_COUNT, LINE_COUNT, lnArr);
//    free(lnArr);
    printf("Number of Good Passports: %i\n", numOfGoodPassports);

}

//loadPassports is used to print out the length of each line using malloc and getline. It overlaps 
//with the countLines function 
int loadPassports(char in_data[], int lineLength, int numPasspts,int lnCount, char *linePTR[] ){
    FILE *fps; 
    int  numLines = 0;
    ssize_t lnLen = 0;
    char *line;
    char *curLine;
    size_t bufsize = lineLength;
    printf("bufsize is: %li \n", bufsize);
    fps = fopen(in_data, "r");
    if(fps == NULL){
        printf("error opening the file %s\n", in_data);
        exit(1);
    }
//create a buffer to hold  a single passport file line. "line is then fed into getline" 
//getline returns a lnLen of characters in the line, it also returns a pointer to the beginning 
//of captured line. 
//    line = (char *) malloc(lineLength * sizeof(char));
    line = (char *) malloc(bufsize* sizeof(char));
    while ((lnLen = getline(&line, &bufsize, fps)) > 0){
//        printf("\nlnLen = %i\n", lnLen);
        if ( numLines >= lnCount || ((curLine = (char *)  malloc (bufsize * sizeof (char))) == NULL)){
//        if ( numLines >= lnCount || ((curLine = (char *)  malloc (lnLen )) == NULL)){
            printf("\n****Error, exiting****\n");
//            fclose(fps);
            free(line);
            return -1;
        }
        else {
            //line[lnLen - 1] = '\0'; //remove the blank line
            //line[lnLen] = '\0';
            strcpy(curLine, line);
            linePTR[numLines++] = curLine;
        }
        printf("lnLen = %i\n", lnLen);
//        free(line);
    }
//%20[^\n]
    fclose(fps);
    free(line);
    return numLines;
}

int countGoodPassport(char in_data[], int lineLength, int numPasspts,int lnCount, char *linePTR[] ){
    FILE *fps; 
    int  numLines = 0;
    ssize_t lnLen;
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
//create an array to hold the passport record - malloc requires buffer (lnLen that will 
    line = (char *) malloc(lineLength * sizeof(char));
    while ((lnLen = getline(&line, &bufsize, fps)) > 0){
        printf("\nlnLen = %i\n", lnLen);
//dynamically create space (curLine) for each getline call - using malloc) and create a pointer to it (curLine)
        if ( numLines >= lnCount || ((curLine = (char *)  malloc (bufsize* sizeof (char))) == NULL)){
//        if ( numLines >= lnCount || ((curLine = (char *)  malloc (lnLen )) == NULL)){
            printf("\n****Finished processing, exiting****\n");
            free(line);
//            fclose(fps);
            return addGoodPassport; 
        }
        else {
            //line[lnLen - 1] = '\0'; //remove the blank line
            //line[lnLen] = '\0';
//
            strcpy(curLine, line);

            if (isspace(linePTR[numLines][0])){
//            if (isspace(linePTR[numLines][0])){
//check for the passport validity: each passport field (i.e. expiry yr, pid, etc)
//has a weight of "1" so we need 7 or more fields to have a valid passport.To accomodate for problem req
//we can have either 7 + 0 (from cid = 0) or 8 (all passport fields are present) 
//We also reset all field counters
                if (((numFieldsInPass >= 7) && (cid == 0)) || numFieldsInPass == 8 ){
                    printf("Good Passports = %i\n", ++addGoodPassport);
                }
                numFieldsInPass = byr = iyr = eyr = hgt = hcl = ecl = pid = cid = 0;
            }
 
            else {
                for (i = 0; i < 8; i++){
                    if (strstr(linePTR[numLines], passport[i])){
                        printf("Found: %s\n", passport[i]);
//for each field add "1" if present
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
                    }
                    printf("Total number of fields in a given passport record = %i\n", numFieldsInPass = byr +\
                            iyr + eyr + hgt + hcl + ecl + pid + cid);
                    
                }
            }
            linePTR[numLines++] = curLine;
//            free(line);
        }
    fclose(fps);
    free(line);
    return addGoodPassport;
    }

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
//                sPassport->longestLine = ++n;
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
