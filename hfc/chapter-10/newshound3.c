//This program takes the output from the rssgossip.py
//and pipes it to a webbrowser which opens the URL
//Basically this code
//connects the parent and child processes to a pipe
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
void open_url(char *url){
    char launch[255];
    sprintf(launch, "x-www-browser '%s' &", url);
    system(launch);
    sprintf(launch, "cmd /c start %s", url);
    system(launch);
    sprintf(launch, "open '%s'", url);
    system(launch);
}
void error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}


int main(int argc, char *argv[]){
    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://rss.cnn.com/rss/edition_entertainment.rss"
        , NULL};
//create the pipe:
    int fd[2];
    if (pipe(fd) == -1){
        error("Cannot create the pipe");
    }
//FILE is not needed as we're using a pipe to connect from output
//from rssgossip.py to be opened in a webbrowser. 
//FILE *f = fopen("stories.txt", "w");
//    if (!f) {
//        error("Can't open stories.txt");
//    }
//fork:
    pid_t pid = fork();
    if (pid == -1) {
        error("Can't fork process");
    }

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//check that we're at child and create a pipe. 
//If fork() returned a 0, the code is
//  running in the child process. 

    if (!pid) {//this is the same as if (pid == 0)
//        if ( dup2((fd[1]), 1) == -1 ) {
//            error("Can't redirect child's Standard Output\n");
//        }
        dup2(fd[1], 1);
        close(fd[0]);
        if (execle("/usr/bin/python3", "/usr/bin/python3", "./rssgossip.py",
                    "-u", phrase, NULL, vars) == -1) {
            error("Can't run script");
        }
    }
    dup2(fd[0], 0);
    close(fd[1]);
    char line[255];
    while (fgets(line,255, stdin)) {
        if (line[0] == '\t')
            open_url(line + 1);
    }
    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1) {
        error("Error waiting for child process");
    }
    if (WEXITSTATUS(pid_status))
        puts("Error status non-zero");
return 0;
}
