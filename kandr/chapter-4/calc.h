//Wed 19 Aug 2020 05:09:00 AM AWST
#define NUMBER '0'  // signal that a nubmer was found
#define NEG_NUMS 'N' // 4-3 provisions for negative numbers
#define MAXOP 100
#define DUP 'D'
#define PRN 'P'
#define CLR 'C'
#define SWP 'S'
#define SINX '$'
#define POW '^'
#define EXP '@'
double clr(void);
double swp(void);
double prn(void);
double dpl(void);
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
