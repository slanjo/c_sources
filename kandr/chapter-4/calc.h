//Wed 19 Aug 2020 05:09:00 AM AWST
#define NUMBER '0'  // signal that a nubmer was found
//#define NEG_NUMS 'N' 
#define MAXOP 100
#define DUP 'd'
#define PRN 'p'
#define CLR 'c'
#define SWP 's'
#define SINX '$'
#define POW '^'
#define EXP '@'
extern char variablehandling[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', \
   'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; 
double clr(void);
double swp(void);
double prn(void);
double dpl(void);
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
