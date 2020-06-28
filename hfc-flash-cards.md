### HFC Reading Notes

_____  
-----   
### *create a string*   
-----    
```
    char s[] = "Some string here";
```
_____  
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
_____  
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
_____  

-----    
### *union*  
  *  ** **  
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
_____  
-----    
### *create a pointer array*   
  * ** **  
```
    char *array[] = {"array", "of", "pointers"};  
```
_____  
-----    
### *CLI parsing*   
  * ** **  
```
int main(argc, *argv[]);  
```
_____  
-----    
### *c***    
-----    
  * ** **  
```
```
_____  
-----    
### *funciton pointer*   
-----    
  * ** **  
  * to declare a funciton pointer we use: 'ReturnType (*func_name)(param_types)';.  
   
```
ReturnTYpe (*func_name)(param types);
  char**   (*name_fn)    (char*, int);
void find(int(match)(char**,int){
    };
```  
If fp is a function pointer, we can call it with:
fp(params...) or we can use (*fp)(params). C works the same with both.  

_____  
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
_____  
-----    
### *Data types in C*   
-----    
  * ** **  
  * char - stores character codes for characters (A==65)
  * short - up to a few hundred; 1/2 size of int
  * int - guaranteed to be 16 bits, up to a few million  
  * long - used to be double the size of ints, nowadays usually same or more. Guaranteed size of 32 
  * float - regular daily usage decimals
  * double - double memory size used as for float 
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  
-----    
### **   
-----    
  * ** **  
```
```
_____  


[//]: # (Comments Section - needs two blank lines after this initial section
        comment line format is:
        [alias_name]: < > 
        for links we can use alias names throught the document before this section) 


[slanjo]: <https://github.com/slanjo>

[table]: <| Concept | Explanation | Syntax Sample |>
[table]: <| --- | --- | --- |>
[table]: <| some concept name |some concept definition|something else | >
[table]: < | | | |>

