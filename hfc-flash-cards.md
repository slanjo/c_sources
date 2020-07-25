### HFC Reading Notes

  
-----   
### *create a string*   
-----    
```
    char s[] = "Some string here";
```
  
-----    
### *functions for custom file data streams*   
  * **fopen()**
  * **fclose()**
  * **fprintf()**
  * **fscanf**
```
  FILE *out_file = fopen("file_name","w"); //or "r", or "a"
  fclose(my_file);
  FILE *in_file = fopen("file_name", "r");
  fprintf(stderr,"err %s", some_var);
  fscanf(some_file,"%f %s", &some_float, &some_string);  
  fscanf(some_file,"$80[^\n", &string), 
   
```
  
-----    
### *sizeof(int)*   
  *  **sizeof** - shows in bytes how much space something occupies in memory.  
  *  on 32-bit OSs sizeof(some_pointer) == 4, and on 64-bit, sizeof(some_pointer) == 8  
  *  C compiler is also smart enough to return the actual sizeof(array[]) eventhough  
     array[] is only a pointer to a memory address.   
```
    sizeof(int);
    siszeof("Turtles"); // returns 9 because of '\0'
```
  

-----    
### *union*    
  *  unions allow us to create a variable that supports multiple data types.  
  so we're basically using same memory location to save different data types (int, float, char)
  *  only one value can be stored at any point in time, and the we have to allocate  
  enough memory to allocate the largest data ttype. so between float, int, and double  
  we'd allocate 32 bits so we can fit a double in our union. 
```
    typedef union{
        short count;
        int num;
        fload decimal;
    }my_union;

```
  
-----    
### *create a pointer array*   
```
    char *array[] = {"array", "of", "pointers"};  
```
  
-----    
### *CLI parsing*   
```
int main(argc, *argv[]);  
```
  
-----    
### *c***    
  * **c** is used to point to an array of strings   
```
```
  
-----    
### *funciton pointer*   
  * to declare a funciton pointer we use: 'ReturnType (*func_name)(param_types)';.  
   
```
ReturnTYpe (*func_name)(param types);
  char**   (*name_fn)    (char*, int);
void find(int(match)(char**,int){
    };
```  
If fp is a function pointer, we can call it with:
fp(params...) or we can use (*fp)(params). C works the same with both.  

  
-----    
### *string literal*   
-----    
  * ** ** 
  A variable that points to a string literal cannot be used to modify the contents of a string literal.  
```
char *some_char = "some_char_literal";
```  
  instead we'd want to use an array, which copies a literal to stack. 
```
char some_char[] = "some_char_literal";
```  
To prevent code from modifying string literals we can use 'const char *' -HFC page 77   
  
-----    
### *Data types in C*   
  * ** **  
  * char - stores character codes for characters (A==65)
  * short - up to a few hundred; 1/2 size of int
  * int - guaranteed to be 16 bits, up to a few million  
  * long - used to be double the size of ints, nowadays usually same or more. Guaranteed size of 32 
  * float - regular daily usage decimals
  * double - double memory size used as for float 
```
```
  
-----    
### *declaration vs definition*   
  * declaration defines something exists and defines the nature of a function or variable but not storage is allocated   
  Definitions defines what that a variable or function exists, how it looks like, and storage is assigned to at this point.    
  
```
```
  
-----    
### *Compilation process*   
-----    
  * **Preprocessor** - all preprocessors directives are ran - includes, header files are added, etc.
  * **Compilation: Translate into Assembly** - C code is translated into assembly symbols, 
  * **Assembly** -generate the object code. Object code is generated from Assembly code symbols. This is machine code and 
  it will be done for every library file, our code, and any additional files included.
  * **Linkage** - all object files generated during assembly are linked and stiched. So, functions
  calling functions in different object code files will be stiched. Compiler will also make sure
  calls to library funcitons are correct.  

```
```
  
-----    
### **nix standard header directories*   
-----    
  * **/usr/include - normally used for operating system header files**  
  * **/usr/local/include - normally used for header files for third-party libraries** 
```
```
  
-----    
### *ar*   
-----    
  * **ar - stores a set of object files into an archive**  
```
ar -rcs libhfsecurity.a encrypt.o checksum.o
```
  
-----    
### *extern*   
-----    
  * **extern char password** - declare a variable as 'extern' and include it in your headers file to
  share it within your project  
```
```
  
-----    
### *make*   
-----    
  * **make**  
  * **gcc -c \*.c** - compiles but doesn't link sources
  * **gcc \*.o -o program_name** links the object files into final executable
```
```
  
