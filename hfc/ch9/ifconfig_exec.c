//This program tries to run ifconfig, and if it fails it then tries to run
//ifconfig, and if it fails, then it returns an error
#include <stdio.h>
#include <errno.h>//errno variable 
#include <string.h>//need for strerror dislplay of errors
#include <unistd.h>//exec() functions

int main(){
    if (execl("/sbin/ifconfig","/sbin/ifconfig",NULL) == -1 ){
            if (execlp("ifconfig","ifconfig",NULL) == -1){
                fprintf(stderr, "Cannot run ipconfig: %s", strerror(errno));
                return 1;
                }} 
        return 0;
}
