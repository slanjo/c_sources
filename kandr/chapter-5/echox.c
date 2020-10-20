#include <stdio.h>
//echo CLI input back to CLI

int main(int argc, char *argv[])
{
    int i = argc;
/* Array option
    for (i = 1; i < argc; i++){
        printf("%s%s", argv[i], (i < argc - 1) ? " " : " ");
        printf("\n");
    }
*/
//Pointer option:
/*    while ( --i> 0 )
    {
        printf("\naddress of ARGV:            %p\n", argv);
        printf("value of second argument:   %s\n", *++argv );
        printf("address of third argument:  %p\n", argv);
        printf("************LOOP END*************");
    }
    printf("\n#####################NEW TEST##################");
    i = argc;
    */
    while ( --i> 0 )
    {
//        printf("\nADDRESS OF argv: %p\n%s%s\nADDRESS of ++argv %p\n", argv, *++argv, (i > 1) ? " " : " ", argv);
        printf("%s%s\n", *++argv, (i > 1) ? " " : " ");
        printf("%p is address of argv\n%p is address of **argv\n", argv, &(**argv));
//        printf("%c\n", **++argv);
   }
    printf("\n");
    return 0;
}