-----    
### *nm and ldconfig*   
-----    
  * **ldconfig** it creates links and cache to the most recent shared libraries. Required by a run-time linker  
  * **nm** reads a shared object libraries symbols
```
```
  
-----    
### *malloc()*   
-----    
  * **malloc** reserves an n amount of bytes on the heap     
  * the reservation is done at runtime, and it will be held untill allocated memory is released    
  * it takes an int size of requested bytes  
  * it returns void* to the first byte of the requested memory space   
  * it is usually ran together with sizeof operator as we ordinarily wouldn't know the size of requested memory space    
  * **free()** is used to release memory, each time we've used malloc
```
int *p = malloc(sizeof(something));
```
-----    
### *assign a struct variable...*   
-----    
  * **...COPIES the data into a new variable**  
```
```
-----    
### *text stream*   
-----    
  * **text stream** is a sequence of characters divided into lines. Each line contains zero or more characters  
  followd by a new line character.   
```
```
-----    
### *getchar() and putchar()*   
-----    
  * **getchar()** reads the next character from a text stream of characters one string at a time  
  getchar returns EOF when there is no more characters to return. EOF = -1 on linux.   
  * **putchar()** prints a character eachtime it is called   
```
```
-----    
### *single quote ' '*   
-----    
  * **'\n'** a character between single quotes represents and integer value equal to the numerical value of the character in the machine's character set.  
  This is called a *character constant* - basicallly another way to write a small integer! So `'A'` is a character constant, and in ASCII char set it is  
  equal to 65.  `'\n'` is a single character (just an integer) and `"\n"` is a string constant that happens to contain only one character. 
```
```
-----    
### *check if a char is numeric*   
-----    
  * ** ** this uses ASCII/UTF8 code page characteristc  
```
if (c >= '0' && c <= '9')
    c - '0' //represents a numercial value of c
```
-----    
### *XOR Operator*   
-----    
  * **XOR ^** operator can be used to compare two values instead of an if statement  
  it will return True (1) only when both inputs differ.
```
```
-----    
### *Bitwise and Bytewise*   
-----    
  * ** **  
```
```
-----    
### *Constants*   
-----    
  * **Integer Constants/Floating point constants**    can be any of the float, long, int, double, unsigned or a combination
  1234 is an integer. An integer constant that doesn't fit into an int will be a long. We mark integer constants by terminal l (ell) or L.
  for example 123456UL is an unsigned long integer.  Floating point is an constant that contains a decimal point or  
  an exponent (le-2). f or F indicates the float and l or L marks a long double floating point constant.  
  * **Character Constants**  is an integer value equal to character's numerical value in machine's character set. 'x' is not the same as  
  "x". One is a Character constant and the other is a string constant. \0 is a sentinel and has a numerical value of dec 48.  
  * **String Constants or String Literals**  is a sequence of zero or more character constants. It is basically an array of character   
  constants. 
  * **Constant Expression**  an expression that involves only constants.  Can be evaluated during compilation rather than during the run time.  
  Enums are sometimes better than *defines* as they can generate values for us.
  ```
\#define SOME_CONST 1;
  ```
  * **Enumeration constant (Enums)**  is a list of integer constants 
```
enum my_enum {ONE, TWO, THREE}; //these will be ONE = 1, TWO = 2, THREE = 3
enum escapes {TAB ='\t', NEWLINE = '\n', BELL = '\a'};
```
-----    
### *Automatic vs. Extern*   
-----    
  * **Automatic variables** appear in a function and are available as long as the function is being run. They're removed from memory   
  after the execution.    
  * **Extern variables** are defined in a const part of memory and are avaible through out program run. They're visible to all functions   
  in the file and can be shared via .h files among different program files.  
```
```
-----    
### *bitwise vs. bytewise*   
-----    
  * ** **  
```
&&, ||, !
&, |, ~
```
-----    
### *~(~0 << n)*   
-----    
  * **~(~0 << n)** ~0 is all ones. Shifting ~0 by "n" to left sets "n"-far-right bits to 0  
  then we complement (~) which creates a mask with all 1s at far right bits.  
```
```
-----    
### **   
-----    
  * ** **  
```
```
-----    
### **   
-----    
  * ** **  
```
```
-----    
### **   
-----    
  * ** **  
```
```
-----    
### **   
-----    
  * ** **  
```
```



[//]: # (Comments Section - needs two blank lines after this initial section
        comment line format is:
        [alias_name]: < > 
        for links we can use alias names throught the document before this section) 


[slanjo]: <https://github.com/slanjo>

[table]: <| Concept | Explanation | Syntax Sample |>
[table]: <| --- | --- | --- |>
[table]: <| some concept name |some concept definition|something else | >
[table]: < | | | |>

